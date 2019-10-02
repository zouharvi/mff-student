#!/usr/bin/env python3
import argparse
import datetime
import os
import re

import numpy as np
import tensorflow as tf

from mnist import MNIST

# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument("--batch_size", default=50, type=int, help="Batch size.")
parser.add_argument("--epochs", default=10, type=int, help="Number of epochs.")
parser.add_argument("--hidden_layer", default=100, type=int, help="Size of the hidden layer.")
parser.add_argument("--threads", default=1, type=int, help="Maximum number of threads to use.")
parser.add_argument("--layers", default=3, type=int, help="Total number of hidden layers.")
parser.add_argument("--activation", default='none', type=str, help="Activation function.")
args = parser.parse_args()

# Create logdir name
args.logdir = "logs/{}-{}-{}".format(
    os.path.basename(__file__),
    datetime.datetime.now().strftime("%Y-%m-%d_%H%M%S"),
    ",".join(("{}={}".format(re.sub("(.)[^_]*_?", r"\1", key), value) for key, value in sorted(vars(args).items())))
)

# Load data
mnist = MNIST()

# Create the model
model_args = [
    tf.keras.layers.InputLayer((MNIST.H, MNIST.W, MNIST.C), name="input_images"),
    tf.keras.layers.Flatten(name="flatten"),
]

ACTIVATION_FUNCTIONS = {'none': None, 'relu': tf.nn.relu, 'tanh': tf.nn.tanh, 'sigmoid': tf.nn.sigmoid}

for i in range(args.layers):
    model_args.append(tf.keras.layers.Dense(
        args.hidden_layer,
        activation=ACTIVATION_FUNCTIONS.get(args.activation, None),
        name="hidden_"+str(i)))

model_args.append(tf.keras.layers.Dense(MNIST.LABELS, activation=tf.nn.softmax, name="output_layer"))
model = tf.keras.Sequential(model_args)

model.compile(
    optimizer=tf.keras.optimizers.Adam(),
    loss=tf.keras.losses.sparse_categorical_crossentropy, # SparseCategoricalCrossentropy in v2
    metrics=[tf.keras.metrics.SparseCategoricalAccuracy()],
)

tb_callback=tf.keras.callbacks.TensorBoard(args.logdir, histogram_freq=1, update_freq=1000)
tb_callback.on_train_end = lambda *_: None

model.fit(
    mnist.train.data["images"], mnist.train.data["labels"],
    batch_size=args.batch_size, epochs=args.epochs,
    validation_data=(mnist.dev.data["images"], mnist.dev.data["labels"]),
    callbacks=[tb_callback],
)

test_logs = model.evaluate(
    mnist.test.data["images"], mnist.test.data["labels"], batch_size=args.batch_size,
)

tb_callback.on_epoch_end(1, dict(("test_" + metric, value) for metric, value in zip(model.metrics_names, test_logs)))

print(test_logs[1])