#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
LAnguage DISTInctor
Author: Vilém Zouhar
'''

import json, re, collections, time
from StringIO import StringIO
from math import log

# command line arguments:
# -ld --load-database (path to compiled database)
# -sv --save-database (path to target database file, will be overridden - to merge, load the database first)
# -ls --language-samples (path to json file)
# -lc --language-comparison (show language comparison) (mutually exclusive with -i, -fi)
# -i --input (string containing text to categorize) (mutually exclusive with -lc, -fi)
# -fi --file-input (path to text file) (mutually exclusive with -i, -lc)

lang_data = {}
FREQ_LIMIT = 0
WORD_CHAR_RATIO = 10.0

def clean_data(data):
    # remove unwanted symbols from input
    data = data.lower()
    data_clean = re.sub("[.?!<>(){}\[\]\"'_%*\n$0123456789]+", " ", data)
    data_clean = re.sub('\s+', ' ', data_clean)
    return data_clean


def process_words(words):
    # calculate word frequency
    words_freq = {}
    for word in words:
        if word in words_freq:
            words_freq[word] += 1.0
        else:
            words_freq[word] = 1.0
    '''
    # remove underrepresented words (below FREQ_LIMIT)
    words_freq_clean = {}
    for word in words_freq.keys():
        freq = words_freq[word]
        if freq > FREQ_LIMIT:
            words_freq_clean[word] = freq

    return words_freq_clean
    '''
    return words_freq

def process_chars(chars):
    # calculate word frequency
    chars_freq = {}
    for char in chars:
        if char in chars_freq:
            chars_freq[char] += 1
        else:
            chars_freq[char] = 1
    return chars_freq

def create_lang_object(object, data):
    data_clean = clean_data(data)
    object["word_freq"] = process_words(data_clean.split(" "))
    
    word_count = 0
    for value in object["word_freq"].values():
        word_count += value 
    object["word_count"] = word_count
    object["char_freq"] = process_chars(data_clean.replace(" ", ""))

    char_count = 0
    for value in object["char_freq"].values():
        char_count += value 
    object["char_count"] = char_count

def add_to_database(key, data):
    # adds data to local database
    sample = 0
    if not key in lang_data:
        sample = lang_data[key] = {}
    else:
        sample = lang_data[key]
    create_lang_object(sample, data)  

def define_langs():
    # load language definition into database
    # invalid json is checked for
    content = open("./lang_def.json").read()
    try:
        sample_data = json.load(StringIO(content))
        lang_keys = list(sample_data.keys())
        for key in lang_keys:
            add_to_database(key, sample_data[key])
    except ValueError:
        print("invalid json, aborting")
        return False
    return True

        
def distance_langs(lang1, lang2):
    # calculates distance between two languages (sample input is interpreted as language on its own)
    word_freq_1 = lang1["word_freq"]
    word_freq_2 = lang2["word_freq"]
    s1 = 0.0
    for key in word_freq_1.keys():
        if key in word_freq_2:
            s1 += 3 #word_freq_2[key]*word_freq_1[key]

    score1 = s1/float(lang1["word_count"]*lang2["word_count"])

    char_freq_1 = lang1["char_freq"]
    char_freq_2 = lang2["char_freq"]
    s2 = 0.0
    for key in char_freq_1.keys():
        if key in char_freq_2:
            s2 += 1 #char_freq_2[key]*char_freq_1[key]

    score2 = s2/float(lang1["char_count"]*lang2["char_count"])

    return score1+score2

def compare_against_database(name, lang):
    # compares input language against everything in the database
    #TODO: confidence in result? (percentage - comparison to other results)
    score = []
    for key in lang_data.keys():
        score.append({"name": key, "score": distance_langs(lang_data[key], lang)})
    score.sort(key=lambda l:-l["score"])
    print(name + ":")
    for obj in score:
        print(obj["name"] + ": " + str(obj["score"]))

if __name__ == "__main__":
    res = define_langs()
    if not res:
        exit()
    input_sample = {}
    create_lang_object(input_sample, u"Ahoj, jmenuji se Vilda mám rád knihy - obzvlášť když venku prší. Guten tag, meine name ist Vilem und ich liebe bücher.")
    compare_against_database("sample", input_sample)