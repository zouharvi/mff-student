#!/usr/bin/env python3

from data import Data
from evaluator import evaluate
from model import Model
import numpy as np
import argparse

# model.predict(dataH)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='HMM based tokenizer')
    parser.add_argument('-i', '--interactive', help='Run with interactive input loop.', default=None)
    args, _args_rest = parser.parse_known_args()

    dataT = Data(corpus='genesis', startSent=0, endSent=500)
    model = Model()
    model.fit(dataT)

    model = Model()
    model.fit(dataT)

    dataH = Data(corpus='genesis', startSent=0, endSent=50)
    
    predictedStates = model.predict(dataH)
    evaluate(dataH, predictedStates)