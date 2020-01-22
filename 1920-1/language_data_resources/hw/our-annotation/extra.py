#!/usr/bin/env python3
import sys

assert(len(sys.argv) == 3)

text = []

with open(sys.argv[1], 'r') as f:
    data = f.readlines()
    a0 = [float(x.rstrip('\n').split(',')[0]) for x in data]
    text = [x.strip('\n').split(',')[2:4] for x in data]
with open(sys.argv[2], 'r') as f:
    a1 = [float(x.rstrip('\n').split(',')[0]) for x in f.readlines()]

assert(len(a0) == len(a1))

def normalize(an):
    out = []
    vMin = min(an)
    vMax = max(an)
    vAvg = sum(an)/len(an)
    for v in an:
        out.append((v-vMin)/vMax)
    return out

#a0 = normalize(a0)
#a1 = normalize(a1)

for x in zip(a0, a1, text):
    if abs(x[0]-x[1]) > 0.2:
        print(f'{x[0]:.2f} {x[1]:.2f}: {x[2][0]} | {x[2][1]}')
