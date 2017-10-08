#!/usr/bin/python
# -*- coding: utf-8 -*-

import json, re, collections, time
from StringIO import StringIO

# command line arguments:
# -cd --compiled-database (path to compiled database)
# -sv --save-database (path to target database file, will be merged)
# -ld --language-definitions (path to json file)
# -lc --language-comparison (show language comparison) (mutually exclusive with -i, -fi)
# -i --input (string containing text to categorize) (mutually exclusive with -lc, -fi)
# -fi --file-input (path to text file) (mutually exclusive with -i, -lc)

lang_data = {}
FREQ_LIMIT = 1

def process_data(data):
    # remove unwanted symbols from input
    data = data.lower()
    data_clean = re.sub("[.?!<>(){}\[\]\"'_%*\n$0123456789]+", " ", data)
    data_clean = re.sub('\s+', ' ', data_clean)
    words = data_clean.split(" ")
    
    # calculate word frequency
    words_freq = {}
    for word in words:
        if word in words_freq:
            words_freq[word] += 1.0
        else:
            words_freq[word] = 1.0

    # remove underrepresented words (below FREQ_LIMIT)
    words_freq_clean = {}
    for word in words_freq.keys():
        freq = words_freq[word]
        if freq > FREQ_LIMIT:
            words_freq_clean[word] = freq

    return words_freq_clean

def create_lang_object(object, data):
    object["word_freq"] = process_data(data)
    object["word_count"] = len(object["word_freq"])
    #object["char_freq"] = ... #levenstein distance of sorted arrays?

def add_to_database(key, data):
    # adds data to local database
    sample = 0
    if not key in lang_data:
        sample = lang_data[key] = {}
    else:
        sample = lang_data[key]
    create_lang_object(sample, data)  

def define_langs():
    # 
    content = open("./lang_def.json").read()
    sample_data = json.load(StringIO(content))

    lang_keys = list(sample_data.keys())
    for key in lang_keys:
        add_to_database(key, sample_data[key])
        
def distance_langs(lang1, lang2):
    # calculates distance between two languages (sample input is interpreted as language on its own)
    word_freq_1 = lang1["word_freq"]
    word_freq_2 = lang2["word_freq"]
    s = 0.0
    for key in word_freq_1.keys():
        if key in word_freq_2:
            s += word_freq_2[key]*word_freq_1[key]

    return s/(lang1["word_count"]*lang2["word_count"])

def compare_against_database(name, lang):
    # compares input language against everything in the database
    #TODO: confidence in result? (percentage - comparison to other results)
    score = []
    for key in lang_data.keys():
        score.append({"name": key, "score": distance_langs(lang_data[key], lang)})
    score.sort(key=lambda l:-l["score"])
    print("closest lang to " + name + " is " + score[0]["name"])

if __name__ == "__main__":
    define_langs()
    input_sample = {}
    create_lang_object(input_sample, u"What is   [ your 5 5name?] ${ What is 6your name?") #TODO: parametrize create lang object, so that boundary doesn't apply, or make it dynamic
    compare_against_database("sample", input_sample)
    compare_against_database("pl", lang_data["pl"])