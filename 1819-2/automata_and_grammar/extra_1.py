#!/bin/env python3

import random
import itertools

def check_proper(a):
    return 2*a.count('a') == a.count('b')

rep_strings = list(itertools.permutations(['a', 'a', 'b', 'S'])

def generate_fuzzy(ob, depth=3):
    if depth <= 0:
        return ob

    for o in ob:
            
    for rep_string in rep_strings:
        ob = ob.union(generate_fuzzy(set(ob), depth-1))
    for replacable in [i for i, x in enumerate(ob) if x == 'S']:


ob = generate_fuzzy(set(['S']))
