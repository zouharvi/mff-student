#!/usr/bin/env python3

from data import Data
from evaluator import evaluate, decode
from model import Model
import numpy as np
import argparse

"""
Entry point for HMM tokenizer
"""

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='HMM based tokenizer')
    parser.add_argument('-i', '--interactive',
                        help='Run with interactive input loop.', action='store_true', default=None)
    parser.add_argument(
        '-d', '--heldout', help='Evaluate on heldout data.', action='store_true', default=None)
    parser.add_argument(
        '-v', '--value', help='Value to tokenize.', default=None)
    args, _args_rest = parser.parse_known_args()

    def bar(): return print('='*30)

    # Training data
    bar()
    dataT = Data(corpus='genesis', train=True, endChar=200000)
    bar()
    model = Model()
    model.fit(dataT)
    bar(), print('Train data evaluation:'), bar()
    predicted = model.predict(dataT)
    evaluate(dataT, predicted)
    bar()

    if args.heldout:
        dataH = Data(gutenbergF='austen-sense.txt', endChar=50000)
        bar(), print('Heldout data evaluation:'), bar()
        predicted = model.predict(dataH)
        evaluate(dataH, predicted)
    if args.value:
        dataH = Data(value=args.value)
        predicted = model.predict(dataH)
        print(decode(dataH, predicted))
    if args.interactive:
        while True:
            input_text = input('> ')
            if not input_text:
                break
            dataH = Data(value=input_text)
            predicted = model.predict(dataH)
            print(decode(dataH, predicted))
