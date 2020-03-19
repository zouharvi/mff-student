from features import scan
from data import Data
from random import choice
from utils import draw_bar

from typing import List


def evaluate(data: Data, prediction: str, example: bool = False) -> None:
    """
    Evaluate data object on provided prediction prolix tag sequence.
    """

    if len(data.trueTokenization) != len(prediction):
        raise Exception(
            f'True data length ({len(data.trueTokenization)}) does not match prediction length ({len(prediction)})'
        )

    wTP = 0
    wFP = 0
    wTN = 0
    wFN = 0

    indexFP = []
    indexFN = []

    POSITIVE = {'W', 'B'}
    NEGATIVE = {'N', 'S'}
    for i, (trueTag, predTag) in enumerate(zip(data.trueTokenization, prediction)):
        if trueTag in NEGATIVE and predTag in NEGATIVE:
            wTN += 1
        elif trueTag in POSITIVE and predTag in POSITIVE:
            wTP += 1
        elif trueTag in POSITIVE and predTag in NEGATIVE:
            wFN += 1
            indexFN.append(i)
        elif trueTag in NEGATIVE and predTag in POSITIVE:
            wFP += 1
            indexFP.append(i)

    def safeDiv(x: float, y: float):
        return x/y if y != 0 else float('nan')

    total = wTP + wFP + wTN + wFN
    wTP = safeDiv(wTP, total)
    wFP = safeDiv(wFP, total)
    wTN = safeDiv(wTN, total)
    wFN = safeDiv(wFN, total)

    print('Any-level: ')
    print(f'TP: {wTP*100:6.2f}%, FP: {wFP*100:6.2f}%')
    print(f'FN: {wFN*100:6.2f}%, TN: {wTN*100:6.2f}%')
    print(f'Precision: {wTP/(wTP+wFP)*100:6.2f}%')
    print(f'Recall:    {wTP/(wTP+wFN)*100:6.2f}%')

    if example:
        show_sample(data, prediction, indexFN, indexFP)

    draw_bar()


def show_sample(data: Data, prediction: str, indexFN: List[int], indexFP: List[int], window: int = 20) -> None:
    if indexFP or indexFN:
        print()
    if indexFN:
        index = choice(indexFN)
        print('False Negative example')
        print(data.all[index-window:index+window], sep='')
        print(prediction[index-window:index+window], sep='')
    if indexFP:
        index = choice(indexFP)
        print('False Positive example')
        print(data.all[index-window:index+window], sep='')
        print(prediction[index-window:index+window], sep='')


def decode(data: Data, prediction: str) -> None:
    """
    Decode input string against predicted sequence
    """
    out = []
    buffer = ''
    for tag, char in zip(prediction, data.all):
        buffer += char
        if tag in {'W', 'B'}:
            out.append(buffer)
            buffer = ''
    out += buffer
    out = [x.strip() for x in out]
    return '|' + '|'.join(out) + '|'
