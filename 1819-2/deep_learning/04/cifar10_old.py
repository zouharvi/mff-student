#!/usr/bin/env python3
import numpy as np
from cifar10_old import CIFAR10
from PIL import Image

cifar = CIFAR10()

def unpickle(file):
    import pickle
    with open(file, 'rb') as fo:
        d = pickle.load(fo, encoding='bytes')
    images = np.zeros(shape=(len(d[b'data']), 32, 32, 3))
    for i in range(len(d[b'data'])):
        images[i] = d[b'data'][i].reshape((3, 32, 32)).transpose([1,2,0])/255
    return images, d[b'labels']

b1, b1_l = unpickle('cifar10-all/data_batch_1')
b2, b2_l = unpickle('cifar10-all/data_batch_2')
b3, b3_l = unpickle('cifar10-all/data_batch_3')
b4, b4_l = unpickle('cifar10-all/data_batch_4')
b5, b5_l = unpickle('cifar10-all/data_batch_5')
b6, b6_l = unpickle('cifar10-all/test_batch')

cnc = np.append 
b_images = cnc(cnc(cnc(cnc(cnc(b1,b2,axis=0),b3,axis=0),b4,axis=0),b5,axis=0),b6,axis=0)
del b1
del b2
del b3
del b4
del b5
del b6
b_labels = cnc(cnc(cnc(cnc(cnc(b1_l,b2_l,axis=0),b3_l,axis=0),b4_l,axis=0),b5_l,axis=0),b6_l, axis=0).reshape(60000, 1)

cifar.train.data['labels'] = np.append(cifar.train.data['labels'], b_labels,axis=0)
cifar.train.data['images'] = np.append(cifar.train.data['images'], b_images,axis=0)