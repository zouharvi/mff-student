#!/usr/bin/env python3
# 7cf40fc2-b294-11e7-a937-00505601122b
# 7f0a197b-bc00-11e7-a937-00505601122b

import numpy as np
import tensorflow as tf
from modelnet import ModelNet

# The neural network model

def eval_write(args, epoch):
    prediction = network.model.predict(modelnet.test.data["voxels"], batch_size=args.batch_size)
    with open(os.path.join(args.logdir, "modelnet_" + str(epoch+1) + "_test.txt"), "w", encoding="utf-8") as out_file:
        for probs in prediction:
            print(np.argmax(probs), file=out_file)  
    np.save(os.path.join(args.logdir, "modelnet_" + str(epoch+1) + "_test.npy"), prediction)

    prediction = network.model.predict(modelnet.dev.data["voxels"], batch_size=args.batch_size)
    np.save(os.path.join(args.logdir, "modelnet_" + str(epoch+1) + "_dev.npy"), prediction)


class Network:
    def __init__(self, modelnet, args):
        self.model = tf.keras.Sequential()
        self.model.add(tf.keras.layers.Input((32, 32, 32, 1)))
        self.model.add(tf.keras.layers.Conv3D(16, kernel_size=3, strides=1, activation='relu', padding='same'))
        self.model.add(tf.keras.layers.MaxPooling3D(pool_size=2, strides=2, padding='valid'))
        self.model.add(tf.keras.layers.Conv3D(32, kernel_size=3, strides=1, activation='relu', padding='same'))
        self.model.add(tf.keras.layers.MaxPooling3D(pool_size=2, strides=2, padding='valid'))
        self.model.add(tf.keras.layers.Conv3D(128, kernel_size=3, strides=1, activation='relu', padding='same'))
        self.model.add(tf.keras.layers.MaxPooling3D(pool_size=2, strides=2, padding='valid'))
        self.model.add(tf.keras.layers.Conv3D(256, kernel_size=3, strides=1, activation='relu', padding='same'))
        self.model.add(tf.keras.layers.MaxPooling3D(pool_size=2, strides=2, padding='valid'))
        self.model.add(tf.keras.layers.Conv3D(512, kernel_size=3, strides=1, activation='relu', padding='same'))
        # self.model.add(tf.keras.layers.MaxPooling3D(pool_size=2, strides=2, padding='valid'))
        
        # self.model.add(tf.keras.layers.Dropout(0.5))
        # self.model.add(tf.keras.layers.Conv3D(64, 5, strides=2, activation='relu'))
        # # self.model.add(tf.keras.layers.Flatten())
        self.model.add(tf.keras.layers.GlobalAveragePooling3D())
        self.model.add(tf.keras.layers.Dense(10, activation='softmax'))

        self.model.summary()

        self.tb_callback = tf.keras.callbacks.TensorBoard(
            args.logdir, update_freq=1000, profile_batch=1)
        self.tb_callback.on_train_end = lambda *_: None
        self.tb_callback.on_epoch_end = lambda epoch, logs: eval_write(args, epoch)

        self.model.compile(loss=tf.losses.CategoricalCrossentropy(label_smoothing=0.1),
                      optimizer=tf.optimizers.Adam(lr=0.001),
                      metrics=['accuracy'])

    def train(self, modelnet, args):
        self.model.fit_generator(
                modelnet.train.batches(args.batch_size),
                # modelnet.train.data['voxels'], modelnet.train.data['labels'],
                # batch_size=args.batch_size, 
                steps_per_epoch=int(modelnet.train.size/args.batch_size),
                epochs=args.epochs,
                validation_data=(modelnet.dev.data['voxels'], modelnet.dev.data['labels']),
                shuffle=True,
                callbacks=[self.tb_callback])


if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=256, # previously None
                        type=int, help="Batch size.")
    parser.add_argument("--modelnet", default=32, type=int,
                        help="ModelNet dimension.")
    parser.add_argument("--epochs", default=1500,
                        type=int, help="Number of epochs.")
    parser.add_argument("--threads", default=4, type=int,
                        help="Maximum number of threads to use.")
    args = parser.parse_args()

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
    modelnet = ModelNet(args.modelnet)

    # Create the network and train
    network = Network(modelnet, args)
    network.train(modelnet, args)
