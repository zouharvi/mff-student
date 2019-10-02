#!/usr/bin/env python3
from sys import stdin

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


for line in stdin:
    print(labels[int(line)])