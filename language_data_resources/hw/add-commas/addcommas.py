"""tutorial.AddCommas block template."""
from udapi.core.block import Block
import sys

# nickname = Vilda

def printE(t):
    print(t, file=sys.stderr)

class AddCommas(Block):
    """Heuristically insert nodes for missing commas."""

    def __init__(self, language='en', **kwargs):
        super().__init__(**kwargs)
        self.language = language

    # def process_tree(self, tree):
    #     printE(tree.compute_text())

    def process_node(self, node):
        if self.should_add_comma_before(node):
            comma = node.create_child(form=',', deprel='punct', upos='PUNCT')
            comma.shift_before_node(node)
        elif node.prev_node.misc['SpaceAfter'] == 'No' and node.form != '.': 
            # printE(f'> {node.prev_node.form}, {node.form} | {node.root.compute_text()}')
            pass

    def hasParentConj(self, node, leftLimit=0):
        if node.ord == 0:
            return False
        elif 'dirtyC' in node.misc:
            return False
        elif node.udeprel == 'conj' and node.ord >= leftLimit:
            node.misc['dirtyC'] = True
            return True
        elif node.ord >= leftLimit:
            val = self.hasParentConj(node.parent, leftLimit=leftLimit) 
            if val:
                node.misc['dirtyC'] = True
                return True
        return False

    def level(self, node):
        if node.ord == 0:
            return 0
        else:
            return 1 + self.level(node.parent)

    def getGovVerb(self, node):
        if node.ord == 0:
            return None
        elif node.upos == 'VERB':
            return node
        else:
            return self.getGovVerb(node.parent)

    def should_add_comma_before(self, node):
        prev_node = node.prev_node
        # commas don't start a sentence
        if prev_node is None:
            return False

        if self.language == 'en':
            if prev_node.lemma == 'however':
                if node.next_node != None:
                    return True
            if node.lemma == 'but':
                if node.next_node != None and node.ord > 1:
                    printE(f'{node.ord}: {node.root.compute_text()}')
                    return True
        if self.language == 'cs':
            if node.ord > 1:
                # 83% prec, 30% rec
                if self.hasParentConj(node, leftLimit=node.ord):
                    if node.lemma not in ['a', 'nebo', 'až'] and node.upos not in ['PUNCT', 'SYM']:
                        # printE(f'{node.lemma} -- {node.root.compute_text()}')
                        return True
                
                # terrible
                # if self.closestVerb(node.prev_node) != self.closestVerb(node):
                #     return True
                govVerb1 = self.getGovVerb(node.prev_node)
                if (govVerb1 is not None) and (not 'dirtyD' in govVerb1.misc) and govVerb1.feats['VerbForm'] != 'Inf':
                    govVerb2 = self.getGovVerb(node)
                    if (govVerb2 is not None) and (not 'dirtyD' in govVerb2.misc) and govVerb2.feats['VerbForm'] != 'Inf':
                        if govVerb1 != govVerb2:
                            govVerb1.misc['dirtyD'] = True
                            # govVerb2.misc['dirtyD'] = True
                            if node.form not in ['a'] and node.upos not in ['PUNCT', 'SYM'] and node.prev_node.lemma not in ['*', '-', ':']:
                                return True

                # 91% prec, 15% rec
                if node.upos == 'SCONJ' and node.parent.upos == 'VERB':
                    return True
                # > jednotku, propadne | Tomu, kdo nezaplatil, nebo nezaplatil včas vydraženou provozní jednotkupropadne dražební jistota.

                # if node.lemma == 'než':
                #     govVerb = self.getGovVerb(node)
                #     if govVerb != None and govVerb.ord >= node.ord and govVerb.ord - node.ord <= 5:
                #         return True
                # if node.lemma == 'tak':
                #     return True

                # 94% prec, 30% rec
                if node.lemma in ['neboť', 'zda', 'proč']:
                    return True
                if node.lemma in ['ve', 'v', 'se', 's'] and \
                     (node.next_node != None and node.next_node.lemma in ['který', 'která', 'které', 'kteří', 'kterého', 'kterých', 'kterému', 'kterým', 'kterou', 'kterým', 'kterými']):
                    return True
                if node.prev_node.lemma not in ['ve', 'v', 'se', 's'] and \
                    node.lemma in ['který', 'která', 'které', 'kteří', 'kterého', 'kterých', 'kterému', 'kterým', 'kterou', 'kterým', 'kterými']:
                    return True
                if node.lemma == 'například' and node.prev_node.lemma != 'jako' and node.prev_node.upos not in ['AUX', 'VERB']:
                    return True
                if node.lemma == 'jako' and (node.next_node != None and node.next_node.lemma == 'například'):
                    return True
                if node.form in ['co'] and node.upos in ['SCONJ', 'PRON']:
                    return True
                if node.lemma in ['aby', 'že', 'protože'] and node.upos == 'SCONJ':
                    return True
            else:
                # set the first conj to dirty
                self.hasParentConj(node, leftLimit=node.ord)
                # set the first gov verb to dirty
                # govVerb = self.getGovVerb(node)
                # if govVerb != None:
                #     govVerb.misc['dirtyD'] = True

        return False
