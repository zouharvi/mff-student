#!/bin/env python3

import numpy as np
import os
from modelnet import ModelNet as MN

FILES = [
    (1.0, 'predictions/modelnet_231_crhalike_test.npy'),
    (1.5, 'predictions/modelnet_496_zoom0_test.npy'),
    (1.0, 'predictions/modelnet_499_ker3_test.npy'),
    (1.0, 'predictions/modelnet_500_base_test.npy'),
    (1.0, 'predictions/modelnet_500_bigcutout_test.npy'),
    (2.0, 'predictions/modelnet_974_zoom1_bigger_test.npy'),
    ]

PREDS = []

for path in FILES:
    PREDS.append(path[0]*np.load(path[1]))

ens = np.zeros(PREDS[0].shape[0], dtype=np.int8)

for line in range(PREDS[0].shape[0]):
    voting = np.zeros(PREDS[0].shape[1])
    for agent in PREDS:
        voting += agent[line]
    ens[line] = np.argmax(voting)

with open('predictions/ensemble_0_lab.txt', 'w') as f:
    for i in ens:
        print(MN.LABELS[i], file=f)