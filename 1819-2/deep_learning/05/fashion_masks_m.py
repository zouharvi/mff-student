#!/usr/bin/env python3

import numpy as np
import tensorflow as tf

from fashion_masks_data_v import FashionMasks

# Could not create cudnn handle: CUDNN_STATUS_INTERNAL_ERROR without following lines, solution from https://github.com/tensorflow/tensorflow/issues/24496#issuecomment-464909727
from tensorflow.compat.v1 import ConfigProto
from tensorflow.compat.v1 import InteractiveSession
config = ConfigProto()
config.gpu_options.allow_growth = True
session = InteractiveSession(config=config)


def comp_iou(A, B):
    overlap = np.sum(A & B)
    n_sum = np.sum(A) + np.sum(B)
    return overlap/(n_sum - overlap)


mean_iou = tf.keras.metrics.MeanIoU(2)


def comp_iou_2(y_true, y_pred):
    return mean_iou(y_true*1, tf.greater_equal(y_pred, 0.5))


def eval_test(args, epoch):
    with open(os.path.join(args.logdir, "fashion_masks_test" + str(epoch+1) + ".txt"), "w", encoding="utf-8") as out_file:
        test_labels, test_masks = network.model.predict(
            fashion_masks.test.data["images"], batch_size=args.batch_size)
        for label, mask in zip(test_labels, test_masks):
            print(np.argmax(label), *
                  (mask >= 0.5).astype(np.uint8).flatten(), file=out_file)


class WideResBuildingBlock():
    @staticmethod
    def create(in_tensor, channel_count_out, channel_count_in, downscale):
        stride = 2 if downscale else 1
        residual_l = tf.keras.layers.BatchNormalization()(in_tensor)
        residual_l = tf.keras.layers.Activation(
            tf.keras.activations.relu)(residual_l)
        residual_l = tf.keras.layers.Conv2D(
            filters=channel_count_out, kernel_size=3, strides=stride, padding="same", use_bias=False)(residual_l)
        residual_l = tf.keras.layers.BatchNormalization()(residual_l)
        residual_l = tf.keras.layers.Activation(
            tf.keras.activations.relu)(residual_l)
        residual_l = tf.keras.layers.Conv2D(
            filters=channel_count_out, kernel_size=3, strides=1, padding="same", use_bias=False)(residual_l)

        shortcut_l = None
        if channel_count_in == channel_count_out:
            shortcut_l = in_tensor
        else:
            shortcut_l = tf.keras.layers.MaxPool2D(
                pool_size=3, strides=stride, padding="same")(in_tensor)
            shortcut_l = tf.keras.layers.Lambda(lambda t: tf.pad(
                t, [[0, 0], [0, 0], [0, 0], [int(channel_count_out-channel_count_in), 0]]))(shortcut_l)
        return tf.keras.layers.Add()([shortcut_l, residual_l])

def sample_loss(masks, gold_label, gold_mask):
    return masks[:,:,gold_label]

def batch_loss(batch,  gold_labels, gold_masks):
    loss = tf.constant(0) 
    for index in range(batch.shape[0]):
        loss += sample_loss(batch[index], gold_labels[index], gold_masks[index])

