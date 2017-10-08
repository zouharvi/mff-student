#!/usr/bin/python
# -*- coding: utf-8 -*-

import json
from StringIO import StringIO

# command line arguments:
# -f --file
# -s --sample
# -v --verbose (show language comparison)
# -i --input

lang_data = {}
BANNED_CHARS = set(".?!<>(){}[]\"'_%*\n0123456789 ") #TODO: regex replaces
FREQ_LIMIT = 1

def process_data(data):
    # remove unwanted symbols from input
    data = data.lower()
    data_clean = ""
    prev_space = True
    for c in data:
        if not c in BANNED_CHARS:
            data_clean += c
            prev_space = False
        if c == " " and not prev_space:
            data_clean += c
            prev_space = True
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

    # calculate ratio, so that samples of different size have the same weight
    #no_words = len(words_freq_list) # TODO: divide by no_words later (after sum / for bigger precision)
    #words_ratio = []
    #for word in words_freq_list:
    #    words_ratio.append({"word": word["word"], "ratio": (word["freq"]/no_words)})    

    return words_freq_clean

def create_lang_object(object, data):
    object["word_freq"] = process_data(data)
    object["word_count"] = len(object["word_freq"])

def add_to_database(key, data):
    sample = 0
    if not key in lang_data:
        sample = lang_data[key] = {}
    else:
        sample = lang_data[key]
    create_lang_object(sample, data)  

def define_langs():
    content = open("./lang_def.json").read()
    sample_data = json.load(StringIO(content))

    lang_keys = list(sample_data.keys())
    for key in lang_keys:
        add_to_database(key, sample_data[key])
        
def distance_langs(lang1, lang2):
    word_freq_1 = lang1["word_freq"]
    word_freq_2 = lang2["word_freq"]
    s = 0.0
    for key in word_freq_1.keys():
        if key in word_freq_2:
            s += word_freq_2[key]*word_freq_1[key]

    return s/(lang1["word_count"]*lang2["word_count"])

if __name__ == "__main__":
    define_langs()
    input_sample = {}
    #create_lang_object(input_sample, u"alenka v říši divů rabbit alenka v říši divů rabbit")
    #create_lang_object(input_sample, u"Já jsem Vilda, mám rád knihy a teplý čaj - obzvlášť když venku prší. Já jsem Vilda, mám rád knihy a teplý čaj - obzvlášť když venku prší.")
    create_lang_object(input_sample, u"Hi, how are you? Hi, how are you? guten guten tag tag meine name ist vilda  meine name ist vilda dzien dobry dzien dobry alicja alicja ")
    print(distance_langs(lang_data["cs"], input_sample))
    print(distance_langs(lang_data["en"], input_sample))
    print(distance_langs(lang_data["de"], input_sample))
    print(distance_langs(lang_data["pl"], input_sample))
    #print(lang_data)