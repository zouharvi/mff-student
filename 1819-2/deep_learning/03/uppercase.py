#!/usr/bin/env python3
import argparse
import datetime
import os
import re

import numpy as np
import tensorflow as tf

from uppercase_data import UppercaseData


# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument("--alphabet_size", default=40, type=int,
                    help="If nonzero, limit alphabet to this many most frequent chars.")
parser.add_argument("--batch_size", default=50, type=int, help="Batch size.")
parser.add_argument("--epochs", default=6, type=int, help="Number of epochs.")
parser.add_argument("--hidden_layers", default="30, 30",
                    type=str, help="Hidden layers configuration.")
parser.add_argument("--threads", default=8, type=int,
                    help="Maximum number of threads to use.")
parser.add_argument("--window", default=7, type=int,
                    help="Window size to use.")
args = parser.parse_args()
args.hidden_layers = [int(hidden_layer)
                      for hidden_layer in args.hidden_layers.split(",") if hidden_layer]

# Fix random seeds
np.random.seed(42)
tf.random.set_seed(42)
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
uppercase_data = UppercaseData(args.window, args.alphabet_size)

# change target dataset
target_dset = 'test'
target_dset_obj = uppercase_data.dev
source_dset_obj = uppercase_data.train
if target_dset == 'test':
    target_dset_obj = uppercase_data.test
    # join train and dev labels
    class D:
        pass
    source_dset_obj = D
    source_dset_obj.data = {
        'windows': np.concatenate((uppercase_data.dev.data['windows'], uppercase_data.train.data['windows'])),
        'labels': np.concatenate((uppercase_data.dev.data['labels'], uppercase_data.train.data['labels']))
    }

model_layers = [
    tf.keras.layers.InputLayer(
        input_shape=[2 * args.window + 1], dtype=tf.int32),
    tf.keras.layers.Lambda(lambda x: tf.one_hot(
        x, len(uppercase_data.train.alphabet))),
    tf.keras.layers.Flatten(dtype=tf.int32),
]

for i in range(len(args.hidden_layers)):
    model_layers += [tf.keras.layers.Dense(
        args.hidden_layers[i], activation=tf.nn.relu)]

model_layers += [tf.keras.layers.Dense(uppercase_data.LABELS,
                                       activation=tf.nn.softmax)]

model = tf.keras.Sequential(model_layers)
model.compile(
    optimizer=tf.keras.optimizers.Adam(),
    loss=tf.keras.losses.SparseCategoricalCrossentropy(),
    metrics=[tf.keras.metrics.SparseCategoricalAccuracy(
        name="individual_accuracy")],
)

model.fit(
    source_dset_obj.data['windows'], source_dset_obj.data['labels'],
    batch_size=args.batch_size, epochs=args.epochs
)

res = model.predict(target_dset_obj.data['windows'])

with open("uppercase_" + target_dset + ".txt", "w") as out_file:
    out = ''
    for i in range(len(res)):
        if res[i][1] > res[i][0]:
            out += target_dset_obj.text[i].upper()
        else:
            out += target_dset_obj.text[i]
    out_file.write(out)