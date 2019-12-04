"""tutorial.Parse block template.

Usage:
udapy read.Conllu zone=gold files=sample.conllu \
      read.Conllu zone=pred files=sample.conllu \
      transform.Flatten zones=pred \
      tutorial.Parse zones=pred \
      eval.Parsing gold_zone=gold \
      util.MarkDiff gold_zone=gold \
      write.TextModeTreesHtml marked_only=1 files=parse-diff.html
"""
# nickname = Vilda

from udapi.core.block import Block
from collections import Counter

uposPairs = []

def rAdjNoun(node0, node1):
    if node0.upos in {'ADJ', 'ADV'} and node1.upos in {'NOUN', 'PROPN'}:
        return 0

def rVerbAdv(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'ADJ', 'ADV'}:
        return 2
    if node1.upos in {'VERB'} and node0.upos in {'ADV'}:
        return 0

def rVerbNoun(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'NOUN', 'PRON'}:
        return 2
        
def rAdjAdj(node0, node1):
    if node0.upos in {'ADJ'} and node1.upos in {'ADJ'}:
        return 0

def rVerbVerb(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'VERB'}:
        return 2

def rNounNoun(node0, node1):
    if node0.upos in {'NOUN'} and node1.upos in {'NOUN'}:
        return 2

def rPunctNoun(node0, node1):
    if node0.upos in {'PUNCT'} and node1.upos in {'NOUN'}:
        return 0

def rAnyStop(node0, node1):
    if node1.lemma == '.':
        return 2

def rPunctAdj(node0, node1):
    if node0.upos in {'PUNCT'} and node1.upos in {'ADV'}:
        return 0

def rAdvAdj(node0, node1):
    if node0.upos in {'ADV'} and node1.upos in {'ADJ'}:
        return 0

def rPunctCconj(node0, node1):
    if node0.upos in {'PUNCT'} and node1.upos in {'CCONJ'}:
        return 2

def rAdvNum(node0, node1):
    if node0.upos in {'ADV'} and node1.upos in {'NUM'}:
        return 0
    
def rAdpNoun(node0, node1):
    if node0.upos in {'ADP'} and node1.upos in {'NOUN'}:
        return 0

def rNumNoun(node0, node1):
    if node0.upos in {'NUM'} and node1.upos in {'NOUN'}:
        return 0

def rPropnNoun(node0, node1):
    if node0.upos in {'PROPN'} and node1.upos in {'NOUN'}:
        return 0

def rNounPropn(node0, node1):
    if node0.upos in {'NOUN'} and node1.upos in {'PROPN'}:
        return 2

def rVerbPunct(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'PUNCT'}:
        return 2

def rDetVerb(node0, node1):
    if node0.upos in {'DET'} and node1.upos in {'VERB'}:
        return 0

def rCconjNoun(node0, node1):
    if node0.upos in {'CCONJ'} and node1.upos in {'NOUN'}:
        return 0

def rVerbDet(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'DET'}:
        return 2

def rDetNoun(node0, node1):
    if node0.upos in {'DET'} and node1.upos in {'NOUN'}:
        return 0

def rAuxNoun(node0, node1):
    if node0.upos in {'AUX'} and node1.upos in {'NOUN'}:
        return 0

def rVerbPart(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'PART'}:
        return 2

def rXX(node0, node1):
    if node0.upos in {'VERB'} and node1.upos in {'PART'}:
        return 2

def rDeathHangRight(node1, node2):
    # print("Used the death rule (hang right)")
    uposPairs.append((node1.upos, node2.upos))
    return 0

RULES = [
    rAnyStop,
    rVerbDet,
    rDetNoun,
    rNounPropn,
    rDetVerb,
    rCconjNoun,
    rNounNoun,
    rPunctNoun,
    rPunctCconj,
    rAdvAdj,
    rAdjNoun,
    rAdjAdj,
    rAdvNum,
    rAdpNoun,
    rVerbNoun,
    rVerbAdv,
    rVerbVerb,
    rNumNoun,
    rPropnNoun,
    rVerbPunct,
    rAuxNoun,
    rVerbPart,
    # rXX,
    rDeathHangRight,
]

def getDeprel0(node):
    if node.upos == 'NOUN':
        if node.feats['Case'] == 'Nom':
            return 'nsubj'
        if node.feats['Case'] == 'Acc':
            return 'obj'
        if node.feats['Case'] in {'Gen', 'Loc'}:
            return 'nmod'
        if node.feats['Case'] == 'Dat':
            return 'obl'
        if node.feats['Case'] == 'Ins':
            return 'obj'
    if node.upos == 'VERB':
        return 'root' # :^)

    if node.upos == 'PRON':
        if node.lemma == 'se':
            return 'expl:pv'
        else:
            return 'obl'

    SIMPLE = {
        'ADJ': 'amod', 'ADP': 'case', 'ADV': 'advmod', 'CCONJ': 'cc',
        'SCONJ': 'mark', 'DET': 'det', 'AUX': 'cop', 'NUM': 'nummod',
        'PROPN': 'nmod', 'PUNCT': 'punct'
        }
    if node.upos in SIMPLE.keys():
        return SIMPLE[node.upos]
    
    return 'UNLABELED'

class Parse(Block):
    """Dependency parsing."""

    def __init__(self, language='en', **kwargs):
        super().__init__(**kwargs)
        self.language = language

    # 0 - node0 > node1
    # 1 - node0 = node1 
    # 2 - node0 < node1 

    def after_process_document(self, doc):
        global uposPairs
        uposPairs = Counter(uposPairs)
        # print(uposPairs.most_common(10))

    def process_tree(self, root):
        for node in root.descendants:
            node.deprel = getDeprel0(node)

        stackA = root.descendants
        stackB = []

        while len(stackA) + len(stackB) != 1:
            for ruleI in range(len(RULES)):
                stackB = stackA[1:]
                stackA = stackA[:1]

                ruleF = RULES[ruleI]
                change = False
                
                while len(stackB) != 0:
                    # print(ruleI, len(stackA), len(stackB))
                    prevHead = stackA[-1]
                    nextHead = stackB[0]

                    del stackA[-1]
                    del stackB[0]
        
                    score = ruleF(prevHead, nextHead)
                    if score == 0:
                        prevHead.parent = nextHead 
                        stackA.append(nextHead)
                        change = True
                    elif score == 1 or score is None:
                        stackA.append(prevHead)
                        stackA.append(nextHead)
                    elif score == 2:
                        nextHead.parent = prevHead 
                        stackA.append(prevHead)
                        change = True
                    # print(change)

                if change:
                    break

        stackA[0].deprel = 'root'
                
    # BRAINSTORMING

    # Idea 1: recursion
    # Split by head token and recurse on the two sequences

    # Idea 2: graph based
    # For each pair of nodes we estimate a value
    # We then search for MST (maximum spanning tree for oriented) Chu-Liu-Edmonds
    # Problem: we don't have much context apart from the two nodes

    # Idea 3: transition based
    # We go left to right and use a stack + buffer
    # We compare top stack 

    # Idea 4: transition based several times
    # Levels of rules by probability

    # Final idea:
    # Build the transition based structure with some tweaks so that the only work that
    # needs to be done is to create several levels of rules.
    # Create a "death rule" and log UPOS pairs.
    # If there is some UPOS pair common, create a new rule and check if hanging left
    # or right helps (may have to try different positions).
    # This could be implemented as a greedy algorithm, but it was easier to do it all manualy.