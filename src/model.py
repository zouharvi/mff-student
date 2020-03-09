import numpy as np
from hmmlearn import hmm

class Model:
    def __init__(self):
        # BOW, BOS
        STATES = [
            (False, False),
            (True, False),
            (True, True)
        ]

        # CLASS * CASE * LEN * STOP * BLANK * ABBR * (BOW * BOS)
        EMISSIONS = 14 * 3 * 3 * 2 * 2 * 2 * (3)
        
        np.random.seed(0)
        model = hmm.MultinomialHMM(n_components=len(STATES))
        model.startprob_ = np.np.empty(len(STATES))
        model.startprob_.fill(1.0/len(STATES))
        model.transmat_ = np.empty((len(STATES), len(STATES)))
        model.transmat_.fill(1.0/len(STATES))

        model.emissionprob_ = np.array([
            [0.0, 0.9, 0.1],
            [0.3, 0.6, 0.1],
            [0.5, 0.4, 0.1]])

    def feature_to_vec(self, feature):
        vClass = np.zeros(15)
        vCase  = np.zeros(3)
        vLen   = np.zeros(3)
        vStop  = np.zeros(2)
        vBlank = np.zeros(2)
        vAbbr  = np.zeros(2)
        vClass[feature[0]] = 1
        vCase[feature[1]] = 1
        vLen[feature[2]] = 1
        vStop[feature[3]] = 1
        vBlank[feature[4]] = 1
        vAbbr[feature[5]] = 1
        return np.concatenate([vClass, vCase, vLen, vStop, vBlank, vAbbr])

    def vec_to_feature(self, _vec):
        vec = list(_vec)
        vClass = vec[:15]
        vec = vec[15:]
        vCase = vec[:3]
        vec = vec[3:]
        vLen = vec[:3]
        vec = vec[3:]
        vStop = vec[:2]
        vec = vec[2:]
        vBlank = vec[:2]
        vec = vec[2:]
        vAbbr = vec[:2]
        return (vClass.index(1), vCase.index(1), vLen.index(1), vStop.index(1), vBlank.index(1), vAbbr.index(1))

    def fit(self, data):
        pass

    def predict(self, data):
        return data.split('\n')