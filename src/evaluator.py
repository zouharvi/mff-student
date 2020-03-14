from features import scan


def evaluate(data, prediction):
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

    POSITIVE = {'W', 'B'}
    NEGATIVE = {'N', 'S'}
    for trueTag, predTag in zip(data.trueTokenization, prediction):
        if trueTag in NEGATIVE and predTag in NEGATIVE:
            wTN += 1
        elif trueTag in POSITIVE and predTag in POSITIVE:
            wTP += 1
        elif trueTag in POSITIVE and predTag in NEGATIVE:
            wFN += 1
        elif trueTag in NEGATIVE and predTag in POSITIVE:
            wFP += 1

    def safeDiv(x, y):
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
    print(f'Recall: {wTP/(wTP+wFN)*100:6.2f}%')

def decode(data, prediction):
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
    return '|' + '|'.join(out) + '|'