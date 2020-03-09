import numpy as np
from hmmlearn import hmm

class Model:
    def __init__(self):
        np.random.seed(0)
        model = hmm.MultinomialHMM(n_components=3)
        model.startprob_ = np.array([0.6, 0.3, 0.1])
        model.transmat_ = np.array([
            [0.7, 0.2, 0.1],
            [0.3, 0.5, 0.2],
            [0.3, 0.3, 0.4]])

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