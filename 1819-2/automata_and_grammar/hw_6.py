#!/bin/env python3

from nltk.parse.generate import generate
from nltk import CFG

grammar1 = CFG.fromstring("""
S -> 'b' A | 'a' B
A -> 'a' | 'a' S | 'b' A A
B -> 'b' | 'b' S | 'a' B B
""")

grammar2 = CFG.fromstring("""
S -> 'b' A S | 'a' B S | 'b' A | 'a' B
A -> 'a' | 'b' A A
B -> 'b' | 'a' B B
""")

grammar3 = CFG.fromstring("""
S -> 'b' A | 'a' B
A -> 'a' | 'b' A A
B -> 'b' | 'a' B B
""")

D = 7
#words1 = set([''.join(x) for x in list(generate(grammar1, depth=D))])
words2 = set([''.join(x) for x in list(generate(grammar2, depth=D))])
words3 = set([''.join(x) for x in list(generate(grammar3, depth=D))])

diff = words2.difference(words3)
