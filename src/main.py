#!/usr/bin/env python3

from data import Data
from evaluator import evaluate
from model import Model
import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='HMM based tokenizer')
    parser.add_argument('-i', '--inference', help='Data used for inference.', default=None)
    args, _args_rest = parser.parse_known_args()

    data = Data(corpus='brown')
    data.first_shot()
    data.add_features()

    model = Model()
    model.fit(data.all)
    predicted = model.predict(data.all)

    print('Train:')
    evaluate(predicted, data.gold)
    
    print('Dev:')
    data = Data(corpus='genesis')
    data.first_shot()
    data.add_features()
    evaluate(predicted, data.gold)

    if args.inference:
        dataArg = Data(value=args.inference)
        dataArg.first_shot()
        dataArg.add_features()

        out = model.predict(dataArg.all)
        print('|'.join(out))
