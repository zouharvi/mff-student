import numpy as np
from hmmlearn import hmm


class Model:
    """
    Wrapper around hmmlearn HMM
    """

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
        """
        Normalize Python or Numpy list
        """

        total = np.sum(v)
        if total == 0:
            return v
        return v / total

    def feature_to_vec(self, feature):
        """
        Create one hot representation of feature vectors from Data::word_features
        """

        vClass = np.zeros(14)
        vLen = np.zeros(4)
        vCase = np.zeros(3)
        vStop = np.zeros(2)
        vBlank = np.zeros(2)
        vAbbr = np.zeros(2)
        vClass[feature[0]] = 1
        vLen[feature[1]] = 1
        vCase[feature[2]] = 1
        vStop[feature[3]] = 1
        vBlank[feature[4]] = 1
        vAbbr[feature[5]] = 1
        out = np.concatenate([vClass, vLen, vCase, vStop, vBlank, vAbbr])
        return np.array(out, dtype=np.int8)

    def fit(self, data):
        """
        Manually compute optimal HMM values from training data. Provided data object must have 
        corresponding traing attributes.
        """

        print('Fitting the model')

        # one-hot encode
        self.fFF = np.array(list(map(self.feature_to_vec, data.fFF)))
        self.fTF = np.array(list(map(self.feature_to_vec, data.fTF)))
        self.fTT = np.array(list(map(self.feature_to_vec, data.fTT)))

        def trans_p(seq):
            return data.transitions.count(seq)/data.transitions.count(seq[0])
        def start_p(seq):
            return data.transitions.count(seq)/len(data.transitions)

        self.model.transmat_ = np.array([
            self.normalize([trans_p('NN'), trans_p('NW'), trans_p('NB')]),
            self.normalize([trans_p('WN'), trans_p('WW'), trans_p('WB')]),
            self.normalize([trans_p('BN'), trans_p('BW'), trans_p('BB')]),
        ])

        self.model.startprob_ = np.array(
            [start_p('N'), start_p('W'), start_p('B')]
        )

        self.model.means_ = np.array([
            self.fFF.mean(axis=0),
            self.fTF.mean(axis=0),
            self.fTT.mean(axis=0),
        ])

        # pylint: disable=locally-disabled, unsubscriptable-object
        epsilons = np.full(
            shape=(self.fFF.shape[1],),
            fill_value=np.finfo(float).eps
        )

        # Gaussian mixture requires all covars to be strictly positive
        self.model.covars_ = np.array([
            self.fFF.var(axis=0)+epsilons,
            self.fTF.var(axis=0)+epsilons,
            self.fTT.var(axis=0)+epsilons,
        ])

    def predict(self, data):
        """
        Compute most probable state explanation of the provided sequence.
        """

        print('Data prediction')
        observables = np.array(list(map(self.feature_to_vec, data.featured)))
        prediction = list(self.model.predict(observables))

        out = ''
        # iterate prolix tag encoding
        for prolixTag in data.prolixTokenization:
            if prolixTag in ['N', 'S']:
                out += prolixTag
            elif prolixTag == 'W':
                if not prediction:
                    raise Exception(
                        'Fewer predictions outputs than proposed prolixes')
                pred = prediction.pop(0)
                if pred == 0:
                    out += 'N'
                elif pred == 1:
                    out += 'W'
                elif pred == 2:
                    out += 'B'
                else:
                    raise Exception('Undefined output symbol encountered')

        if prediction:
            raise Exception('More predictions outputs than proposed prolixes')

        return out
