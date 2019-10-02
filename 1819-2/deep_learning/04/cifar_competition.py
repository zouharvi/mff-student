#!/usr/bin/env python3
# 
# 7cf40fc2-b294-11e7-a937-00505601122b
# 
# I trained several different models with accuracy about 85% (just basic convolutions),
# hoping they'd have independent errors and then did weighted ensemble with Jakub (ResNets)
#

import numpy as np
import tensorflow as tf
from tensorflow.keras.layers import Dense, Activation, Flatten, Dropout, BatchNormalization
from tensorflow.keras.layers import Conv2D, MaxPooling2D

# from cifar10 import CIFAR10
import cifar10

layer_desc_arg = 'C-64-3-1-same,M-3-2,C-256-3-1-same,M-3-2,C-512-3-1-same,M-3-2,F,D-128,B,D-256,B,D-512,B,D-1024,B'
# layer_desc_arg = 'C-32-3-1-same,C-64-3-1-same,M-3-2,C-256-3-1-same,M-3-2,C-512-3-1-same,M-3-2,F,D-128,B,DR,D-256,B,DR,D-512,B,DR,D-1024,B'
# layer_desc_arg = 'C-32-5-1-same,B,M-2-2,C-64-5-1-same,B,M-2-2,C-256-5-1-same,B,M-2-2,F,D-64'
# layer_desc_arg = 'C-64-3-1-same,M-3-2,C-256-3-1-same,M-3-2,C-512-3-1-same,M-3-2,F,D-128,B,D-256,B,D-512,B,D-1024,B'
# layer_desc_arg = 'C-64-3-1-same,M-3-2,C-256-3-1-same,R[C-256-3-1-same],M-3-2,C-512-3-1-same,M-3-2,F,D-128,B,DR,D-256,B,DR,D-512,B,DR,D-1024,B'

def eval_test(args, epoch):
    prediction = network.predict(cifar.test.data["images"], batch_size=args.batch_size)
    with open(os.path.join(args.logdir, "cifar_competition_test_" + str(epoch+1) + ".txt"), "w", encoding="utf-8") as out_file:
        for probs in prediction:
            print(np.argmax(probs), file=out_file)  
    np.save(os.path.join(args.logdir, "cifar_competition_test_" + str(epoch+1) + ".npy"), prediction)

    prediction = network.predict(cifar.dev.data["images"], batch_size=args.batch_size)
    np.save(os.path.join(args.logdir, "cifar_competition_dev_" + str(epoch+1) + ".npy"), prediction)

# The neural network model
class Network(tf.keras.Model):
    def __init__(self, args):
        inputs = tf.keras.layers.Input(shape=[32, 32, 3])

        rec_index = 0
        rec_defs = re.findall('\[[^\]]*\]', layer_desc_arg)
        rec_defs = [x[1:-1].split(',') for x in rec_defs]
        layer_args = re.sub('\[[^\]]*\]', '', layer_desc_arg)
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
            elif params[0] == 'B':
                previous = tf.keras.layers.Dropout(0.5)(previous)
                return tf.keras.layers.BatchNormalization()(previous)
            elif params[0] == 'M':
                previous = tf.keras.layers.MaxPool2D(pool_size=int(params[1]), strides=int(params[2]))(previous)
                return tf.keras.layers.BatchNormalization()(previous)

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
        outputs = tf.keras.layers.Dense(10, activation=tf.nn.softmax)(hidden)

        super().__init__(inputs=inputs, outputs=outputs)

        self.compile(
            optimizer=tf.keras.optimizers.Adam(),
            loss=tf.keras.losses.SparseCategoricalCrossentropy(),
            metrics=[tf.keras.metrics.SparseCategoricalAccuracy(
                name="accuracy")],
        )

        self.tb_callback=tf.keras.callbacks.TensorBoard(args.logdir, update_freq=1000, profile_batch=1)
        self.tb_callback.on_train_end = lambda *_: None
        self.tb_callback.on_epoch_end = lambda epoch, logs: eval_test(args, epoch)

    def train(self, cifar, args):
        self.fit(
            cifar.train.data["images"], cifar.train.data["labels"],
            batch_size=args.batch_size, epochs=args.epochs,
            validation_data=(cifar.dev.data["images"], cifar.dev.data["labels"]),
            callbacks=[self.tb_callback],
        )


if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=128, type=int, help="Batch size.")
    parser.add_argument("--epochs", default=10000, type=int, help="Number of epochs.")
    parser.add_argument("--threads", default=2, type=int, help="Maximum number of threads to use.")
    args = parser.parse_args()

    # Fix random seeds
    np.random.seed(42)
    tf.random.set_seed(42)
    tf.config.threading.set_inter_op_parallelism_threads(args.threads)
    tf.config.threading.set_intra_op_parallelism_threads(args.threads)

    # Create logdir name
    args.logdir = os.path.join("logs", "{}-{}-{}".format(
        os.path.basename(__file__),
        datetime.datetime.now().strftime("%Y-%m-%d_%H%M%S"),
        ",".join(("{}={}".format(re.sub("(.)[^_]*_?", r"\1", key), value) for key, value in sorted(vars(args).items())))
    ))

    
    # Load data
    cifar = cifar10.cifar
    # cifar = CIFAR10()

    # Create the network and train
    network = Network(args)
    network.train(cifar, args)

    # Generate test set annotations, but in args.logdir to allow parallel execution.
    with open(os.path.join(args.logdir, "cifar_competition_test.txt"), "w", encoding="utf-8") as out_file:
        for probs in network.predict(cifar.test.data["images"], batch_size=args.batch_size):
            print(np.argmax(probs), file=out_file)