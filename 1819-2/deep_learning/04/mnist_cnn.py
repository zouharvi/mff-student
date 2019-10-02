#!/usr/bin/env python3

import numpy as np
import tensorflow as tf
import re

from mnist import MNIST

# The neural network model


class Network(tf.keras.Model):
    def __init__(self, args):
        inputs = tf.keras.layers.Input(shape=[MNIST.H, MNIST.W, MNIST.C])

        rec_index = 0
        rec_defs = re.findall('\[[^\]]*\]', args.cnn)
        rec_defs = [x[1:-1].split(',') for x in rec_defs]
        layer_args = re.sub('\[[^\]]*\]', '', args.cnn)
        layer_args = layer_args.split(',')

        def simple_layer(previous, params):
            if params[0] == 'F':
                return tf.keras.layers.Flatten()(previous)
            elif params[0] == 'D':
                return tf.keras.layers.Dense(int(params[1]), activation=tf.nn.relu)(previous)
            elif params[0] == 'C':
                return tf.keras.layers.Conv2D(filters=int(params[1]),
                                                  kernel_size=int(params[2]), strides=int(params[3]), padding=params[4], activation='relu')(previous)
            elif params[0] == 'CB':
                previous = tf.keras.layers.Conv2D(filters=int(params[1]), kernel_size=int(params[2]),
                    strides=int(params[3]), padding=params[4], use_bias=False)(previous)
                previous = tf.keras.layers.BatchNormalization()(previous)
                return tf.keras.layers.Activation('relu')(previous)
            elif params[0] == 'M':
                return tf.keras.layers.MaxPool2D(pool_size=int(params[1]), strides=int(params[2]))(previous)

        hidden = inputs
        for layer_arg in layer_args:
            params = layer_arg.split('-')
            if params[0] == 'R':
                beg = hidden
                for inner_layer_args in rec_defs[rec_index]:
                    hidden = simple_layer(hidden, inner_layer_args.split('-'))
                rec_index += 1
                hidden = tf.add(hidden, beg)
            else:
                hidden = simple_layer(hidden, params)

        # Add the final output layer
        outputs = tf.keras.layers.Dense(
            MNIST.LABELS, activation=tf.nn.softmax)(hidden)

        super().__init__(inputs=inputs, outputs=outputs)

        self.compile(
            optimizer=tf.keras.optimizers.Adam(),
            loss=tf.keras.losses.SparseCategoricalCrossentropy(),
            metrics=[tf.keras.metrics.SparseCategoricalAccuracy(
                name="accuracy")],
        )

        self.tb_callback = tf.keras.callbacks.TensorBoard(
            args.logdir, update_freq=1000, profile_batch=1)
        self.tb_callback.on_train_end = lambda *_: None

    def train(self, mnist, args):
        self.fit(
            mnist.train.data["images"], mnist.train.data["labels"],
            batch_size=args.batch_size, epochs=args.epochs,
            validation_data=(
                mnist.dev.data["images"], mnist.dev.data["labels"]),
            callbacks=[self.tb_callback],
        )

    def test(self, mnist, args):
        test_logs = self.evaluate(
            mnist.test.data["images"], mnist.test.data["labels"], batch_size=args.batch_size)
        self.tb_callback.on_epoch_end(1, dict(
            ("val_test_" + metric, value) for metric, value in zip(self.metrics_names, test_logs)))
        return test_logs[self.metrics_names.index("accuracy")]


if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=50,
                        type=int, help="Batch size.")
    parser.add_argument("--cnn", default='', type=str,
                        help="CNN architecture.")
    parser.add_argument("--epochs", default=30, type=int,
                        help="Number of epochs.")
    parser.add_argument("--recodex", default=False,
                        action="store_true", help="Evaluation in ReCodEx.")
    parser.add_argument("--threads", default=1, type=int,
                        help="Maximum number of threads to use.")
    args = parser.parse_args()

    # Fix random seeds and number of threads
    np.random.seed(42)
    tf.random.set_seed(42)
    if args.recodex:
        tf.keras.utils.get_custom_objects(
        )["glorot_uniform"] = lambda: tf.keras.initializers.glorot_uniform(seed=42)
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
    mnist = MNIST()

    # Create the network and train
    network = Network(args)
    network.train(mnist, args)

    # Compute test set accuracy and print it
    accuracy = network.test(mnist, args)
    with open("mnist_cnn.out", "w") as out_file:
        print("{:.2f}".format(100 * accuracy), file=out_file)
