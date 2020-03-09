import numpy as np
from hmmlearn import hmm

class Model:
    def __init__(self):
        # CLASS * CASE * LEN * BLANK * ABBR * (BOW * BOS * EOS)
        # STATES = 18 * 3 * 3 * 2 * 2         * (2 * 2 * 2)
        STATES = (2 * 2 * 2)
        np.random.seed(0)
        model = hmm.MultinomialHMM(n_components=STATES)
        model.startprob_ = np.array([0.6, 0.3, 0.1])
        model.transmat_ = np.empty((STATES, STATES))
        model.transmat_.fill(1.0/STATES)

        # TODO: one-hot encoding of state emissions
        model.emissionprob_ = np.array([
            [0.0, 0.9, 0.1],
            [0.3, 0.6, 0.1],
            [0.5, 0.4, 0.1]])

        model.sample(4)
        pass

    def fit(self, data):
        pass

    def predict(self, data):
        return data.split('\n')