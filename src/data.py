from nltk.corpus import brown, genesis
from nltk.corpus import stopwords
import re
import nltk

class Data:
    def __init__(self, file=None, corpus=None, value=None, gold=True, language='english'):
        assert(corpus or value or file)
        assert(not (corpus and value and file))

        self.language = language
        try:
            stopwords.words(language)
        except LookupError as _le:
            nltk.download('stopwords')

        if file:
            with open(file, 'r') as f:
                self.all = f.read()
            self.scan()
            self.add_features()

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
                self.prolix = list(corpusNLTK.words())
                self.add_features()
            else:
                self.all = str(corpusNLTK.raw())
                self.scan()
                self.add_features()

        if value:
            self.all = value
            self.scan()
            self.add_features()
        

    def scan(self):
        print('Creating prolix')
        self.prolix = re.split(r'([\w]+)', self.all)
        # TODO: filter segments of size 0

    def add_features(self):
        print('Adding features')
        self.featured = map(self.word_features, zip([None] + self.prolix[:-1], self.prolix))

    def word_features(self, x):
        prev = x[0]
        word = x[1]
        # here we skip stopword text
        return [
            self.word_feature_class(word),
            self.word_feature_case(word),
            self.word_feature_len(word),
            self.word_feature_stop(word),
            self.word_feature_blank(prev, word),
            self.word_feature_abbr(word)
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
        if word in stopwords.words(self.language):
            return 0
        SPECIAL = [
            r'[IVXCDM]+', r'[a-zA-Z]+', r'[0-9]+', r'\.', r',', r'\:', r'\;',
            r'[\?\!]', r'[\(\[\{]', r'[\)\]\}]', r'\-', r'\+', r'\/', r'\"', r'\'', r'~'
        ]
        
        for x, expr in enumerate(SPECIAL):
            if bool(re.match(expr, word)):
                return 1+x

        return 1+len(SPECIAL)+1
        