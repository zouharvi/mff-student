#!/usr/bin/env python3
import numpy as np
import tensorflow as tf

from mnist import MNIST

# The neural network model
class Network:
    def __init__(self, args):
        input1 = tf.keras.layers.Input(shape=[MNIST.H, MNIST.W, MNIST.C])
        input2 = tf.keras.layers.Input(shape=[MNIST.H, MNIST.W, MNIST.C])
        
        conv1 = tf.keras.layers.Conv2D(filters=10, kernel_size=3, strides=2, padding="valid", activation = tf.keras.activations.relu)
        conv2 = tf.keras.layers.Conv2D(filters=20, kernel_size=3, strides=2, padding="valid", activation = tf.keras.activations.relu)
        flat = tf.keras.layers.Flatten()
        full = tf.keras.layers.Dense(200, activation=tf.keras.activations.relu)

        def spawn(input_layer):
            return full(flat(conv2(conv1(input_layer))))

        network1 = spawn(input1)
        network2 = spawn(input2)

        labels_output = tf.keras.layers.Dense(10, activation=tf.keras.activations.softmax)
        labels_output1 = labels_output(network1)
        labels_output2 = labels_output(network2)

        labels_output_comb = tf.keras.layers.concatenate([network1, network2])
        labels_output_comb = tf.keras.layers.Dense(200, activation=tf.keras.activations.relu)(labels_output_comb)
        labels_output_comb = tf.keras.layers.Dense(1, activation=tf.keras.activations.sigmoid)(labels_output_comb)
        
        model = tf.keras.Model(inputs=[input1, input2], outputs=[labels_output1, labels_output_comb, labels_output2])
        model.compile(
            tf.keras.optimizers.Adam(),
            loss=[tf.keras.losses.SparseCategoricalCrossentropy(),
            tf.keras.losses.BinaryCrossentropy(),
            tf.keras.losses.SparseCategoricalCrossentropy()]
        )
        self.model = model

    @staticmethod
    def _prepare_batches(batches_generator):
        batches = []
        for batch in batches_generator:
            batches.append(batch)
            if len(batches) >= 2:
                model_inputs = [batches[0]["images"], batches[1]["images"]]
                model_targets = [batches[0]["labels"], (batches[0]["labels"] > batches[1]["labels"])*1, batches[1]["labels"]]
                yield (model_inputs, model_targets)
                batches.clear()

    def train(self, mnist, args):
        for epoch in range(args.epochs):
            for batch in self._prepare_batches(mnist.train.batches(args.batch_size)):
                self.model.train_on_batch(batch[0], batch[1])

            # Print development evaluation
            print("Dev {}: directly predicting: {:.4f}, comparing digits: {:.4f}".format(epoch + 1, *self.evaluate(mnist.dev, args)))

    def evaluate(self, dataset, args):
        total = 0
        correct_direct = 0
        correct_indirect = 0
        for inputs, targets in self._prepare_batches(dataset.batches(args.batch_size)):
            num1, direct, num2 = self.model.predict(inputs)
            total += len(direct)
            num1 = np.argmax(num1,axis=1)
            num2 = np.argmax(num2, axis=1)
            indirect = (num1>num2)*1
            direct_pred = (direct >= 0.5)*1
            direct_comp = direct_pred == np.reshape(targets[1], direct_pred.shape)
            correct_direct += np.sum(direct_comp)
            correct_indirect += np.sum(indirect == targets[1])
        return correct_direct/total, correct_indirect/total


if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=50, type=int, help="Batch size.")
    parser.add_argument("--epochs", default=10, type=int, help="Number of epochs.")
    parser.add_argument("--recodex", default=False, action="store_true", help="Evaluation in ReCodEx.")
    parser.add_argument("--threads", default=1, type=int, help="Maximum number of threads to use.")
    args = parser.parse_args()

    # Fix random seeds and number of threads
    np.random.seed(42)
    tf.random.set_seed(42)
    if args.recodex:
        tf.keras.utils.get_custom_objects()["glorot_uniform"] = lambda: tf.keras.initializers.glorot_uniform(seed=42)
    tf.config.threading.set_inter_op_parallelism_threads(args.threads)
    tf.config.threading.set_intra_op_parallelism_threads(args.threads)

    # Create logdir name
    args.logdir = os.path.join("logs", "{}-{}-{}".format(
        os.path.basename(__file__),
        datetime.datetime.now().strftime("%Y-%m-%d_%H%M%S"),
        ",".join(("{}={}".format(re.sub("(.)[^_]*_?", r"\1", key), value) for key, value in sorted(vars(args).items())))
    ))

    # Load the data
    mnist = MNIST()

    # Create the network and train
    network = Network(args)
    network.train(mnist, args)
    with open("mnist_multiple.out", "w") as out_file:
        direct, indirect = network.evaluate(mnist.test, args)
        print("{:.2f} {:.2f}".format(100 * direct, 100 * indirect), file=out_file)