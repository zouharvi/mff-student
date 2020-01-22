#!/usr/bin/env python3

import sys, re

def tokenize(raw):
    # separate punctuation marks
    out = re.sub(r'([\.\,\?\!\"\'\\\/])', r' \1 ', raw)
    # collapse spaces
    out = re.sub(r'\s+', r' ', out)
    # not on the ends
    out = re.sub(r'^ | $', r'', out)
    # one per each line
    out = re.sub(r' ', r'\n', out)
    # remove empty liens
    out = re.sub(r'\n+', r'\n', out)
    # to lowercase
    out = out.lower()
    return out

raw = ''
for line in sys.stdin:
    raw += line.rstrip('\n')
print(tokenize(raw))
