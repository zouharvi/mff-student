#!/usr/bin/env python3

from data import Data
from evaluator import evaluate
from model import Model
import argparse

if False and __name__ == '__main__':
    parser = argparse.ArgumentParser(description='HMM based tokenizer')
    parser.add_argument('-i', '--inference', help='Data used for inference.', default=None)
    args, _args_rest = parser.parse_known_args()

    data = Data(corpus='genesis')

    model = Model()
    model.fit(data)
    # predicted = model.predict(data.all)

    # print('Train:')
    # evaluate(predicted, data.gold)
    
    # print('Dev:')
    # data = Data(corpus='genesis')
    # evaluate(predicted, data.gold)

    # if args.inference:
    #     dataArg = Data(value=args.inference)

    #     out = model.predict(dataArg.all)
    #     print('|'.join(out))
