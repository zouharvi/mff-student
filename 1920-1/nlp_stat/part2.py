#!/usr/bin/env python3
import collections

# Load text files
def loadFile(name):
    with open(name, 'r', encoding='iso-8859-2') as f:
        return [x.rstrip('\n') for x in f.readlines()]

textcz = loadFile('TEXTCZ1.txt')
texten = loadFile('TEXTEN1.txt')

# Generate n-grams and compute frequencies
def generateNgrams(tokens, n):
    ngrams = zip(*[tokens[i:] for i in range(n)])
    return ngrams
def frequency(ngram):
    return collections.Counter(ngram)

TOK_S = '<S>'
TOK_SS = [TOK_S]*2

def splitData(data):
    return (
        TOK_SS + data[:len(data)-60000], \
        TOK_SS + data[-60000:][:40000], \
        TOK_SS + data[-20000:]
    )

# Uniform, unigram, bigram and trigram probabilities
def gramProb0(dataFreq, toks):
    return 1/len(dataFreq['vocab'])
def gramProb1(dataFreq, toks):
    return dataFreq['unigram'][(toks[2],)]/len(dataFreq['data'])
def gramProb2(dataFreq, toks):
    return dataFreq['bigram'][(toks[1], toks[2])]/dataFreq['unigram'][(toks[1],)]
def gramProb3(dataFreq, toks):
    return dataFreq['trigram'][(toks[0], toks[1], toks[2])]/dataFreq['bigram'][(toks[0], toks[1])]
GRAM_PROBS = [gramProb0, gramProb1, gramProb2, gramProb3]

# Compute smoothed probabilities
def smoothProb(lambdas, dataFreq, toks):
    return sum([ \
        lambdas[i] * GRAM_PROBS[i](dataFreq, toks) for i in range(4) \
               ])

# Compute expected counts for lambdas
def expectedCounts(lambdas, index, dataFreq):
    total = 0
    tokens = dataFreq['data']
    for i in range(2, len(tokens)):
        total += \
            GRAM_PROBS[index](dataFreq, (tokens[i-2], tokens[i-1], tokens[i])) / \
            smoothProb(lambdas, dataFreq, (tokens[i-2], tokens[i-1], tokens[i]))
    return lambdas[index]*total

# Compute next lambdas
def recomputeLambdas(lambdas, dataFreq):
    counts = [expectedCounts(lambdas, i, dataFreq) for i in range(4)]
    return [c/sum(counts) for c in counts]
    
# Training, Heldout and Test
data0, data1, data2 = splitData(texten)

# EM smoothing algorithm
def emAlg(data):
    lambdas = [0.25, 0.25, 0.25, 0.25]
    dataFreq = {
        'vocab': set(data),
        'data': data,
        'unigram': frequency(generateNgrams(data, 1)),
        'bigram' : frequency(generateNgrams(data, 2)),
        'trigram': frequency(generateNgrams(data, 3)),
    }
    for i in range(5):
        lambdas = recomputeLambdas(lambdas, dataFreq)
        print(f'Lambdas: {lambdas}')
    
emAlg(data1)
