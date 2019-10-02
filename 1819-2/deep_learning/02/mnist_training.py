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
parser.add_argument("--decay", default=None, type=str, help="Learning decay rate type")
parser.add_argument("--epochs", default=10, type=int, help="Number of epochs.")
parser.add_argument("--hidden_layer", default=200, type=int, help="Size of the hidden layer.")
parser.add_argument("--learning_rate", default=0.01, type=float, help="Initial learning rate.")
parser.add_argument("--learning_rate_final", default=None, type=float, help="Final learning rate.")
parser.add_argument("--momentum", default=0, type=float, help="Momentum.")
parser.add_argument("--optimizer", default="SGD", type=str, help="Optimizer to use.")
parser.add_argument("--recodex", default=False, action="store_true", help="Evaluation in ReCodEx.")
parser.add_argument("--threads", default=1, type=int, help="Maximum number of threads to use.")
args = parser.parse_args()

# Fix random seeds
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
    ",".join(("{}={}".format(re.sub("(.)[^_]*_?", r"\1", key), value)
              for key, value in sorted(vars(args).items())))
))

# Load data
mnist = MNIST()

# Create the model
model = tf.keras.Sequential([
    tf.keras.layers.Flatten(input_shape=[MNIST.H, MNIST.W, MNIST.C]),
    tf.keras.layers.Dense(args.hidden_layer, activation=tf.nn.relu),
    tf.keras.layers.Dense(MNIST.LABELS, activation=tf.nn.softmax),
])

scheduler = None
batch_total = args.epochs * len(mnist.train.data['labels']) / args.batch_size

if args.decay == 'polynomial':
    scheduler = tf.keras.optimizers.schedules.PolynomialDecay(
        initial_learning_rate=args.learning_rate, decay_steps=batch_total, end_learning_rate=args.learning_rate_final)
elif args.decay == 'exponential':
    scheduler = tf.keras.optimizers.schedules.ExponentialDecay(
        initial_learning_rate=args.learning_rate, decay_steps=batch_total, decay_rate=args.learning_rate_final/args.learning_rate)

optimizer = None
if args.optimizer == 'SGD':
    if scheduler == None:
        optimizer = tf.keras.optimizers.SGD(
            momentum=args.momentum, learning_rate=args.learning_rate)
    else:
        optimizer = tf.keras.optimizers.SGD(
            momentum=args.momentum, learning_rate=scheduler)
elif args.optimizer == 'Adam':
    if scheduler == None:
        optimizer = tf.keras.optimizers.Adam(learning_rate=args.learning_rate)
    else:
        optimizer = tf.keras.optimizers.Adam(learning_rate=scheduler)


model.compile(
    optimizer=optimizer,
    loss=tf.keras.losses.SparseCategoricalCrossentropy(),
    metrics=[tf.keras.metrics.SparseCategoricalAccuracy()],
)

tb_callback = tf.keras.callbacks.TensorBoard(
    args.logdir, histogram_freq=1, update_freq=1000, profile_batch=1)
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
tb_callback.on_epoch_end(1, dict(("val_test_" + metric, value)
                                 for metric, value in zip(model.metrics_names, test_logs)))


with open("mnist_training.out", "w") as out_file:
    print("{:.2f}".format(100 * test_logs[1]), file=out_file)
