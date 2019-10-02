#!/bin/env python3

from modelnet import ModelNet

FILE1 = 'predictions/test_1_lab_best.txt'
FILE2 = 'predictions/test_1_num_best.txt'
with open(FILE1, 'r') as f:
    labels = f.readlines()

with open(FILE2, 'w') as f:
    for l in labels:
        l = l.replace('#', '').replace('\n', '')
        print(ModelNet.LABELS.index(l), file=f) 