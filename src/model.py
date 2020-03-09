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
        EMISSIONS = 15 * 3 * 4 * 2 * 2 * 2 * 2 * 2
        EMISSIONS = 2 * 2
        
        np.random.seed(0)
        
        self.model = hmm.MultinomialHMM(
            n_components=len(STATES),
            params='st', # don't touch the emission probs
            init_params='st',
            verbose=True)
        self.model.startprob_ = np.empty(len(STATES))
        self.model.startprob_.fill(1.0/len(STATES))
        self.model.transmat_ = np.empty((len(STATES), len(STATES)))
        self.model.transmat_.fill(1.0/len(STATES))

        sFF = np.zeros(EMISSIONS)
        sFF.fill(1.0)
        sTF = np.zeros(EMISSIONS)
        sTF.fill(1.0)
        sTT = np.zeros(EMISSIONS)
        sTT.fill(1.0)
        
        sFF[0] = 0
        sFF[1] = 0
        sFF = self.normalize(sFF)
        
        sTF[1] = 0
        sTF = self.normalize(sTF)
        
        sTT = self.normalize(sTT)

        self.model.emissionprob_ = np.array([sFF, sTF, sTT])

    def normalize(self, v):
        norm = np.linalg.norm(v)
        if norm == 0: 
            return v
        return v / norm

    def feature_to_vec(self, feature):
        out = 0
        return 2*feature[0]+feature[1]
        POWERS = [2, 2, 2, 2, 2, 4, 3, 15]
        for i, f in enumerate(feature):
            out = out*POWERS[i] + f
        return out

    def fit(self, data):
        print('Fitting the model')
        self.vData = list(map(self.feature_to_vec, data.featured))
        self.vData = np.array(self.vData, dtype=np.int32)
        self.vData = self.vData.reshape(len(data.featured), 1)
        self.model.fit(self.vData)

    def decode(self, data):
        pass

    def predict(self, data):
        return data.split('\n')