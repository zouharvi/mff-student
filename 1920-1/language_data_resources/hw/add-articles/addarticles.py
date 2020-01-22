"""tutorial.AddArticles block template."""
# nickname = Vilda

from udapi.core.block import Block
import sys, random

def printE(t):
    print(t, file=sys.stderr)

class AddArticles(Block):
    """Heuristically insert English articles."""

    def process_node(self, node):
        # if node.next_node == None:
        #     printE(node.root.compute_text())

        if self.add_a_before(node):
            if node.ord <= 1:
                the = node.create_child(form="A", lemma="A", upos="DET", deprel="det")
            else:
                the = node.create_child(form="a", lemma="a", upos="DET", deprel="det")
            the.shift_before_node(node)

            return

        if self.add_the_before(node):
            if self.capizalize_the(node):
                the = node.create_child(form="The", lemma="The", upos="DET", deprel="det")
            else:
                the = node.create_child(form="the", lemma="the", upos="DET", deprel="det")
            the.shift_before_node(node)
            
            # remove duplicit DET
            if the.prev_node != None and the.prev_node.prev_node != None:
                prevThe = the.prev_node.prev_node
                if prevThe.lemma.lower() in {'the'}:
                    prevThe.remove(children='rehang')
            return
            
    def has_noun_parent_right(self, node):
        if node.ord == 0:
            return False
        elif 'dirtyC' in node.misc:
            return False
        elif node.upos == 'NOUN':
            node.misc['dirtyC'] = True
            # > the car bomb
            if node.parent.upos == 'NOUN':
                node.parent.misc['dirtyC'] = True
                return True
            else:
                return True
        elif node.ord < node.parent.ord:
            val = self.has_noun_parent_right(node.parent) 
            if val:
                self.dirty_parent_right(node)
                node.misc['dirtyC'] = True
                return True
        return False

    def dirty_parent_right(self, node):
        if node.ord == 0:
            return
        else:
            node.misc['dirtyC'] = True
            if node.ord < node.parent.ord:
                self.dirty_parent_right(node.parent)
    
    def capizalize_the(self, node):
        if node.ord <= 1 or node.prev_node == '"':
            return True
        # if node.form[0].isupper():
        #     return True
        return False

    def add_the_before(self, node):
        # possesive handling
        if node.form in {"'s"}: 
            self.has_noun_parent_right(node.prev_node.parent) # set to dirty
            return False
        if node.upos == 'DET' \
            or (node.prev_node != None and node.prev_node.feats['Poss'] == 'Yes') \
            or node.upos in {'PRON', 'PUNCT', 'NUM'} \
            or (node.ord <= 3 and node.form[0].isupper()) \
            or node.form in {'years'} \
            or (node.prev_node != None and node.lemma in {'be'}) \
            or (node.prev_node != None and node.upos in {'ADV', 'CCONJ'}):
            self.has_noun_parent_right(node) # set to dirty
            return False
        if node.upos in {'ADP', 'CCONJ'}:
            # do not set to dirty
            return False
        if self.has_noun_parent_right(node):
            return True
        return False

    def add_a_before(self, node):
        if node.form in {'few', 'lot', 'new', 'small', 'large', 'couple', 'number', 'very'} \
            or node.form in {'great'} and node.next_node != None and node.next_node.next_node != None:
            self.has_noun_parent_right(node) # set to dirty
            return True
        return False