"""tutorial.AddCommas block template."""
from udapi.core.block import Block
import sys, random

# nickname = Vilda

def printE(t):
    print(t, file=sys.stderr)

class AddCommas(Block):
    """Heuristically insert nodes for missing commas."""

    def __init__(self, language='en', **kwargs):
        super().__init__(**kwargs)
        self.language = language

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

        if self.language == 'cs':
            if node.ord > 1:
                # 83% prec, 30% rec
                if self.hasParentConj(node, leftLimit=node.ord):
                    if node.lemma not in ['a', 'nebo', 'až'] and node.upos not in ['PUNCT', 'SYM']:
                        # printE(f'{node.lemma} -- {node.root.compute_text()}')
                        return True
                
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

                # 94% prec, 30% rec
                if node.lemma in ['neboť', 'zda', 'proč']:
                    return True
                if node.upos == 'ADP' and (node.next_node != None and (node.next_node.feats['PronType'] == 'Rel' or node.next_node.lemma == 'který')):
                    return True
                if node.prev_node.upos != 'ADP' and (node.feats['PronType'] == 'Rel' or node.lemma == 'který'):
                    return True
                if node.lemma == 'například' and node.prev_node.lemma not in ['jako', 'že'] and node.prev_node.upos not in ['AUX', 'VERB']:
                    return True
                if node.lemma in ['jako', 'že'] and (node.next_node != None and node.next_node.lemma == 'například'):
                    return True
                if node.form in ['co'] and node.upos in ['SCONJ', 'PRON']:
                    return True
                if node.lemma in ['aby', 'že', 'protože'] and node.upos == 'SCONJ':
                    return True

                return False
            else:
                # set the first conj to dirty
                self.hasParentConj(node, leftLimit=node.ord)
                return False

        elif self.language == 'en':
            EPSILON = 150
            COMMAS_YES = 1594+EPSILON
            COMMAS_ALL  = 38186
            return random.random() < COMMAS_YES/COMMAS_ALL
        elif self.language == 'fr':
            EPSILON = 5
            COMMAS_YES = 83+EPSILON
            COMMAS_ALL  = 2294
            return random.random() < COMMAS_YES/COMMAS_ALL