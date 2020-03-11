import nltk
# pylint: disable=locally-disabled, no-name-in-module
from nltk import punkt
from nltk.corpus import brown, genesis, webtext
from nltk.corpus import stopwords

import re
import numpy as np
import random

from features import word_features, add_observables, scan


class Data:
    def __init__(self, file=None, corpus=None, value=None, startSent=0, endSent=None, language='english'):
        assert(corpus or value or file)
        assert(not (corpus and value and file))

        self.language = language
        try:
            stopwords.words(language)
            punkt.demo
        except LookupError as _le:
            nltk.download('stopwords')
            nltk.download('punkt')

        if file:
            with open(file, 'r') as f:
                self.all = f.read()
            print('Computing additional prolix')
            self.prolix = scan(self.all)
            self.language = 'en'
            self.featured = add_observables(self.prolix, self.language)

        if corpus:
            print('Loading corpus from NLTK')
            try:
                corpusNLTK = globals()[corpus]
                assert(len(corpusNLTK.raw()) > 0)
            except LookupError as _le:
                nltk.download(corpus)
                corpusNLTK = globals()[corpus]
                assert(len(corpusNLTK.raw()) > 0)

            self.all = str(corpusNLTK.raw().replace('\n', ' '))
            # self.piecewise_features(corpusNLTK, self.all)
            print('Loading all relevant data')
            allSent = list(corpusNLTK.sents()[startSent:endSent])
            curSent = []
            curWord = []

            self.fTT = []
            self.fTF = []
            self.fFF = []

            wordsBOS = []
            print('Iterating sentences')
            while allSent:
                BOS = False
                if not curSent:
                    curSent = allSent.pop(0)
                    BOS = True

                curWord = curSent.pop(0)
                wordsBOS.append((curWord, BOS))

            # copy for future reference
            self.wordsBOS = list(wordsBOS)
                
            print('Iterating prolix')
            startLen = len(wordsBOS)
            self.transitions = ''
            while wordsBOS:
                if len(wordsBOS) % 1000 == 0:
                    print(f'{(1-len(wordsBOS)/startLen)*100:.2f}%\r', end='')
                word, BOS = wordsBOS.pop(0)
                cutIndex = self.all.index(word) + len(word)
                buffer = self.all[:cutIndex]
                self.all = self.all[cutIndex:]
                prolix = scan(buffer)
                
                for seg in prolix:
                    if word.startswith(seg):
                        if BOS:
                            self.transitions += '2'
                            self.fTT.append(seg)
                        else:
                            self.transitions += '1'
                            self.fTF.append(seg)
                    else:
                        self.transitions += '0'
                        self.fFF.append(seg)

            print('Computing features')
            self.fFF = list(map(lambda x: word_features(*x, self.language), zip([None] + self.fFF[:-1], self.fFF)))
            self.fTF = list(map(lambda x: word_features(*x, self.language), zip([None] + self.fTF[:-1], self.fTF)))
            self.fTT = list(map(lambda x: word_features(*x, self.language), zip([None] + self.fTT[:-1], self.fTT)))

            print('Computing additional prolix')
            self.all = str(corpusNLTK.raw().replace('\n', ' '))
            self.prolix = scan(self.all)
            self.featured = add_observables(self.prolix, self.language)

        if value:
            print('Computing additional prolix')
            self.all = value
            self.prolix = scan(self.all)
            self.featured = add_observables(self.prolix, self.language)