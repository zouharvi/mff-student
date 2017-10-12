#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
LAnguage DISTInctor, 2017
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
# -v --version
# -h --help

#TODO: check if code is executed with Python3

lang_data = {}
WORD_CHAR_RATIO = 100

def clean_data(data):
    # remove unwanted symbols from input
    data = data.lower()
    data = re.sub("[.?!<>(){}\[\]\"'_%*\n$0123456789\-]+", " ", data)
    data = re.sub("\s+", " ", data) # merge consecutive spaces into one
    data = re.sub("\s+$", "", data) # remove trailing space
    data = re.sub("^\s+", "", data) # remove leading space
    return data


def element_frequency(elements):
    # calculate element frequency is array (words in list and chars in string)
    element_freq = {}
    for element in elements:
        if element in element_freq:
            element_freq[element] += 1.0
        else:
            element_freq[element] = 1.0
    return element_freq

def create_lang_object(object, data):
    data_clean = clean_data(data)
    object["word_freq"] = element_frequency(data_clean.split(" "))
    
    word_count = 0
    for value in object["word_freq"].values():
        word_count += value 
    object["word_count"] = word_count
    object["char_freq"] = element_frequency(data_clean.replace(" ", ""))

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
            s1 += log(word_freq_2[key]*word_freq_1[key])


    char_freq_1 = lang1["char_freq"]
    char_freq_2 = lang2["char_freq"]
    s2 = 0.0
    for key in char_freq_1.keys():
        if key in char_freq_2:
            s2 += log(char_freq_2[key]*char_freq_1[key]+1)


    score1 = WORD_CHAR_RATIO*10*s1/float(lang1["word_count"]*lang2["word_count"])
    score2 =                 10*s2/float(lang1["char_count"]*lang2["char_count"])

    return (score1+score2)

def compare_against_database(name, lang):
    # compares input language against everything in the database
    score = []
    score_sum = 0
    for key in lang_data.keys():
        score_local = distance_langs(lang_data[key], lang)
        score_sum += score_local
        score.append({"name": key, "score": score_local})
    score.sort(key=lambda l:-l["score"])
    print(name + ":")
    
    for obj in score:
        print(obj["name"] + ": " + str(100.0*obj["score"]/score_sum))

if __name__ == "__main__":
    res = define_langs()
    if not res:
        exit()
    input_sample = {}
    create_lang_object(input_sample, u"Steh' auf und lebe, geh' neue Wege. Schau' nach vorn, nichts ist verlor'n.")
    compare_against_database("sample", input_sample)
