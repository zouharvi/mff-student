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
parser.add_argument("--dropout", default=0, type=float, help="Dropout regularization.")
parser.add_argument("--epochs", default=30, type=int, help="Number of epochs.")
parser.add_argument("--hidden_layers", default="500", type=str, help="Hidden layer configuration.")
parser.add_argument("--l2", default=0, type=float, help="L2 regularization.")
parser.add_argument("--label_smoothing", default=0, type=float, help="Label smoothing.")
parser.add_argument("--recodex", default=False, action="store_true", help="Evaluation in ReCodEx.")
parser.add_argument("--threads", default=1, type=int, help="Maximum number of threads to use.")
args = parser.parse_args()
args.hidden_layers = [int(hidden_layer) for hidden_layer in args.hidden_layers.split(",") if hidden_layer]

# Fix random seeds
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

# Load data
mnist = MNIST()

# TODO: Implement L2 regularization.
# If `args.l2` is nonzero, create a `tf.keras.regularizers.L1L2` regularizer
# and use it for all kernels and biases of all Dense layers. Note that
# because of a bug if `args.l2` is zero, use `None` instead of `L1L2` regularizer
# with zero l2.
reg_l2 = None
if args.l2 != 0:
    reg_l2 = tf.keras.regularizers.l2(args.l2)

# TODO: Implement dropout.
# Add a `tf.keras.layers.Dropout` with `args.dropout` rate after the Flatten
# layer and after each Dense hidden layer (but not after the output Dense layer).

# Create the model
model = tf.keras.Sequential()
model.add(tf.keras.layers.Flatten(input_shape=[MNIST.H, MNIST.W, MNIST.C]))
model.add(tf.keras.layers.Dropout(args.dropout))

for hidden_layer in args.hidden_layers:
    model.add(tf.keras.layers.Dense(hidden_layer, activation=tf.nn.relu, kernel_regularizer=reg_l2, bias_regularizer=reg_l2))
    model.add(tf.keras.layers.Dropout(args.dropout))
model.add(tf.keras.layers.Dense(MNIST.LABELS, kernel_regularizer=reg_l2, bias_regularizer=reg_l2))

# TODO: Implement label smoothing.
# Apply the given smoothing. You will need to change the
# SparseCategorical{Crossentropy,Accuracy} to Categorical{Crossentropy,Accuracy}
# because label_smooting is supported only by CategoricalCrossentropy.
# That means you also need to modify the labels of all three datasets
# (i.e., mnist.{train,dev,test}.data["labels"]) from indices of the gold class
# to a full categorical distribution (you can use either NumPy or there is
# a helper method also in the Keras API).

def generate_dist(data):
    new_data = np.zeros((len(data), MNIST.LABELS))
    for i in range(len(data)):
        new_data[i][data[i]] = 1
    return new_data

mnist.test.data['labels'] = generate_dist(mnist.test.data['labels'])
mnist.train.data['labels'] = generate_dist(mnist.train.data['labels'])
mnist.dev.data['labels'] = generate_dist(mnist.dev.data['labels'])

model.compile(
    optimizer=tf.keras.optimizers.Adam(),
    loss=tf.keras.losses.CategoricalCrossentropy(from_logits=True, label_smoothing=args.label_smoothing),
    metrics=[tf.keras.metrics.CategoricalAccuracy(name="accuracy")],
)

tb_callback=tf.keras.callbacks.TensorBoard(args.logdir, update_freq=1000, profile_batch=1)
tb_callback.on_train_end = lambda *_: None
model.fit(
    mnist.train.data["images"][:5000], mnist.train.data["labels"][:5000],
    batch_size=args.batch_size, epochs=args.epochs,
    validation_data=(mnist.dev.data["images"], mnist.dev.data["labels"]),
    callbacks=[tb_callback],
)

test_logs = model.evaluate(mnist.test.data["images"], mnist.test.data["labels"], batch_size=args.batch_size)
tb_callback.on_epoch_end(1, dict(("val_test_" + metric, value) for metric, value in zip(model.metrics_names, test_logs)))

accuracy = test_logs[model.metrics_names.index("accuracy")]
with open("mnist_regularization.out", "w") as out_file:
    print("{:.2f}".format(100 * accuracy), file=out_file)