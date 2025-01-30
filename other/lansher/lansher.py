#!/usr/bin/python3
# -*- coding: utf-8 -*-

'''
LANSHER
language distinguisher, 2017
Author: Vilém Zouhar
'''

import sys
if sys.version_info.major != 3:
    print("python 3.x is required to run this program, aborting") 
    sys.exit()

import json, re, argparse, pickle
from io import StringIO
from math import log

VERSION = "0.1.2"
VERSION_STR = "LANSHER language distinguisher " + VERSION + "\nVilém Zouhar, 2017"
HELP_STR = '''the options below may be used: (-i, -fi, -lc are mutually exclusive)
    -ld --load-database           path to compiled database
    -sv --save-database           path to target database file (will be overriden; load the databse first to merge)
    -ls --language-samples        path to json file
    -lc --language-comparison     show language comparison
    -i  --input                   string containing text to categorize
    -fi --file-input              path to text file
    -v  --version                 show program version and exit
    -h  --help                    show help and exit

full documentation and source code at <https://github.com/zouharvi/lansher>
'''

lang_data = {}
WEIGHTS = {
    "word":     200,
    "char":     1,      # use chars only if notyhing else is left
    "tuple2":   200,
    "tuple3":   200,
    "tuple4":   200
}

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
            element_freq[element] += 1
        else:
            element_freq[element] = 1
    return element_freq

def join_frequencies(freqs_1, freqs_2):
    # merge two frequency dictionaries
    freqs_merged = freqs_1    
    for key in freqs_2.keys():
        if key in freqs_merged:
            freqs_merged[key] += freqs_2[key]
        else:
            freqs_merged[key] = freqs_2[key]
    return freqs_merged

def create_tuples(n, words):
    # create all n-tuple subsequences from list of string
    tuples = []
    for element in words:
        processed = ""
        cur_length = 0
        for c in element:
            processed += c
            cur_length += 1
            if cur_length == n:
                cur_length -= 1
                tuples.append(processed)
                processed = processed[1:]
    return tuples

def join_if_available(name, object, arr_local):
    # joins two frequencies if available
    if name in object["freqs"]:
        object["freqs"][name] = join_frequencies(arr_local, object["freqs"][name]) 
    else:
        object["freqs"][name] = arr_local
    object["counts"][name] = len(object["freqs"][name])

def create_lang_object(object, data):
    if object == None:
        object = {"freqs":{}, "counts":{}}

    data_clean = clean_data(data)
    words_split = data_clean.split(" ")

    word_freq_local = element_frequency(words_split)
    join_if_available("word", object, word_freq_local)
    char_freq_local = element_frequency(data_clean.replace(" ", ""))
    join_if_available("char", object, char_freq_local)

    tuples2_freq_local = element_frequency(words_split)
    join_if_available("tuple2", object, tuples2_freq_local)
    tuples3_freq_local = element_frequency(words_split)
    join_if_available("tuple3", object, tuples3_freq_local)
    tuples4_freq_local = element_frequency(words_split)
    join_if_available("tuple4", object, tuples4_freq_local)
    return object

def add_to_database(key, data):
    # adds data to local database
    sample = 0
    if not key in lang_data:
        sample = lang_data[key] = {"freqs":{}, "counts":{}}
    else:
        sample = lang_data[key]
    create_lang_object(sample, data)  

def add_lang_file(file_name):
    # load language definition from JSON file into database
    # invalid json is checked for
    content = None
    try:
        content = open(file_name).read()
    except IOError:
        print("cannot open \"" + file_name + "\", aborting")
        sys.exit()

    try:
        sample_data = json.load(StringIO(content))
        lang_keys = list(sample_data.keys())
        for key in lang_keys:
            if not isinstance(sample_data[key], str) or len(sample_data[key]) < 1:
                raise ValueError()
            add_to_database(key, sample_data[key])
    except ValueError:
        print("invalid json, aborting")
        sys.exit()

def add_lang_database(file_name):
    # load language definition from python file into database
    # invalid data are checked for
    global lang_data
    try:
        with open(file_name, 'rb') as input:
            lang_data = pickle.load(input)
    except (IOError, pickle.UnpicklingError) as e:
        print("cannot open \"" + file_name + "\", aborting")


