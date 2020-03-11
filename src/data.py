from nltk.corpus import brown, genesis, webtext
from nltk.corpus import stopwords
import nltk

import re
import numpy as np
import random

class Data:
    def __init__(self, file=None, corpus=None, value=None, gold=True, language='english'):
        assert(corpus or value or file)
        assert(not (corpus and value and file))

        self.language = language
        try:
            stopwords.words(language)
        except LookupError as _le:
            nltk.download('stopwords')
            nltk.download('punkt')

        if file:
            with open(file, 'r') as f:
                self.all = f.read()
            self.prolix = self.scan(self.all)
            self.add_observables(self.prolix)

        if corpus:
            print('Loading corpus from NLTK')
            try:
                corpusNLTK = globals()[corpus]
                assert(len(corpusNLTK.raw()) > 0)
            except LookupError as _le:
                nltk.download(corpus)
                corpusNLTK = globals()[corpus]
                assert(len(corpusNLTK.raw()) > 0)

            if gold:
                self.all = str(corpusNLTK.raw())
                print('Creating prolix')
                prolix = self.scan(self.all)
                self.fFF = []
                self.fTF = []
                self.fTT = []
                allSent = list(corpusNLTK.sents())
                prevSeg = None
                
                print('Adding features')
                print('Adding BOW')
                BOWwords = set()
                for sent in allSent:
                    proposed = sent.pop(0)
                    self.fTT.append(self.word_features(prevSeg, proposed))
                    prevSeg = proposed
                    BOWwords.add(self.scan(proposed)[0])

                    for proposed in sent:
                        self.fTF.append(self.word_features(prevSeg, proposed))
                        prevSeg = proposed
                        BOWwords.add(self.scan(proposed)[0])

                print('Adding not BOW')
                prevSeg = None
                for proposed in prolix:
                    if not (proposed in BOWwords):
                        self.fFF.append(self.word_features(prevSeg, proposed))
                    prevSeg = proposed
                self.BOWwords = BOWwords
                self.prolix = prolix

            else:
                self.all = str(corpusNLTK.raw())
                self.prolix = self.scan(self.all)
                self.add_observables(self.prolix)

        if value:
            self.all = value
            self.prolix = self.scan(self.all)
            self.add_observables(prolix)
        

    def scan(self, all):
        prolix = re.split(r'([\w]+)', all)
        prolix = list(filter(lambda x: len(x) != 0, prolix))
        return prolix

    def add_observables(self, prolix):
        print('Adding features')
        self.featured = list(map(self.word_features, zip([None] + prolix[:-1], prolix)))

    def word_features(self, prev, word):
        # CLASS * LEN * CASE * STOP * BLANK * ABBR
        # EMISSIONS = 14 * 4 * 3 * 2 * 2 * 2
        return [
            self.word_feature_class(word),
            self.word_feature_len(word),
            self.word_feature_case(word),
            self.word_feature_stop(word),
            self.word_feature_blank(prev, word),
            self.word_feature_abbr(word),
        ]

    def word_feature_case(self, word):
        if all([x.isupper() for x in word]):
            return 0 # cap 
        if word[0].isupper():
            return 1 # up
        return 2 # lo 

    def word_feature_len(self, word):
        if len(word) <= 1:
            return 0
        if len(word) <= 3:
            return 1
        if len(word) <= 5:
            return 2
        return 3

    def word_feature_blank(self, prev, _word):
        return int(bool(prev) and bool(re.match(r'\s', prev)))

    def word_feature_abbr(self, word):
        return int(word in ['etc.', 'e.g.'])

    def word_feature_stop(self, word):
        return int(bool(word) and (word in stopwords.words(self.language)))

    def word_feature_class(self, word):
        SPECIAL = [
            r'[IVXCDM]+', r'[a-zA-Z]+', r'[0-9]+', r'\.', r',', r'\:', r'\;',
            r'[\?\!]', r'[\(\[\{\)\]\}]', r'[\-\+]', r'\/', r'[\"\']', r'~'
        ]
        
        for x, expr in enumerate(SPECIAL):
            if bool(re.match(expr, word)):
                return x

        return len(SPECIAL)
        