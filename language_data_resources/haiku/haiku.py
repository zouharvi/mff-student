#!/usr/bin/env python3
# wget http://www.gutenberg.org/files/34225/34225-0.txt

import re

# TODO: split by re \s whitespace instead of ' '

def countSyllables(raw):
    raw = f' {raw} '
    # naively counts the number of syllables in a string
    syllables = 0
    for syllable in ['a', 'e', 'i', 'y', 'o', 'u', 'ě', 'á', 'ý', 'í', 'é', 'ú']:
        syllables += raw.count(syllable)
    # diphthongs
    for syllable in ['ou', 'au']:
        syllables -= raw.count(syllable)
    # standalone words
    for word in ['z', 's', 'v']:
        syllables += raw.count(f' {word} ')
    return syllables

def formatSentenceByHaiku(sentence, index):
    # given three word split boundaries format the given sentence
    sp = sentence.split(' ')[:index[2]]
    haiku = []
    haiku.append(" ".join(sp[:index[0]]))
    haiku.append(" ".join(sp[index[0]:index[1]]))
    haiku.append(" ".join(sp[index[1]:index[2]]))
    return '\n'.join(haiku) + '\n-----'

def syllableSignature(sentence):
    # count syllables per word
    words = sentence.split(' ')
    return list(map(countSyllables, words))

def computeHaiku(sentence):
    # returns False if it is not a haiku
    # returns a triplet of word indicies, where lines should end
    signature = syllableSignature(sentence)

    def eatTokens(i, x):
        counter = 0
        while counter < x:
            if i >= len(signature):
                return False
            counter += signature[i]
            i+=1
        return i

    # first line
    i = eatTokens(0, 5)
    a = i
    
    # second line
    i = eatTokens(i, 7)
    b = i

    # third line
    i = eatTokens(i, 5)
    c = i

    if not (a and b and c):
        return False
    return [a, b, c]

with open('34225-0.txt', 'r') as f:
    raw = f.read().replace('\n', '')

# split to sentences
sentences = re.split('\\.|\\?|\\!', raw)

# lowercase and more cleaning
sentences = [x.lstrip(' ').lower() for x in sentences]

# drop empty lines
sentences = list(filter(lambda x: len(x) != 0, sentences))

# syllables = list(map(countSyllables, sentences))
sentences17 = list(filter(lambda x: countSyllables(x) == 17, sentences))

# filter only haiku eligible sentences
haikusSentences = list(filter(lambda x: computeHaiku(x), sentences17))

# format the sentences
haikus = list(map(lambda x: formatSentenceByHaiku(x, computeHaiku(x)), haikusSentences))

print('\n'.join(haikus))
print(f'Total number of haikus: {len(haikus)}')
