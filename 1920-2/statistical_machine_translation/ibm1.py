#!/usr/bin/env python3

import argparse
from collections import defaultdict

sents = []
words_src = set()
words_tgt = set()

parser = argparse.ArgumentParser(description='IBM Model 1')
parser.add_argument('file', help='Triple-pipe delimeted SRC ||| TGT file')
args = parser.parse_args()

with open(args.file, 'r') as f:
    def sentenceToSet(sent):
        return list(filter(lambda x: len(x) != 0, sent.split(' ')))

    for line in f.readlines():
        items = list(map(sentenceToSet, line.lower().rstrip('\n').split(' ||| ')))
        uniform = [[1.0]*len(items[0]) for x in items[1]]
        sents.append([items[0], items[1], uniform])
        words_src |= set(items[0])
        words_tgt |= set(items[1])

# fix ordering
words_src = list(words_src)
words_tgt = list(words_tgt)
words_prob = [[0]*len(words_src) for x in words_tgt]

def addCount(word_src, word_tgt, count):
    src_i = words_src.index(word_src)
    tgt_i = words_tgt.index(word_tgt)
    words_prob[tgt_i][src_i] += count

def getCount(word_src, word_tgt):
    src_i = words_src.index(word_src)
    tgt_i = words_tgt.index(word_tgt)
    return words_prob[tgt_i][src_i]

def normalize(l):
    sm = sum(l)
    return [x/sm for x in l]

def transpose(l):
    return list(zip(*l))

def normalizeVert(l):
    x = transpose(l)
    x = [normalize(y) for y in x]
    return transpose(x)

def expectation():
    global words_prob
    for sent_src, sent_tgt, probs in sents:
        for word_tgt, probline in zip(sent_tgt, probs):
            for word_src, prob in zip(sent_src, probline):
                addCount(word_src, word_tgt, prob)

    words_prob = [normalize(x) for x in words_prob]

def maximization():
    global words_prob
    for i in range(len(sents)):
        sent_src, sent_tgt, probs = sents[i]
        probs = [[0]*len(sent_src) for x in sent_tgt]
        for j in range(len(sent_src)):
            word_src = sent_src[j]
            for k in range(len(sent_tgt)):
                word_tgt = sent_tgt[k]
                probs[k][j] = getCount(word_src, word_tgt)
        sents[i][2] = normalizeVert(probs)

def generateAlignment():
    alignment = ''
    for sent_src, sent_tgt, probs in sents:
        i = 0
        for word_tgt, probline in zip(sent_tgt, probs):
            argmax = max(range(len(probline)), key=lambda x: probline[x])
            alignment += f'{i}-{argmax} '
            i += 1
        alignment += '\n'
    return alignment.rstrip('\n')


prevAlignment = None
STEP = 1
while True:
    print(f'STEP {STEP}')
    expectation()
    maximization()
    alignment = generateAlignment()
    if alignment == prevAlignment:
        print(alignment)
        break
    else:
        prevAlignment = alignment
        STEP += 1