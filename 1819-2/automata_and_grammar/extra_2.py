#!/bin/env python3

from nltk.parse.generate import generate
from nltk import CFG

grammar1 = CFG.fromstring("""
S -> S 'a' S 'a' S 'b'
S -> S 'a' S 'b' S 'a'
S -> S 'b' S 'a' S 'a'
S -> 
""")
grammar2 = CFG.fromstring("""
S -> 'aab' S|'aa' S 'b'|'a' S 'ab'|S 'aab'
S -> 'aba' S|'ab' S 'a'|'a' S 'ba'|S 'aba'
S -> 'baa' S|'ba' S 'a'|'b' S 'aa'|S 'baa'
S -> 
""")

D = 3
words1 = set([''.join(x) for x in list(generate(grammar1, depth=D))])
words2 = set([''.join(x) for x in list(generate(grammar2, depth=(2*D)))])

diff = words1.difference(words2)

print(diff)
