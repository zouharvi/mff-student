import re
from nltk.corpus import stopwords

def scan(all):
    prolix = re.split(r'([\w]+)', all)
    prolix = list(filter(lambda x: len(x) != 0 and x != ' ', prolix))
    return prolix

def add_observables(prolix, language):
    return list(map(lambda x: word_features(*x, language), zip([None] + prolix[:-1], prolix)))

def word_features(prev, word, language):
    # CLASS * LEN * CASE * STOP * BLANK * ABBR
    # EMISSIONS = 14 * 4 * 3 * 2 * 2 * 2
    return [
        word_feature_class(word),
        word_feature_len(word),
        word_feature_case(word),
        word_feature_stop(word, language),
        word_feature_blank(prev, word),
        word_feature_abbr(word),
    ]

def word_feature_case(word):
    if all([x.isupper() for x in word]):
        return 0 # cap 
    if word[0].isupper():
        return 1 # up
    return 2 # lo 

def word_feature_len(word):
    if len(word) <= 1:
        return 0
    if len(word) <= 3:
        return 1
    if len(word) <= 5:
        return 2
    return 3

def word_feature_blank(prev, _word):
    return int(bool(prev) and bool(re.match(r'\s', prev)))

def word_feature_abbr(word):
    return int(word in ['etc.', 'e.g.'])

def word_feature_stop(word, language):
    return int(bool(word) and (word in stopwords.words(language)))

def word_feature_class(word):
    SPECIAL = [
        r'[IVXCDM]+', r'[a-zA-Z]+', r'[0-9]+', r'\.', r',', r'\:', r'\;',
        r'[\?\!]', r'[\(\[\{\)\]\}]', r'[\-\+]', r'\/', r'[\"\']', r'~'
    ]
    
    for x, expr in enumerate(SPECIAL):
        if bool(re.match(expr, word)):
            return x

    return len(SPECIAL)
