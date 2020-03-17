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

    def _prolix_pass(self, all, prolix):
        """
        Tag sequence pass through input data against prolix
        """
        print('Tagging prolix tokenization')
        remainingText = str(all)
        prolixTokenization = ''

        for i, proposed in enumerate(self.prolix):
            print(f'{i/len(self.prolix)*100:6.2f}%\r', end='')
            try:
                index = remainingText.index(proposed)
            except ValueError as _e:
                raise Exception(
                    f'Error, "{proposed}" not found in raw string') from None
            totalLength = index + len(proposed)
            remainingText = remainingText[totalLength:]
            prolixTokenization += 'N'*(totalLength-1) + 'W'

        return prolixTokenization

    def _true_pass(self, all, sentences):
        """
        Tag sequence pass through input data against gold data
        """
        print('Tagging true tokenization')
        remainingText = str(all)
        trueTokenization = ''
        END = False

        remainingTextOrigLen = len(remainingText)
        for sent in sentences:
            BOS = True
            print(
                f'{(1-len(remainingText)/remainingTextOrigLen)*100:6.2f}%\r', end='')
            for word in sent:
                if len(remainingText) <= len(word):
                    END = True
                    break
                try:
                    index = remainingText.index(word)
                except ValueError as _e:
                    raise Exception(
                        f'Error, "{word}" not found in raw string') from None
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

    def _check_nltk_base(self, language):
        try:
            stopwords.words(language)
            punkt.demo
        except LookupError as _le:
            nltk.download('stopwords')
            nltk.download('punkt')

    def _nltk_prep_corpus(self, corpus):
        try:
            corpusNLTK = globals()[corpus]
            assert(len(corpusNLTK.raw()) > 0)
        except LookupError as _le:
            nltk.download(corpus)
            corpusNLTK = globals()[corpus]
            assert(len(corpusNLTK.raw()) > 0)
        return corpusNLTK

    def _nltk_prep_gutenberg(self, gutenbergF):
        try:
            gutenberg.sents()
        except LookupError as _le:
            nltk.download('gutenberg')
        return gutenberg

    def _compute_true_prolix(self):
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

    def _compute_train_features(self):
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

    def _recover_prolix_trimmed(self):
        print('Recovering prolix from trimmed data')
        self.prolix = []
        buffer = ''
        for i, (char, tag) in enumerate(zip(self.all, self.prolixTokenization)):
            print(f'{i/len(self.prolixTokenization)*100:6.2f}%\r', end='')
            buffer += char
            if tag == 'W':
                self.prolix.append(buffer.strip())
                buffer = ''

    def _init_file(self, fileF):
        """
        Load inference data from file
        """
        with open(fileF, 'r') as f:
            self.all = f.read()
        self.prolix = scan(self.all)
        self.featured = add_observables(self.prolix, self.language)
        self.prolixTokenization = self._prolix_pass(self.all, self.prolix)

    def _init_value(self, value):
        """
        Load inference data from a string
        """
        self.all = value
        self.prolix = scan(self.all)
        self.featured = add_observables(self.prolix, self.language)
        self.prolixTokenization = self._prolix_pass(self.all, self.prolix)

    def _init_corpus(self, corpus, gutenbergF, train, endChar):
        """
        Load train or inference data from an NLTK (or gutenberg) corpus
        """
        print('Loading corpus from NLTK')
        if corpus:
            corpusNLTK = self._nltk_prep_corpus(corpus)
            print('Loading all relevant data')
            allSent = list(corpusNLTK.sents())
            self.all = self._collapse(corpusNLTK.raw())[:endChar]
        elif gutenbergF:
            gutenberg = self._nltk_prep_gutenberg(gutenbergF)
            print('Loading all relevant data')
            allSent = list(gutenberg.sents(gutenbergF))
            self.all = self._collapse(gutenberg.raw(gutenbergF))[:endChar]

        # @TODO: trap for bad prolix
        allSent[0] = ['Fake.Word.FF'] + allSent[0]
        self.all = 'Fake.Word.FF ' + self.all

        self.prolix = scan(self.all)
        self.prolixTokenization = self._prolix_pass(self.all, self.prolix)

        self.trueTokenization = self._true_pass(self.all, allSent)

        minlen = min(
            len(self.prolixTokenization),
            len(self.trueTokenization),
            len(self.all)
        )
        self.prolixTokenization = self.prolixTokenization[:minlen]
        self.trueTokenization = self.trueTokenization[:minlen]
        self.all = self.all[:minlen]

        self._recover_prolix_trimmed()

        self.featured = add_observables(self.prolix, self.language)

        self._compute_true_prolix()

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

        self._compute_train_features()

    def __init__(self, fileF=None, corpus=None, gutenbergF=None, value=None, endChar=None, train=False, language='english'):
        assert(corpus or value or fileF or gutenbergF)
        assert(not (corpus and value and fileF and gutenbergF))

        self.language = language
        self._check_nltk_base(language)

        if corpus or gutenbergF:
            self._init_corpus(corpus, gutenbergF, train, endChar)

        if fileF:
            assert(not train)
            self._init_file(fileF)

        if value:
            assert(not train)
            self._init_value(value)
