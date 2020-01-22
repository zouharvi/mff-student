#!/usr/bin/env python3
import sys

assert(len(sys.argv) == 3)

with open(sys.argv[1], 'r') as f:
    a0 = [float(x.rstrip('\n')) for x in f.readlines()]
with open(sys.argv[2], 'r') as f:
    a1 = [float(x.rstrip('\n')) for x in f.readlines()]

assert(len(a0) == len(a1))

def normalize(an):
    out = []
    vMin = min(an)
    vMax = max(an)
    vAvg = sum(an)/len(an)
    for v in an:
        out.append((v-vMin)/vMax)
    return out

def binarize(an, THRESHOLD = 0.5):
    return [v >= THRESHOLD for v in an]

def C0C0(an0, an1):
    total = 0
    for (b0, b1) in zip(an0, an1):
        if b0 and b1:
            total += 1
    return total/len(an0)

def C1C0(an0, an1):
    total = 0
    for (b0, b1) in zip(an0, an1):
        if (not b0) and b1:
            total += 1
    return total/len(an0)

def C0C1(an0, an1):
    total = 0
    for (b0, b1) in zip(an0, an1):
        if b0 and (not b1):
            total += 1
    return total/len(an0)

def C1C1(an0, an1):
    total = 0
    for (b0, b1) in zip(an0, an1):
        if (not b0) and (not b1):
            total += 1
    return total/len(an0)

a0 = normalize(a0)
a1 = normalize(a1)

a0 = binarize(a0)
a1 = binarize(a1)

c0c0 = C0C0(a0, a1)
c1c0 = C1C0(a0, a1)
c0c1 = C0C1(a0, a1)
c1c1 = C1C1(a0, a1)

c0cx = c0c0 + c0c1
c1cx = c1c0 + c1c1
cxc0 = c0c0 + c1c0
cxc1 = c0c1 + c1c1

pa = c0c0+c1c1
pe = c0cx*cxc0+c1cx*cxc1
kappa = (pa-pe)/(1-pe)

print(f'IAA: {pa*100:0.2f}%')
print(f'By chance: {pe*100:0.2f}%')
print(f'Cohen\'s Kappa:: {kappa*100:0.2f}%')