class Network():
    def __init__(self, args):
        input_layer = tmp = tf.keras.layers.Input(
            shape=[FashionMasks.H, FashionMasks.W, FashionMasks.C])

        conv = tf.keras.layers.Conv2D(
            filters=args.init_filters* args.k, kernel_size=3, strides=1, padding="same", use_bias=False)(input_layer)
        bn = tf.keras.layers.BatchNormalization()(conv)
        tmp = tf.keras.layers.Activation(tf.keras.activations.relu)(bn)

        filters = args.init_filters
        k = args.k
        n = args.n

        for _ in range(n):
            tmp = WideResBuildingBlock.create(tmp, filters*k, filters*k, False)

        conv1 = tmp
        filters = filters*2

        tmp = WideResBuildingBlock.create(tmp, filters*k, filters*k/2, True)

        for _ in range(n-1):
            tmp = WideResBuildingBlock.create(tmp, filters*k, filters*k, False)

        conv2 = tmp
        filters = filters*2

        tmp = WideResBuildingBlock.create(tmp, filters*k, filters*k/2, True)

        for _ in range(n-1):
            tmp = WideResBuildingBlock.create(tmp, filters*k, filters*k, False)

        def upsample(layer, out_filters):
            tmp = tf.keras.layers.Conv2D(filters=out_filters, kernel_size=3, strides=1,
                                         padding="same", use_bias=True, activation=tf.keras.activations.relu)(layer)
            tmp = tf.keras.layers.UpSampling2D(
                2, interpolation="bilinear")(tmp)
            return tmp

        conv3 = tmp
        mask_in_3 = upsample(upsample(conv3, filters), filters)
        mask_in_2 = upsample(conv2, filters)
        mask_in_1 = tf.keras.layers.Conv2D(filters=filters, kernel_size=1, strides=1,
                                           padding="same", use_bias=True, activation=tf.keras.activations.relu)(conv1)

        mask_in = tf.keras.layers.Add()([mask_in_1, mask_in_2, mask_in_3])
        mask_predictions = tf.keras.layers.Conv2D(
            filters=1, kernel_size=1, strides=1, padding="same", use_bias=True, activation=tf.keras.activations.sigmoid)(mask_in)

        # GENERAL

        tmp = tf.keras.layers.MaxPool2D(tmp.shape[2], 2)(tmp)
        tmp = tf.keras.layers.Flatten()(tmp)
        labels_layer = tf.keras.layers.Dense(
            FashionMasks.LABELS, activation=tf.keras.activations.softmax)(tmp)

        self.model = tf.keras.Model(inputs=input_layer, outputs=[
                                    labels_layer, mask_predictions])

        self._optimizer = tf.keras.optimizers.Adam()

        self._label_loss = tf.keras.losses.CategoricalCrossentropy()
        self._mask_loss = tf.keras.losses.BinaryCrossentropy()
        self.metrics = [[tf.keras.metrics.CategoricalAccuracy()], [
            comp_iou_2]]

        self.tb_callback = tf.keras.callbacks.TensorBoard(
            args.logdir, update_freq=1000, profile_batch=1)
        self.tb_callback.on_train_end = lambda *_: None
        self.tb_callback.on_epoch_end = lambda epoch, logs: eval_test(
            args, epoch)
    
    def mask_loss(self,masks, gold_label, gold_mask):
        return self._mask_loss(gold_mask, masks[:,:,gold_label])

    def batch_mask_loss(self,batch,  gold_labels, gold_masks):
        loss = tf.constant(0,dtype='float32')
        for index in range(batch.shape[0]):
            loss += self.mask_loss(batch[index],gold_labels[index],gold_masks[index]) 

        return loss/batch.shape[0]

    @staticmethod
    def _prepare_batches(batches_generator):
        batches = []
        for batch in batches_generator:
            batches.append(batch)
            yield (batch["images"], [tf.keras.utils.to_categorical(batch["labels"], 10), batch["masks"]])
            batches.clear()

    def train(self, fashion_masks, args):
        for epoch in range(args.epochs):
            batch_i = 0
            for images, targets in self._prepare_batches(fashion_masks.train.batches(args.batch_size)):
                print('\rBatch: ' + str(batch_i) + '/' + str(int(55000 / args.batch_size)), end='')
                batch_i += 1
                self.train_on_batch(images, *targets)

            # Print development evaluation
            print('\rEpoch #{}, label accuracy: {:.4f}, iou: {:.4f}'.format(
                epoch+1, *self.evaluate(fashion_masks.dev, args)))
            eval_test(args, epoch)
            
    @tf.function
    def train_on_batch(self, images, labels_gold_cat, masks_gold):
        with tf.GradientTape() as gt:
            labels, masks = self.model(images, training=True)   
            label_loss = self._label_loss(labels_gold_cat, labels)
            mask_loss = self._mask_loss(masks_gold,masks)
            loss = label_loss + mask_loss
            grads = gt.gradient(loss, self.model.trainable_variables)
            self._optimizer.apply_gradients(
                zip(grads, self.model.trainable_variables)) 

    def evaluate(self, dataset, args):
        labels_correct = 0
        iou_total = 0
        total = 0
        for inputs, targets in self._prepare_batches(dataset.batches(args.batch_size)):
            labels, masks = self.model(inputs, training = False)
            labels_correct += np.sum(np.argmax(targets[0],axis = 1)==np.argmax(labels.numpy(), axis = 1))
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
    parser.add_argument("--batch_size", default=250,
                        type=int, help="Batch size.")
    parser.add_argument("--epochs", default=2000,
                        type=int, help="Number of epochs.")
    parser.add_argument("--threads", default=0, type=int,
                        help="Maximum number of threads to use.")
    parser.add_argument("--k", default=1, type=int)
    parser.add_argument("--n", default=1, type=int)
    parser.add_argument("--init_filters", default=16, type=int)
    args = parser.parse_args()

    # Fix random seeds
    np.random.seed(42)
    tf.random.set_seed(42)
    # tf.config.threading.set_inter_op_parallelism_threads(args.threads)
    # tf.config.threading.set_intra_op_parallelism_threads(args.threads)

    # Create logdir name
    args.logdir = os.path.join("logs", "{}-{}-{}".format(
        os.path.basename(__file__),
        datetime.datetime.now().strftime("%Y-%m-%d_%H%M%S"),
        ",".join(("{}={}".format(re.sub(
            "(.)[^_]*_?", r"\1", key), value) for key, value in sorted(vars(args).items())))
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
        test_labels, test_masks = network.predict(
            fashion_masks.test.data["images"], batch_size=args.batch_size)
        for label, mask in zip(test_labels, test_masks):
            print(np.argmax(label), *mask.astype(np.uint8).flatten(), file=out_file)