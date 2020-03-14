import nltk
# pylint: disable=locally-disabled, no-name-in-module
from nltk import punkt
from nltk.corpus import brown, genesis, webtext, abc
from nltk.corpus import stopwords, gutenberg

import re
import numpy as np
import random

from features import word_features, add_observables, scan


class Data:
    """
    Holds training/test data
    """

    def _collapse(self, text):
        """
        Collapse longer sequences of regex whitespace to a single space
        """
        return re.sub(r'\s+', ' ', text)

    def _prolixPass(self, all, prolix):
        """
        Tag sequence pass through input data against prolix
        """
        remainingText = str(all)
        prolixTokenization = ''

        for proposed in self.prolix:
            try:
                index = remainingText.index(proposed)
            except ValueError as _e:
                raise Exception(f'Error, "{proposed}" not found in raw string') from None
            totalLength = index + len(proposed)
            remainingText = remainingText[totalLength:]
            prolixTokenization += 'N'*(totalLength-1) + 'W'

        return prolixTokenization

    def _truePass(self, all, sentences):
        """
        Tag sequence pass through input data against gold data
        """
        remainingText = str(all)
        trueTokenization = ''
        END = False
        for sent in sentences:
            BOS = True

            for word in sent:
                if len(remainingText) <= len(word):
                    END = True
                    break
                try:
                    index = remainingText.index(word)
                except ValueError as _e:
                    raise Exception(f'Error, "{word}" not found in raw string') from None
                totalLength = index + len(word)
                remainingText = remainingText[totalLength:]

                # first iteration BOS is true
                if BOS:
                    trueTokenization += 'N'*(totalLength-1) + 'B'
                else:
                    trueTokenization += 'N'*(totalLength-1) + 'W'
                BOS = False
            if END:
                break
        return trueTokenization

    def __init__(self, fileF=None, corpus=None, gutenbergF=None, value=None, endChar=None, train=False, language='english'):
        assert(corpus or value or fileF or gutenbergF)
        assert(not (corpus and value and fileF and gutenbergF))

        self.language = language
        try:
            stopwords.words(language)
            punkt.demo
        except LookupError as _le:
            nltk.download('stopwords')
            nltk.download('punkt')

        if corpus or gutenbergF:

            print('Loading corpus from NLTK')
            if corpus:
                try:
                    corpusNLTK = globals()[corpus]
                    assert(len(corpusNLTK.raw()) > 0)
                except LookupError as _le:
                    nltk.download(corpus)
                    corpusNLTK = globals()[corpus]
                    assert(len(corpusNLTK.raw()) > 0)

                print('Loading all relevant data')
                allSent = list(corpusNLTK.sents())
                self.all = self._collapse(corpusNLTK.raw())[:endChar]
            else:
                try:
                    gutenberg.sents()
                except LookupError as _le:
                    nltk.download('gutenberg')
                print('Loading all relevant data')
                allSent = list(gutenberg.sents(gutenbergF))
                self.all = self._collapse(gutenberg.raw(gutenbergF))[:endChar]

            # @TODO:
            allSent[0] = ['Fake.Word.FF'] + allSent[0]
            self.all = 'Fake.Word.FF ' + self.all

            print('Computing prolix')
            self.prolix = scan(self.all)
            self.prolixTokenization = self._prolixPass(self.all, self.prolix)

            print('Computing true tokenization')
            self.trueTokenization = self._truePass(self.all, allSent)

            minlen = min(
                len(self.prolixTokenization),
                len(self.trueTokenization),
                len(self.all)
            )
            self.prolixTokenization = self.prolixTokenization[:minlen]
            self.trueTokenization = self.trueTokenization[:minlen]
            self.all = self.all[:minlen]

            print('Recovering prolix from trimmed data')
            self.prolix = []
            buffer = ''
            for char, tag in zip(self.all, self.prolixTokenization):
                buffer += char
                if tag == 'W':
                    self.prolix.append(buffer.strip())
                    buffer = ''
            self.featured = add_observables(self.prolix, self.language)

            print('Comparing prolix and true tokenization')
            self.fFF = []
            self.fTF = []
            self.fTT = []
            self.transitions = ''
            buffer = ''
            for a, b, char in zip(self.prolixTokenization, self.trueTokenization, self.all):
                buffer += char
                if buffer:
                    if a == 'W' and b == 'W':
                        self.fTF.append(buffer)
                        self.transitions += 'W'
                        buffer = ''
                    elif a == 'W' and b == 'B':
                        self.fTT.append(buffer)
                        self.transitions += 'B'
                        buffer = ''
                    elif a == 'W' and (b not in ['W', 'B']):
                        # prolix cut the word, but shouldn't have
                        self.fFF.append(buffer)
                        self.transitions += 'N'
                        buffer = ''

            if train:
                if len(self.fFF) == 0:
                    raise Exception('No training FF data')
                if len(self.fTF) == 0:
                    raise Exception('No training TF data')
                if len(self.fTT) == 0:
                    raise Exception('No training TT data')

            print(f'FF size: {len(self.fFF)}')
            print(f'TF size: {len(self.fTF)}')
            print(f'TT size: {len(self.fTT)}')

            print('Computing features')
            self.fFF = list(map(
                lambda x: word_features(*x, self.language),
                zip([None] + self.fFF[:-1], self.fFF))
            )
            self.fTF = list(map(
                lambda x: word_features(*x, self.language),
                zip([None] + self.fTF[:-1], self.fTF))
            )
            self.fTT = list(map(
                lambda x: word_features(*x, self.language),
                zip([None] + self.fTT[:-1], self.fTT))
            )

        if fileF:
            assert(not train)
            print('Computing prolix')
            with open(fileF, 'r') as f:
                self.all = f.read()
            self.prolix = scan(self.all)
            self.featured = add_observables(self.prolix, self.language)
            self.prolixTokenization = self._prolixPass(self.all, self.prolix)

        if value:
            assert(not train)
            print('Computing prolix')
            self.all = value
            self.prolix = scan(self.all)
            self.featured = add_observables(self.prolix, self.language)
            self.prolixTokenization = self._prolixPass(self.all, self.prolix)
