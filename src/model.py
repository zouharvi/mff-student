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
        
        np.random.seed(0)
        
        self.model = hmm.GaussianHMM(
            n_components=len(STATES),
            covariance_type='spherical',
            verbose=True)
        self.model.startprob_ = np.empty(len(STATES))
        self.model.startprob_.fill(1.0/len(STATES))
        
        # self.model.transmat_ = np.empty((len(STATES), len(STATES)))
        # self.model.transmat_.fill(1.0/len(STATES))
        self.model.transmat_ = np.array([
            [1.0/3, 1.0/3, 1.0/3],
            [1.0/3, 1.0/3, 1.0/3],
            [1.0/3, 1.0/3, 1.0/3],
        ])

        # sFF = np.zeros(EMISSIONS)
        # sFF.fill(1.0)
        # sTF = np.zeros(EMISSIONS)
        # sTF.fill(1.0)
        # sTT = np.zeros(EMISSIONS)
        # sTT.fill(1.0)
        
        # sFF[0] = 0
        # sFF[1] = 0
        # sFF = self.normalize(sFF)
        
        # sTF[1] = 0
        # sTF = self.normalize(sTF)
        
        # sTT = self.normalize(sTT)

        # self.model.emissionprob_ = np.array([sFF, sTF, sTT])

        self.model.means_ = np.array([
            [1],
            [0],
            [1],
        ])

        self.model.covars_ = np.array([0.5, 0.5, 0.5])

    def normalize(self, v):
        norm = np.linalg.norm(v)
        if norm == 0: 
            return v
        return v / norm

    def feature_to_vec(self, feature):
        vClass = np.zeros(14)
        vLen   = np.zeros(4)
        vCase  = np.zeros(3)
        vStop  = np.zeros(2)
        vBlank = np.zeros(2)
        vAbbr  = np.zeros(2)
        vClass[feature[0]] = 1
        vCase[feature[1]] = 1
        vLen[feature[2]] = 1
        vStop[feature[3]] = 1
        vBlank[feature[4]] = 1
        vAbbr[feature[5]] = 1
        out = np.concatenate([vClass, vLen, vCase, vStop, vBlank, vAbbr])
        return np.array(out, dtype=np.int8)

    def fit(self, data):
        print('Fitting the model')
        self.fTT = list(map(self.feature_to_vec, data.fTT))
        self.fTF = list(map(self.feature_to_vec, data.fTF))
        self.fFF = list(map(self.feature_to_vec, data.fFF))
        
        # self.vData = np.array(self.vData, dtype=np.int32)
        # self.vData = self.vData.reshape(len(data.featured), 1)
        # self.model.fit(self.vData)

    def decode(self, data):
        pass

    def predict(self, data):
        return data.split('\n')