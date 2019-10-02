#!/usr/bin/env python3
#e99f6192-a850-11e7-a937-00505601122b
#ddb5d1e7-ace9-11e7-a937-00505601122b
#7f0a197b-bc00-11e7-a937-00505601122b


import contextlib

import numpy as np
import tensorflow as tf

from timit_mfcc import TimitMFCC

# Could not create cudnn handle: CUDNN_STATUS_INTERNAL_ERROR without following lines, solution from https://github.com/tensorflow/tensorflow/issues/24496#issuecomment-464909727
from tensorflow.compat.v1 import ConfigProto
from tensorflow.compat.v1 import InteractiveSession
config = ConfigProto()
config.gpu_options.allow_growth = True
session = InteractiveSession(config=config)


class Network:
    def __init__(self, args):
        self._beam_width = args.ctc_beam
        self._gradient_threshold = args.grad
        reg = tf.keras.regularizers.L1L2(0,0.01)
        # TODO: Define a suitable model, given already masked `mfcc` with shape
        # `[None, TimitMFCC.MFCC_DIM]`. The last layer should be a Dense layer
        # without an activation and with `len(TimitMFCC.LETTERS) + 1` outputs,
        # where the `+ 1` is for the CTC blank symbol.
        #
        # Store the results in `self.model`.
        in_layer = tf.keras.Input(shape=[None, TimitMFCC.MFCC_DIM])

        mfcc = in_layer
        for num in args.lstm:
            mfcc = tf.keras.layers.Bidirectional(tf.keras.layers.LSTM(num, return_sequences=True, kernel_regularizer=reg,recurrent_regularizer=reg,bias_regularizer=reg,))(mfcc)

        out = tf.keras.layers.Dense(
            len(TimitMFCC.LETTERS)+1, activation=None)(mfcc)
        self.model = tf.keras.Model(in_layer, out)
        # The following are just defaults, do not hesitate to modify them.
        self._optimizer = tf.optimizers.Adam(0.0001)
        self._loss = None
        self._metrics = {"loss": tf.metrics.Mean(
        ), "edit_distance": tf.metrics.Mean()}
        self._writer = tf.summary.create_file_writer(
            args.logdir, flush_millis=3 * 1000)

    # Converts given tensor with `0` values for padding elements, create
    # a SparseTensor.
    def _to_sparse(self, tensor):
        tensor_indices = tf.where(tf.not_equal(tensor, 0))
        return tf.sparse.SparseTensor(tensor_indices, tf.cast(tf.gather_nd(tensor, tensor_indices), tf.int32), tf.shape(tensor, tf.int64))

    # Convert given sparse tensor to a (dense_output, sequence_lengths).
    def _to_dense(self, tensor):
        tensor = tf.sparse.to_dense(tensor, default_value=-1)
        tensor_lens = tf.reduce_sum(
            tf.cast(tf.not_equal(tensor, -1), tf.int32), axis=1)
        return tensor, tensor_lens

    # Compute logits given input mfcc, mfcc_lens and training flags.
    # Also transpose the logits to `[time_steps, batch, dimension]` shape
    # which is required by the following CTC operations.
    def _compute_logits(self, mfcc, mfcc_lens, training):
        mask = tf.expand_dims(tf.sequence_mask(
            mfcc_lens, dtype=tf.float32), -1)
        logits = self.model(mfcc, training=training)
        return tf.transpose(tf.math.multiply(logits, mask), [1, 0, 2])

    # Compute CTC loss using given logits, their lengths, and sparse targets.
    def _ctc_loss(self, logits, logits_len, sparse_targets):
        loss = tf.nn.ctc_loss(sparse_targets, logits, None,
                              logits_len, blank_index=len(TimitMFCC.LETTERS))
        self._metrics["loss"](loss)
        return tf.reduce_mean(loss)

    # Perform CTC predictions given logits and their lengths.
    def _ctc_predict(self, logits, logits_len):
        (predictions,), _ = tf.nn.ctc_beam_search_decoder(
            logits, logits_len, beam_width=self._beam_width)
        return tf.cast(predictions, tf.int32)

    # Compute edit distance given sparse predictions and sparse targets.
    def _edit_distance(self, sparse_predictions, sparse_targets):
        edit_distance = tf.edit_distance(
            sparse_predictions, sparse_targets, normalize=True)
        self._metrics["edit_distance"](edit_distance)
        return edit_distance

    @tf.function(input_signature=[tf.TensorSpec(shape=[None, None, TimitMFCC.MFCC_DIM], dtype=tf.float32),
                                  tf.TensorSpec(shape=[None], dtype=tf.int32),
                                  tf.TensorSpec(shape=[None, None], dtype=tf.int32)])
    def train_batch(self, mfcc, mfcc_lens, targets):
        with tf.GradientTape() as gt:
            logits = self._compute_logits(mfcc, mfcc_lens, True)
            loss = self._ctc_loss(logits, mfcc_lens, self._to_sparse(targets))
            grads = gt.gradient(loss, self.model.trainable_variables)
            if self._gradient_threshold:
                grads, _ = tf.clip_by_global_norm(
                    grads, self._gradient_threshold)
            self._optimizer.apply_gradients(
                zip(grads, self.model.trainable_variables))
        predicts = self._ctc_predict(logits, mfcc_lens)
        dist = tf.reduce_mean(self._edit_distance(
            predicts, self._to_sparse(targets)))
        tf.summary.experimental.set_step(self._optimizer.iterations)
        with self._writer.as_default():
            tf.summary.scalar("train/loss", loss, step=None)
            tf.summary.scalar("train/dist", dist, step=None)

    def train_epoch(self, dataset, args):
        self.reset_metrics()
        for batch in dataset.batches(args.batch_size):
            self.train_batch(
                batch["mfcc"], batch["mfcc_len"], batch["letters"])

    @tf.function(input_signature=[tf.TensorSpec(shape=[None, None, TimitMFCC.MFCC_DIM], dtype=tf.float32),
                                  tf.TensorSpec(shape=[None], dtype=tf.int32),
                                  tf.TensorSpec(shape=[None, None], dtype=tf.int32)])
    def evaluate_batch(self, mfcc, mfcc_lens, targets):
        logits = self._compute_logits(mfcc, mfcc_lens, False)
        predicts = self._ctc_predict(logits, mfcc_lens)
        self._edit_distance(predicts, self._to_sparse(targets))
        self._ctc_loss(logits, mfcc_lens, self._to_sparse(targets))

    def evaluate(self, dataset, dataset_name, args):
        self.reset_metrics()
        for batch in dataset.batches(args.batch_size):
            self.evaluate_batch(
                batch["mfcc"], batch["mfcc_len"], batch["letters"])
        with self._writer.as_default():
            tf.summary.scalar(f"{dataset_name}/loss",
                              self._metrics["loss"].result(), step=None)
            tf.summary.scalar(
                f"{dataset_name}/dist", self._metrics["edit_distance"].result(), step=None)

    @tf.function(input_signature=[tf.TensorSpec(shape=[None, None, TimitMFCC.MFCC_DIM], dtype=tf.float32),
                                  tf.TensorSpec(shape=[None], dtype=tf.int32)])
    def predict_batch(self, mfcc, mfcc_lens):
        logits = self._compute_logits(mfcc, mfcc_lens, False)
        predicts = self._ctc_predict(logits, mfcc_lens)
        return self._to_dense(predicts)

    def predict(self, dataset, args):
        sentences = []
        for batch in dataset.batches(args.batch_size):
            for prediction, prediction_len in zip(*self.predict_batch(batch["mfcc"], batch["mfcc_len"])):
                sentences.append(prediction[:prediction_len])
        return sentences

    def reset_metrics(self):
        for _, metric in self._metrics.items():
            metric.reset_states()


