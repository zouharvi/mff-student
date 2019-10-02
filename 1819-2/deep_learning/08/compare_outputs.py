#!/bin/env python3

import numpy as np
from modelnet import ModelNet
import os

import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

mn = ModelNet(32)

def display_model(volume):
    voxels = np.logical_or(volume == 1, volume == True)
    colors = np.empty(voxels.shape, dtype=object)
    colors[volume] = 'red'
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.voxels(voxels, facecolors=colors, edgecolor='k')
    plt.show()

def display_t(i):
    display_model(np.rot90(mn.test.data['voxels'][i].reshape(32,32,32), axes=(0,1)))

def resolve(i):
    print('{}: {}/{}'.format(i, pred1[i-1], pred2[i-1]))
    display_t(i-1)


FILE1 = 'predictions/test_0_lab_best.txt'
FILE2 = 'predictions/ensemble_0_lab.txt'
mn = ModelNet(32)

with open(FILE1, 'r') as f:
    pred1 = [(x.replace('\n', '')) for x in f.readlines()]
with open(FILE2, 'r') as f:
    pred2 = [(x.replace('\n', '')) for x in f.readlines()]

try:
    os.mkdir('conflicts')
except:
    pass

# display_model(mn.test.data['voxels'][1].reshape(32,32,32))
# display_model(master_model.data)

agree = len(pred1)
overrules = 0
with open('{}_lab'.format(FILE1), 'w') as f:
    for i in range(len(pred1)):
        if pred1[i] != pred2[i]:
            agree -= 1
            if  "#" not in pred1[i]:
                print('{}/{}'.format(pred1[i], pred2[i]), file=f)
            else:
                overrules += 1
                print(pred1[i], file=f)
        else:
            print(pred1[i], file=f)

print('IAA: {:.2f}%, different: {}, overrules: {}'.format(
    agree/len(pred1)*100, len(pred1)-agree, overrules))
print('Labeled version of the first file: {}_lab'.format(FILE1))

# find closest
# min_o = 1
# min_i = -1
# for i in range(len(mn.test.data['voxels'])):
#     test_obj = np.rot90(mn.test.data['voxels'][i], axes=(0,2))
#     target_obj = master_model.data*1
#     overlap = np.mean(np.abs(test_obj-target_obj))
#     if overlap < min_o:
#         min_i = i
#         min_o = overlap

def start_resolving():
    while True:
        index = int(input('Index: '))
        resolve(index)