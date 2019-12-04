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

def ruleAdjNoun0(node0, node1):
    if node0.upos in {'ADJ', 'ADV'} and node1.upos == 'NOUN':
        return 0
    if node1.upos in {'ADJ', 'ADV'} and node0.upos == 'NOUN':
        return 2
    return 0
        
def ruleAdjAdj0(node0, node1):
    if node0.upos in {'ADJ'} and node1.upos in {'ADJ'}:
        return 0
    return 2

RULES = [
    ruleAdjNoun0,
    ruleAdjAdj0,
]

class Parse(Block):
    """Dependency parsing."""

    def __init__(self, language='en', **kwargs):
        super().__init__(**kwargs)
        self.language = language

    # 0 - node0 > node1
    # 1 - node0 = node1 
    # 2 - node0 < node1 

    def process_tree(self, root):
        stackA = []
        stackB = []
        for node in root.descendants:
            stackA = [root.descendants[0]]
            stackB = root.descendants[1:]

        while len(stackA) + len(stackB) != 1:
            # pass 1
            while len(stackB) != 0:
                prevHead = stackA[-1]
                nextHead = stackB[0]
                del stackA[-1]
                del stackB[0]
    
                score = ruleAdjNoun0(prevHead, nextHead)
                if score == 0:
                    prevHead.parent = nextHead 
                    stackA.append(nextHead)
                elif score == 1:
                    stackA.append(prevHead)
                    stackA.append(nextHead)
                elif score == 2:
                    nextHead.parent = prevHead 
                    stackA.append(prevHead)
            break

        stackA[0].deprel = 'root'
                
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
