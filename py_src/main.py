#!/usr/bin/env python3

import regex as re
import glob
import doc_reader
import data_utils

F_STOPWORDS = "./data/stopwords.txt"
G_ABSTR = "./data/hulth2003_all/*.abstr"
PRINT_RESULTS = False
CONSIDERED_RESULTS = 15
LENGTH_POWER = 0.16
DUPLICITY_SCORE = -0.8
r4 = re.compile(r"[^\p{L}]+")

def rchop(s, sub):
    return s[:-len(sub)] if s.endswith(sub) else s

def process_abstr(data, sws, f_abstr, f_uncontr):
    with open(f_abstr, 'r') as f:
        doc_raw = f.read()
    doc_words = re.split(r4, doc_raw)

    with open(f_uncontr, 'r') as f:
        uncontr_raw = f.read().replace('\n', '').replace('\t', '').replace('\r', '')
    uncontr = set(uncontr_raw.split("; "))

    candidates = data_utils.create_candidates(doc_words, sws)
    (frqs, degs) = data_utils.compute_frq_deg(candidates)

    rat = dict()
    for (key, f_val) in frqs.items():
        d_val = degs[key]
        rat[key] = d_val / f_val

    keywords = dict()

    for candidate in candidates:
        key = " ".join(candidate)
        csum = sum([rat.get(word, 0) * data.term_idf(word) for word in candidate])
        score = csum / (len(candidate) ** LENGTH_POWER)
        if key in keywords:
            csum += DUPLICITY_SCORE
        keywords[key] = score

    keyword_vec = list(keywords.items())
    keyword_vec.sort(key=lambda a: a[1], reverse=True)

    hits = 0
    if PRINT_RESULTS:
        print(f"Score  Keyword {f_abstr}")
    for n in range(CONSIDERED_RESULTS):
        if n >= len(keyword_vec):
            break
        (key, val) = keyword_vec[n]
        if key in uncontr:
            if PRINT_RESULTS:
                print(f"* {val:.3f}: {key}")
            hits += 1
        else:
            if PRINT_RESULTS:
                print(f"  {val:.3f}: {key}")
    return hits


if __name__ == '__main__':
    print(f"Opening stopwords from '{F_STOPWORDS}'")
    with open(F_STOPWORDS, 'r') as f:
        sws_raw = f.read()
    sws = set([x for x in sws_raw.split('\n')])
    data = doc_reader.DocAll(sws, G_ABSTR)

    hits = 0
    doc_count = 0
    for entry in glob.glob(G_ABSTR):
        doc_count += 1
        uncontr_path = rchop(entry, 'abstr') + 'uncontr'
        hits += process_abstr(
            data,
            sws,
            entry,
            uncontr_path,
        )
    print(f"Hit ratio: {hits/doc_count}")