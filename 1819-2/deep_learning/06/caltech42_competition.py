#!/usr/bin/env python3
#
# We did three different models and then compared the results (IAA was about 90-95%).
# We then manualy resolved the conflicts as we thought these were somewhat problematic inputs.
#
#e99f6192-a850-11e7-a937-00505601122b
#ddb5d1e7-ace9-11e7-a937-00505601122b
#7f0a197b-bc00-11e7-a937-00505601122b

import numpy as np
import tensorflow as tf
import tensorflow_hub as tfhub  # Note: you need to install tensorflow_hub

from caltech42_v import Caltech42

# The neural network model
def eval_test(args, epoch):
    prediction = network.predict(caltech42.test.data["images"], batch_size=args.batch_size)
    with open(os.path.join(args.logdir, "caltech42_" + str(epoch+1) + "_test.txt"), "w", encoding="utf-8") as out_file:
        for probs in prediction:
            print(np.argmax(probs), file=out_file)  
    np.save(os.path.join(args.logdir, "caltech42_" + str(epoch+1) + "_test.npy"), prediction)

    prediction = network.predict(caltech42.dev.data["images"], batch_size=args.batch_size)
    np.save(os.path.join(args.logdir, "caltech42_" + str(epoch+1) + "_dev.npy"), prediction)


class Network(tf.keras.Model):
    def __init__(self, args):
        inputs = prev = tf.keras.layers.Input(shape=[224, 224, 3])

        mobilenet = tfhub.KerasLayer(
            "https://tfhub.dev/google/tf2-preview/mobilenet_v2/feature_vector/2", output_shape=[1280], trainable=False)
        prev = mobilenet(prev, training=True)
        prev = tf.keras.layers.Dense(48, activation=tf.nn.relu)(prev)
        # prev = tf.keras.layers.Dense(128, activation=tf.nn.relu)(prev)
        prev = tf.keras.layers.Dense(Caltech42.LABELS, activation=tf.nn.softmax)(prev)

        super().__init__(inputs=inputs, outputs=prev)

        self.compile(
            optimizer=tf.keras.optimizers.Adam(),
            loss=tf.keras.losses.SparseCategoricalCrossentropy(),
            metrics=[tf.keras.metrics.SparseCategoricalAccuracy(name="accuracy")],
            # loss=tf.keras.losses.CategoricalCrossentropy(from_logits=True, label_smoothing=0.1),
            # metrics=[tf.keras.metrics.CategoricalAccuracy(name="accuracy")],
        )

        self.tb_callback = tf.keras.callbacks.TensorBoard(
            args.logdir, update_freq=1000, profile_batch=1)
        self.tb_callback.on_train_end = lambda *_: None
        self.tb_callback.on_epoch_end = lambda epoch, logs: eval_test(args, epoch)
        
        self.summary()


    def train(self, caltech42, args):
        self.fit_generator(
            caltech42.train.batches(args.batch_size),
            epochs=args.epochs,
            validation_data=(caltech42.dev.data["images"], caltech42.dev.data["labels"]),
            callbacks=[self.tb_callback],
        )

if __name__ == "__main__":
    import argparse
    import datetime
    import os
    import re

    # Parse arguments
    parser=argparse.ArgumentParser()
    parser.add_argument("--batch_size", default = 64,
                        type = int, help = "Batch size.")
    parser.add_argument("--epochs", default = 1024,
                        type = int, help = "Number of epochs.")
    parser.add_argument("--threads", default = 0, type = int,
                        help = "Maximum number of threads to use.")
    args=parser.parse_args()

    # Fix random seeds
    np.random.seed(42)
    tf.random.set_seed(42)
    tf.config.threading.set_inter_op_parallelism_threads(args.threads)
    tf.config.threading.set_intra_op_parallelism_threads(args.threads)

    # Create logdir name
    args.logdir=os.path.join("logs", "{}-{}-{}".format(
        os.path.basename(__file__),
        datetime.datetime.now().strftime("%Y-%m-%d_%H%M%S"),
        ",".join(("{}={}".format(re.sub(
            "(.)[^_]*_?", r"\1", key), value) for key, value in sorted(vars(args).items())))
    ))

    # Load data
    caltech42=Caltech42(one_hot=False)

    # Create the network and train
    network=Network(args)
    network.train(caltech42, args)

    # Generate test set annotations, but in args.logdir to allow parallel execution.
    # with open(os.path.join(args.logdir, "caltech42_competition_test.txt"), "w", encoding = "utf-8") as out_file:
    #     for probs in network.predict(caltech42.test, args):
    #         print(np.argmax(probs), file = out_file)
