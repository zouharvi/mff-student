#!/usr/bin/env python3
import numpy as np
import tensorflow as tf

from fashion_masks_data_v import FashionMasks

def comp_iou(A, B):
    overlap = np.sum(A & B)
    n_sum = np.sum(A) + np.sum(B)
    return overlap/(n_sum - overlap)

def comp_iou_2(y_true, y_pred):
    return tf.keras.metrics.MeanIoU(2)(y_true*1, tf.greater_equal(y_pred, 0.5))

def eval_test(args, epoch):
    with open(os.path.join(args.logdir, "fashion_masks_test" + str(epoch+1) + ".txt"), "w", encoding="utf-8") as out_file:
        test_labels, test_masks = network.predict(fashion_masks.test.data["images"], batch_size=args.batch_size)
        for label, mask in zip(test_labels, test_masks):
            print(np.argmax(label), *(mask>=0.5).astype(np.uint8).flatten(), file=out_file)

class Network(tf.keras.Model):
    def __init__(self, args):
        input_layer = tmp = tf.keras.layers.Input(shape=[FashionMasks.H, FashionMasks.W, FashionMasks.C])

        # GENERAL
        tmp = tf.keras.layers.Conv2D(filters=128, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        tmp = tf.keras.layers.BatchNormalization()(tmp)
        # tmp = tf.keras.layers.Conv2D(filters=128, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        # tmp = tf.keras.layers.BatchNormalization()(tmp)
        tmp = tf.keras.layers.MaxPool2D(pool_size=3, strides=2)(tmp)
        tmp = tf.keras.layers.Conv2D(filters=256, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        tmp = tf.keras.layers.BatchNormalization()(tmp)
        # tmp = tf.keras.layers.Conv2D(filters=256, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        # tmp = tf.keras.layers.BatchNormalization()(tmp)
        tmp = tf.keras.layers.MaxPool2D(pool_size=3, strides=2)(tmp)
        # tmp = tf.keras.layers.Conv2D(filters=512, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        # tmp = tf.keras.layers.BatchNormalization()(tmp)
        tmp = tf.keras.layers.Conv2D(filters=512, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        tmp = tf.keras.layers.BatchNormalization()(tmp)
        general_layer = tf.keras.layers.MaxPool2D(pool_size=3, strides=2)(tmp)

        # MASK
        tmp = tf.keras.layers.Conv2D(filters=256, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(general_layer)
        tmp = tf.keras.layers.BatchNormalization()(tmp)
        # tmp = tf.keras.layers.Conv2D(filters=256, kernel_size=3, strides=1, padding="same", activation = tf.keras.activations.relu)(tmp)
        # tmp = tf.keras.layers.BatchNormalization()(tmp)
        tmp = tf.keras.layers.Flatten()(tmp)
        masks_layer = tf.keras.layers.Dense(28*28)(tmp)
        # masks_output = tf.keras.layers.Conv2DTranspose(filters=1, kernel_size=1, strides=2, padding="same", activation = tf.keras.activations.relu)(tmp)

        # LABEL
        tmp = tf.keras.layers.Flatten()(general_layer)
        tmp = tf.keras.layers.Dense(512, activation=tf.keras.activations.relu)(tmp)
        tmp = tf.keras.layers.Dropout(0.5)(tmp)
        labels_layer = tf.keras.layers.Dense(FashionMasks.LABELS, activation=tf.keras.activations.softmax)(tmp)

        super().__init__(inputs=input_layer, outputs=[labels_layer, masks_layer])
        
        self.compile(
            tf.keras.optimizers.Adam(),
            loss=[
                tf.keras.losses.SparseCategoricalCrossentropy(),
                tf.keras.losses.BinaryCrossentropy()
            ],
            metrics=[
                [tf.keras.metrics.SparseCategoricalAccuracy()],
                [comp_iou_2]
            ]
        )

        self.tb_callback=tf.keras.callbacks.TensorBoard(args.logdir, update_freq=1000, profile_batch=1)
        self.tb_callback.on_train_end = lambda *_: None
        self.tb_callback.on_epoch_end = lambda epoch, logs: eval_test(args, epoch)

    @staticmethod
    def _prepare_batches(batches_generator):
        batches = []
        for batch in batches_generator:
            batches.append(batch)
            yield (batch["images"], [batch["labels"], batch["masks"].reshape(int(np.size(batch["masks"])/784),784)])
            batches.clear()

    def train(self, fashion_masks, args):
        for epoch in range(args.epochs):
            batch_i = 0
            for batch in self._prepare_batches(fashion_masks.train.batches(args.batch_size)):
                print('\rBatch ', batch_i, '/', int(55000/args.batch_size), sep='', end='')
                batch_i += 1
                self.train_on_batch(batch[0], batch[1])

            # Print development evaluation
            print('\rEpoch #{}: label accuracy: {:.4f}, IoU: {:.4f}'.format(epoch+1, *self.evaluate(fashion_masks.dev, args)))
            eval_test(args, epoch)


    def evaluate(self, dataset, args):
        labels_correct = 0
        iou_total = 0
        total = 0
        for inputs, targets in self._prepare_batches(dataset.batches(args.batch_size)):
            labels, masks = self.predict(inputs)
            labels_correct += np.sum(np.argmax(labels, axis=1)==targets[0])
            total += len(labels)
            masks = masks >= 0.5 
            for i in range(args.batch_size):
                iou_total += comp_iou(masks[i], targets[1][i])
        return labels_correct/total, iou_total/total

if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--batch_size", default=50, type=int, help="Batch size.")
    parser.add_argument("--epochs", default=2000, type=int, help="Number of epochs.")
    parser.add_argument("--threads", default=0, type=int, help="Maximum number of threads to use.")
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
    # For some reason the logdirs are not created automatically
    os.makedirs(args.logdir)
    # with open(os.path.join(args.logdir, "tmptest.txt"), "w", encoding="utf-8") as out_file:
    #     print('aa', file=out_file)

    # Load data
    fashion_masks = FashionMasks()

    # Create the network and train
    network = Network(args)
    network.train(fashion_masks, args)

    # Predict test data in args.logdir
    with open(os.path.join(args.logdir, "fashion_masks_test.txt"), "w", encoding="utf-8") as out_file:
        test_labels, test_masks = network.predict(fashion_masks.test.data["images"], batch_size=args.batch_size)
        for label, mask in zip(test_labels, test_masks):
            print(np.argmax(label), *mask.astype(np.uint8).flatten(), file=out_file)