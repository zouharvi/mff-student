#!/usr/bin/env python3
# e99f6192-a850-11e7-a937-00505601122b
# 7f0a197b-bc00-11e7-a937-00505601122b
import numpy as np
import tensorflow as tf

from morpho_dataset import MorphoDataset


class Network:
    def __init__(self, args, num_words, num_tags):

        word_ids = tf.keras.Input(shape=(None,))
        embedding = tf.keras.layers.Embedding(
            num_words, args.we_dim, mask_zero=True)(word_ids)

        if args.rnn_cell == "LSTM":
            cell = tf.keras.layers.LSTM
        elif args.rnn_cell == "GRU":
            cell = tf.keras.layers.GRU

        recur_cell = cell(args.rnn_cell_dim, return_sequences=True)
        bidir_cell = tf.keras.layers.Bidirectional(recur_cell)(embedding)
        predictions = tf.keras.layers.Dense(
            num_tags, activation=tf.keras.activations.softmax)(bidir_cell)

        self.model = tf.keras.Model(inputs=word_ids, outputs=predictions)
        self.model.compile(optimizer=tf.optimizers.Adam(),
                           loss=tf.losses.SparseCategoricalCrossentropy(),
                           metrics=[tf.metrics.SparseCategoricalAccuracy(name="accuracy")])

        self._writer = tf.summary.create_file_writer(
            args.logdir, flush_millis=10 * 1000)

    def train_epoch(self, dataset, args):
        for batch in dataset.batches(args.batch_size):
            inputs = batch[dataset.FORMS].word_ids
            targets = batch[dataset.TAGS].word_ids
            targets = np.expand_dims(targets, 2)
            metrics = self.model.train_on_batch(
                inputs, targets, reset_metrics=True)
            tf.summary.experimental.set_step(self.model.optimizer.iterations)
            with self._writer.as_default():
                for name, value in zip(self.model.metrics_names, metrics):
                    tf.summary.scalar(
                        "train/{}".format(name), value, step=tf.summary.experimental.get_step())

    def evaluate(self, dataset, dataset_name, args):
        self.model.reset_metrics()
        # We assume that model metric are resetted at this point.
        for batch in dataset.batches(args.batch_size):
            inputs = batch[dataset.FORMS].word_ids
            targets = batch[dataset.TAGS].word_ids
            targets = np.expand_dims(targets, 2)
            metrics = self.model.test_on_batch(
                inputs, targets, reset_metrics=False)
        self.model.reset_metrics()

        metrics = dict(zip(self.model.metrics_names, metrics))
        with self._writer.as_default():
            for name, value in metrics.items():
                tf.summary.scalar("{}/{}".format(dataset_name, name),
                                  value, step=tf.summary.experimental.get_step())

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
    parser.add_argument("--we_dim", default=128, type=int,
                        help="Word embedding dimension.")
    args = parser.parse_args()

    # Fix random seeds and number of threads
    np.random.seed(42)
    tf.random.set_seed(42)
    if args.recodex:
        tf.keras.utils.get_custom_objects(
        )["glorot_uniform"] = lambda: tf.keras.initializers.glorot_uniform(seed=42)
        tf.keras.utils.get_custom_objects(
        )["orthogonal"] = lambda: tf.keras.initializers.orthogonal(seed=42)
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
    morpho = MorphoDataset("czech_cac", max_sentences=args.max_sentences)

    # Create the network and train
    network = Network(args,
                      num_words=len(
                          morpho.train.data[morpho.train.FORMS].words),
                      num_tags=len(morpho.train.data[morpho.train.TAGS].words))
    for epoch in range(args.epochs):
        network.train_epoch(morpho.train, args)
        metrics = network.evaluate(morpho.dev, "dev", args)

    metrics = network.evaluate(morpho.test, "test", args)
    with open("tagger_we.out", "w") as out_file:
        print("{:.2f}".format(100 * metrics["accuracy"]), file=out_file)