def save_lang_database(file_name):
    # save lang_data to file_name for future use
    try:
        with open(file_name, 'wb') as output:
            pickle.dump(lang_data, output, pickle.HIGHEST_PROTOCOL)
    except (IOError, pickle.PicklingError) as e:
        print("cannot write \"" + file_name + "\", aborting")
        
        
def distance_langs(lang2, lang1):
    # calculates distance between two languages (sample input is interpreted as language on its own)
    total_score = 0
    for type_name in lang1["freqs"]:
        if type_name in lang2["freqs"]:
            type_score = 0
            for key in lang1["freqs"][type_name].keys():
                if key in lang2["freqs"][type_name]:
                    type_score += log(lang1["freqs"][type_name][key]*lang2["freqs"][type_name][key]+1) # log(arg + 1) to allow arg = 1 
            type_score = WEIGHTS[type_name]*type_score/log(lang1["counts"][type_name]*lang2["counts"][type_name]+1)
            total_score += type_score

    return total_score

def compare_against_database(name, lang, skip=None, all=False):
    # compares input language against everything in the database (skips language if $key is $skip)
    score = []
    score_sum = 0
    for key in lang_data.keys():
        if key == skip:
            continue
        score_local = distance_langs(lang_data[key], lang)
        score_sum += score_local
        score.append({"name": key, "score": score_local})
    score.sort(key=lambda l:-l["score"])
    
    if all:
        print(name + ":")
        for obj in score:
            score_percent = 100.0*obj["score"]/score_sum
            print(obj["name"] + " (" +  "{:5.3f}".format(score_percent) + "%)")
    else:
        score_percent = 100.0*score[0]["score"]/score_sum
        print(name + ": " + score[0]["name"] + " (" +  "{:5.2f}".format(score_percent) + "%)")


# the program begins here
if __name__ == "__main__":
    parser = argparse.ArgumentParser(add_help=False, prog="LANSHER")
    parser._optionals.title = "program options"
    parser.add_argument("-v", "--version", action="store_true")
    parser.add_argument("-ld", "--load-database")
    parser.add_argument("-sd", "--save-database")
    parser.add_argument("-ls", "--language-samples")
    me_group = parser.add_mutually_exclusive_group()
    me_group.add_argument("-lc", "--language-comparison", action="store_true")
    me_group.add_argument("-i",  "--input")
    me_group.add_argument("-fi", "--file-input")
    parser.add_argument("-h", "--help", action="store_true")
    
    args = parser.parse_args()

    if args.help:
        print(HELP_STR)
        sys.exit()
    if args.version:
        print(VERSION_STR)
        sys.exit()
    if (args.input == None) and (args.file_input == None) and (args.language_comparison == None) and (args.save_database == None) and (args.load_database == None) and (args.language_samples == None):
        print("no parameters passed")
        sys.exit()

    # language database is filled here
    if args.load_database != None:
        add_lang_database(args.load_database)
    if args.language_samples != None:
        add_lang_file(args.language_samples)
    if len(lang_data) == 0: # assert database has something in it
        print("no language database loaded, aborting")
        sys.exit()

    # categorize input text (either from command line or file)
    if (args.input != None) or (args.file_input != None):
        sample_text = None
        if args.input != None:
            sample_text = args.input
        elif args.file_input != None:
            try:
                with open(args.file_input, "r") as textfile:
                    sample_text = textfile.read()
            except IOError:
                print("cannot open \"" + args.file_input + "\", aborting")
                sys.exit()
        if sample_text == None or len(sample_text) == 0:
            print("no text input, aborting")
            sys.exit()
        else:
            input_sample = create_lang_object(None, sample_text)
            compare_against_database("input text comparison", input_sample, all=True)

    # compare loaded languages
    if args.language_comparison:
        for key in lang_data.keys():
            compare_against_database(key, lang_data[key], skip=key)

    # save database to file
    if args.save_database != None:
        save_lang_database(args.save_database)
