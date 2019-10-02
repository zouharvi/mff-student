#!/usr/bin/env python3

from math import log
import numpy as np

def entropy_simple(a):
    tmp  = a[a != 0]
    return sum(-np.log(tmp)*tmp)

def entropy_cross(a, b):
    return sum(-a * np.log(b))

def kl_divergence(a, b):
    return entropy_cross(a, b) - entropy_simple(a)

if __name__ == "__main__":
    # Load data_freq distribution, each data point on a line
    data = {}
    with open("numpy_entropy_data.txt", "r") as file_data:
        for line in file_data:
            key = line.rstrip("\n")
            data[key] = data.get(key, 0) + 1

    # Load model distribution, each line `word \t probability`
    model = {}
    with open("numpy_entropy_model.txt", "r") as file_model:
        for line in file_model:
            line = line.rstrip("\n")
            word, prob = line.split('\t')
            model[word] = float(prob)
    
    # normalize to empirical distribution
    vals = sorted(set(data.keys()).union(set(model.keys())))
    data = np.array([data.get(key, 0) for key in vals]) / sum(data.values())
    model = np.array([model.get(key, 0) for key in vals])

    print("{:.2f}".format(entropy_simple(data)))
    print("{:.2f}".format(entropy_cross(data, model)))
    print("{:.2f}".format(kl_divergence(data, model)))