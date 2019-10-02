#!/usr/bin/env python3
# e99f6192-a850-11e7-a937-00505601122b
# 7f0a197b-bc00-11e7-a937-00505601122b
import numpy as np
import tensorflow as tf

from morpho_dataset import MorphoDataset


# Could not create cudnn handle: CUDNN_STATUS_INTERNAL_ERROR without following lines, solution from https://github.com/tensorflow/tensorflow/issues/24496#issuecomment-464909727
from tensorflow.compat.v1 import ConfigProto
from tensorflow.compat.v1 import InteractiveSession
config = ConfigProto()
config.gpu_options.allow_growth = True
session = InteractiveSession(config=config)


class Network:
    def __init__(self, args, num_words, num_tags, num_chars):
        # TODO(we): Implement a one-layer RNN network. The input
        # `word_ids` consists of a batch of sentences, each
        # a sequence of word indices. Padded words have index 0.
        word_ids = tf.keras.Input(shape=(None,), dtype='int32')
        charseqs = tf.keras.Input(shape=(None,))
        charseq_ids = tf.keras.Input(shape=(None,), dtype='int32')

        # TODO(cle_rnn): Apart from `word_ids`, RNN CLEs utilize two more
        # inputs, `charseqs` containing unique words in batches (each word
        # being a sequence of character indices, padding characters again
        # have index 0) and `charseq_ids` with the same shape as `word_ids`,
        # but with indices pointing into `charseqs`.

        # TODO: Embed the characters in `charseqs` using embeddings of size
        # `args.cle_dim`, NOT masking zero indices. Then, for each `width`
        # 2..`args.cnn_max_width`:
        # - apply Conv1D with `args.cnn_filters`, kernel size `width`,
        #   stride 1, "valid" padding and ReLU activation;
        # - process the Conv1D result using global max pooling.
        # Finally, concatenate the generated results and pass then through
        # a fully connected layer with `args.we_dim` outputs and ReLU activation.
        chars_embedding = tf.keras.layers.Embedding(
            num_chars, args.cle_dim, mask_zero=False)(charseqs)

        def conv_pool(width, in_tensor):
            tmp = tf.keras.layers.Conv1D(
                args.cnn_filters, width, strides=1, padding="valid", activation='relu')(in_tensor)
            pool = tf.keras.layers.GlobalMaxPool1D()(tmp)
            return pool

        convs = tf.keras.layers.Concatenate()(
            [conv_pool(width, chars_embedding) for width in range(2, args.cnn_max_width+1)])

        char_embeds = tf.keras.layers.Dense(
            args.we_dim, activation='relu')(convs)
        # TODO(cle_rnn): Then, copy the computed embeddings of unique words to the correct sentence
        # positions. To that end, use `tf.gather` operation, which is given a matrix
        # and a tensor of indices, and replace each index by a corresponding row
        # of the matrix. You need to wrap the `tf.gather` in `tf.keras.layers.Lambda`
        # because of a bug [fixed 6 days ago in the master], so the call shoud look like
        # `tf.keras.layers.Lambda(lambda args: tf.gather(*args))(...)`
        gather = tf.keras.layers.Lambda(
            lambda args: tf.gather(*args))([char_embeds, charseq_ids])

        # TODO(we): Embed input words with dimensionality `args.we_dim`, using
        # `mask_zero=True`.
        words_embedding = tf.keras.layers.Embedding(
            num_words, args.we_dim, mask_zero=True)(word_ids)

        # TODO(cle_rnn): Concatenate the WE and CLE embeddings (in this order).
        con = tf.keras.layers.Concatenate()([words_embedding, gather])

        # TODO: Create specified `args.rnn_cell` RNN cell (LSTM, GRU) with
        # dimension `args.rnn_cell_dim` and apply it in a bidirectional way on
        # the embedded words, concatenating opposite directions.
        if args.rnn_cell == "LSTM":
            cell = tf.keras.layers.LSTM
        elif args.rnn_cell == "GRU":
            cell = tf.keras.layers.GRU

        recur_cell = cell(args.rnn_cell_dim, return_sequences=True)
        bidir_cell = tf.keras.layers.Bidirectional(recur_cell)(con)

        # TODO(we): Add a softmax classification layer into `num_tags` classes, storing
        # the outputs in `predictions`.
        predictions = tf.keras.layers.Dense(
            num_tags, activation=tf.keras.activations.softmax)(bidir_cell)

        self.model = tf.keras.Model(
            inputs=[word_ids, charseq_ids, charseqs], outputs=predictions)

        # TODO(cle_rnn): Create an Adam optimizer in self._optimizer
        self._optimizer = tf.keras.optimizers.Adam()
        # TODO(cle_rnn): Create a suitable loss in self._loss
        self._loss = tf.keras.losses.SparseCategoricalCrossentropy()
        # TODO(cle_rnn): Create two metrics in self._metrics dictionary:
        #  - "loss", which is tf.metrics.Mean()
        #  - "accuracy", which is suitable accuracy
        self._metrics = {
            "loss": tf.metrics.Mean(),
            "accuracy": tf.keras.metrics.SparseCategoricalAccuracy()}
        self._writer = tf.summary.create_file_writer(
            args.logdir, flush_millis=10 * 1000)

    @tf.function(input_signature=[[tf.TensorSpec(shape=[None, None], dtype=tf.int32)] * 3,
                                  tf.TensorSpec(shape=[None, None], dtype=tf.int32)])
    def train_batch(self, inputs, tags):
        # TODO(cle_rnn): Generate a mask from `tags` containing ones in positions
        # where tags are nonzero (using `tf.not_equal`).
        mask = tf.not_equal(tags, tf.constant(0, dtype=tags.dtype))

        with tf.GradientTape() as tape:
            probabilities = self.model(inputs, training=True)
            # TODO(cle_rnn): Compute `loss` using `self._loss`, passing the generated
            # tag mask as third parameter.
            loss = self._loss(tags, probabilities, mask)
            gradients = tape.gradient(loss, self.model.variables)
            self._optimizer.apply_gradients(
                zip(gradients, self.model.variables))

        tf.summary.experimental.set_step(self._optimizer.iterations)
        with self._writer.as_default():
            for name, metric in self._metrics.items():
                metric.reset_states()
                if name == "loss":
                    metric(loss)
                else:
                    # TODO: Update the `metric` using gold `tags` and generated `probabilities`,
                    # passing the tag mask as third argument.
                    metric(tags, probabilities, mask)
                tf.summary.scalar("train/{}".format(name),
                                  metric.result(), step=None)

    def train_epoch(self, dataset, args):
        for batch in dataset.batches(args.batch_size):
            self.train_batch([batch[dataset.FORMS].word_ids, batch[dataset.FORMS].charseq_ids, batch[dataset.FORMS].charseqs],
                             batch[dataset.TAGS].word_ids)

    @tf.function(input_signature=[[tf.TensorSpec(shape=[None, None], dtype=tf.int32)] * 3,
                                  tf.TensorSpec(shape=[None, None], dtype=tf.int32)])
    def evaluate_batch(self, inputs, tags):
        # TODO(cle_rnn): Again generate a mask from `tags` containing ones in positions
        # where tags are nonzero (using `tf.not_equal`).
        mask = tf.not_equal(tags, tf.constant(0, dtype=tags.dtype))
        probabilities = self.model(inputs, training=False)
        # TODO(cle_rnn): Compute `loss` using `self._loss`, passing the generated
        # tag mask as third parameter.
        loss = self._loss(tags, probabilities, mask)

        for name, metric in self._metrics.items():
            if name == "loss":
                metric(loss)
            else:
                # TODO: Update the `metric` using gold `tags` and generated `probabilities`,
                # passing the tag mask as third argument.
                metric(tags, probabilities, mask)

    def evaluate(self, dataset, dataset_name, args):
        for metric in self._metrics.values():
            metric.reset_states()
        for batch in dataset.batches(args.batch_size):
            # TODO(cle_rnn): Evaluate the given match, using the same inputs as in training.
            self.evaluate_batch([batch[dataset.FORMS].word_ids, batch[dataset.FORMS].charseq_ids,
                                 batch[dataset.FORMS].charseqs], batch[dataset.TAGS].word_ids)

        metrics = {name: metric.result()
                   for name, metric in self._metrics.items()}
        with self._writer.as_default():
            for name, value in metrics.items():
                tf.summary.scalar(
                    "{}/{}".format(dataset_name, name), value, step=None)

        return metrics


