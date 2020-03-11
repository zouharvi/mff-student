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
            covariance_type='diag',
            verbose=True)
        
    def normalize(self, v):
        total = np.sum(v)
        if total == 0: 
            return v
        return v / total

    def feature_to_vec(self, feature):
        vClass = np.zeros(14)
        vLen   = np.zeros(4)
        vCase  = np.zeros(3)
        vStop  = np.zeros(2)
        vBlank = np.zeros(2)
        vAbbr  = np.zeros(2)
        vClass[feature[0]] = 1
        vLen[feature[1]] = 1
        vCase[feature[2]] = 1
        vStop[feature[3]] = 1
        vBlank[feature[4]] = 1
        vAbbr[feature[5]] = 1
        out = np.concatenate([vClass, vLen, vCase, vStop, vBlank, vAbbr])
        return np.array(out, dtype=np.int8)

    def fit(self, data):
        print('Fitting the model')
        self.fFF = np.array(list(map(self.feature_to_vec, data.fFF)))
        self.fTF = np.array(list(map(self.feature_to_vec, data.fTF)))
        self.fTT = np.array(list(map(self.feature_to_vec, data.fTT)))
            
        trans_p = lambda seq: data.transitions.count(seq)/(len(data.transitions)-1)
        start_p = lambda seq: data.transitions.count(seq)/len(data.transitions)

        self.model.transmat_ = np.array([
            self.normalize([trans_p('00'), trans_p('01'), trans_p('02')]),
            self.normalize([trans_p('10'), trans_p('11'), trans_p('12')]),
            self.normalize([trans_p('20'), trans_p('21'), trans_p('22')]),
        ])

        self.model.startprob_ = np.array(
            [start_p('0'), start_p('1'), start_p('2')]
        )

        self.model.means_ = np.array([
            self.fFF.mean(axis=0),
            self.fTF.mean(axis=0),
            self.fTT.mean(axis=0),
        ])

        # pylint: disable=locally-disabled, unsubscriptable-object
        epsilons = np.full(shape=(self.fFF.shape[1],), fill_value=np.finfo(float).eps)
        self.model.covars_ = np.array([
            self.fFF.var(axis=0)+epsilons,
            self.fTF.var(axis=0)+epsilons,
            self.fTT.var(axis=0)+epsilons,
        ])
        
    def predict(self, data):
        print('Data prediction')
        observables = np.array(list(map(self.feature_to_vec, data.featured)))
        return self.model.predict(observables)