from urllib import request
from nltk.corpus import brown, genesis
import importlib
import nltk

class Data:
    def __init__(self, file=None, corpus=None, value=None):
        assert(corpus or value or file)
        assert(not (corpus and value and file))

        if file:
            with open(file, 'r') as f:
                self.all = f.read()

        if corpus:
            try:
                corpusNLTK = globals()[corpus]
                assert(len(corpusNLTK.raw()) > 0)
            except LookupError as _le:
                nltk.download(corpus)
                corpusNLTK = globals()[corpus]
                assert(len(corpusNLTK.raw()) > 0)

            self.all = str(corpusNLTK.raw())
            self.gold = list(corpusNLTK.words())

        if value:
            self.all += value

    def first_shot(self):
        pass

    def add_features(self):
        pass