if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=50,
                        type=int, help="Batch size.")
    parser.add_argument("--ctc_beam", default=16, type=int, help="CTC beam.")
    parser.add_argument("--epochs", default=10, type=int,
                        help="Number of epochs.")
    parser.add_argument("--threads", default=1, type=int,
                        help="Maximum number of threads to use.")
    parser.add_argument("--lstm", default="16", type=str,
                        help="Number of units in bidir. layers")
    parser.add_argument("--grad", default=None, type=float,
                        help="Max gradient norm")
    args = parser.parse_args()
    args.lstm = [int(num) for num in args.lstm.split(",")]
    # Fix random seeds and number of threads
    np.random.seed(42)
    tf.random.set_seed(42)
    tf.config.threading.set_inter_op_parallelism_threads(args.threads)
    tf.config.threading.set_intra_op_parallelism_threads(args.threads)

    # Create logdir name
    args.logdir = os.path.join("logs", "{}-{}-{}".format(
        os.path.basename(__file__),
        datetime.datetime.now().strftime("%Y-%m-%d_%H%M%S"),
        ",".join(("{}={}".format(re.sub(
            "(.)[^_]*_?", r"\1", key), value) for key, value in sorted(vars(args).items())))
    ))

    # Load the data
    timit = TimitMFCC()

    # Create the network and train
    network = Network(args)
    for epoch in range(args.epochs):
        network.train_epoch(timit.train, args)
        network.evaluate(timit.dev, "dev", args)
        print(f"Epoch {epoch+1} done.")

    # Generate test set annotations, but to allow parallel execution, create it
    # in in args.logdir if it exists.
    out_path = "speech_recognition_test.txt"
    if os.path.isdir(args.logdir):
        out_path = os.path.join(args.logdir, out_path)
    with open(out_path, "w", encoding="utf-8") as out_file:
        for sentence in network.predict(timit.test, args):
            print(" ".join(timit.LETTERS[letters]
                           for letters in sentence), file=out_file)
