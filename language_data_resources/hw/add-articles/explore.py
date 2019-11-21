#!/usr/bin/env python3
import sys
from collections import Counter

def printCounterSignificant(countr, limit=9):
    for x,y in countr.items():
        if y >= limit:
            print(x, y)

with open(sys.argv[1], 'r') as f:
    text = f.read().replace('\n', ' ').lower().split(' ')

bigrams = []
for i in range(len(text)-1):
    bigrams.append((text[i], text[i+1]))

bigramsA = list(filter(lambda x: x[0] == 'a', bigrams))
counterA = Counter(bigramsA)
printCounterSignificant(counterA, 9)

bigramsT = list(filter(lambda x: x[0] == 'the', bigrams))
counterT = Counter(bigramsT)
printCounterSignificant(counterT, 20)