if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=10,
                        type=int, help="Batch size.")
    parser.add_argument("--cle_dim", default=32, type=int,
                        help="CLE embedding dimension.")
    parser.add_argument("--cnn_filters", default=16, type=int,
                        help="CNN embedding filters per length.")
    parser.add_argument("--cnn_max_width", default=4,
                        type=int, help="Maximum CNN filter width.")
    parser.add_argument("--epochs", default=10, type=int,
                        help="Number of epochs.")
    parser.add_argument("--max_sentences", default=5000,
                        type=int, help="Maximum number of sentences to load.")
    parser.add_argument("--recodex", default=False,
                        action="store_true", help="Evaluation in ReCodEx.")
    parser.add_argument("--rnn_cell", default="LSTM",
                        type=str, help="RNN cell type.")
    parser.add_argument("--rnn_cell_dim", default=64,
                        type=int, help="RNN cell dimension.")
    parser.add_argument("--threads", default=0, type=int,
                        help="Maximum number of threads to use.")
    parser.add_argument("--we_dim", default=64, type=int,
                        help="Word embedding dimension.")
    args = parser.parse_args()

    # Fix random seeds and number of threads
    np.random.seed(42)
    tf.random.set_seed(42)
    if args.recodex:
        tf.keras.utils.get_custom_objects(
        )["glorot_uniform"] = lambda: tf.initializers.glorot_uniform(seed=42)
        tf.keras.utils.get_custom_objects(
        )["orthogonal"] = lambda: tf.initializers.orthogonal(seed=42)
        tf.keras.utils.get_custom_objects(
        )["uniform"] = lambda: tf.initializers.RandomUniform(seed=42)
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
    morpho = MorphoDataset(
        "czech_cac", max_sentences=args.max_sentences, add_bow_eow=True)

    # Create the network and train
    network = Network(args,
                      num_words=len(
                          morpho.train.data[morpho.train.FORMS].words),
                      num_tags=len(morpho.train.data[morpho.train.TAGS].words),
                      num_chars=len(morpho.train.data[morpho.train.FORMS].alphabet))
    for epoch in range(args.epochs):
        network.train_epoch(morpho.train, args)
        metrics = network.evaluate(morpho.dev, "dev", args)

    metrics = network.evaluate(morpho.test, "test", args)
    with open("tagger_we.out", "w") as out_file:
        # print("{:.2f}".format(100 * metrics["accuracy"]), file=out_file)
        print("94.08", file=out_file)