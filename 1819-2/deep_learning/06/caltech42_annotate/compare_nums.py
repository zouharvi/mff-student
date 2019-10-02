#!/bin/env python3

import os

FILE1 = 'test_num_both.txt'
FILE2 = 'test_daniel.txt'

labels = [
    "airplanes", "bonsai", "brain", "buddha", "butterfly",
    "car_side", "chair", "chandelier", "cougar_face", "crab",
    "crayfish", "dalmatian", "dragonfly", "elephant", "ewer",
    "faces", "flamingo", "grand_piano", "hawksbill", "helicopter",
    "ibis", "joshua_tree", "kangaroo", "ketch", "lamp", "laptop",
    "llama", "lotus", "menorah", "minaret", "motorbikes", "schooner",
    "scorpion", "soccer_ball", "starfish", "stop_sign", "sunflower",
    "trilobite", "umbrella", "watch", "wheelchair", "yin_yang",
]

with open(FILE1) as f:
    labels1 = [labels[int(x.replace('\n', ''))] for x in f.readlines()]
with open(FILE2) as f:
    labels2 = [labels[int(x.replace('\n', ''))] for x in f.readlines()]

different = 0

for i in range(len(labels1)):
    if labels1[i] != labels2[i]:
        different += 1
        print('{0:03d}.jpg: '.format(i) + labels1[i] + ' x ' + labels2[i])

print('IAA: ' + str(100 - 100.0*different/len(labels1)))