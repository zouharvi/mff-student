#!/bin/env python3

import numpy as np
from cifar10 import CIFAR10

cf = CIFAR10()
cf_dev = np.transpose(cf.dev.data['labels'])
cf_test = np.transpose(cf.test.data['labels'])

# files = [('vilda_all_res', 1), ('vilda_a48', 0.3), ('vilda_alt', 0.3), ('kuba_1', 1.3), ('kuba_2', 1.0)]
files = [('vilda_alt', 1), ('vilda_a48', 1), ('vilda_all_res', 1)]
loaded = [np.load('probs/probs_test_' + x[0] + '.npy')*x[1] for x in files]

total = loaded[0]
for i in range(1,len(loaded)):
    total += loaded[i]

res = np.argmax(total, axis=1)
# print('Ensemble accuracy: ', np.mean(cf_dev==res))

with open('out.txt', 'w') as w:
    for p in res:
        print(p, file=w)