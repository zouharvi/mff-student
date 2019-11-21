"""tutorial.AddArticles block template."""
# nickname = Vilda

from udapi.core.block import Block
import sys, random

def printE(t):
    print(t, file=sys.stderr)

class AddArticles(Block):
    """Heuristically insert English articles."""

    def process_node(self, node):
        if node.next_node == None:
            printE(node.root.compute_text())

        if self.add_a_before(node):
            if node.ord <= 1:
                the = node.create_child(form="A", lemma="A", upos="DET", deprel="det")
            else:
                the = node.create_child(form="a", lemma="a", upos="DET", deprel="det")
            the.shift_before_node(node)
            return

        if self.add_the_before(node):
            if node.ord <= 1 or node.prev_node == '"':
                the = node.create_child(form="The", lemma="The", upos="DET", deprel="det")
            else:
                the = node.create_child(form="the", lemma="the", upos="DET", deprel="det")
            the.shift_before_node(node)
            return
            
    def has_noun_parent_right(self, node):
        if node.ord == 0:
            return False
        elif 'dirtyC' in node.misc:
            return False
        elif node.upos == 'NOUN':
            node.misc['dirtyC'] = True
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
        

    def add_the_before(self, node):
        if node.lemma in {'this', 'that'} or node.upos in {'PRON', 'PUNCT'} or node.form[0].isupper():
            # set to dirty
            self.has_noun_parent_right(node)
            return False
        if node.upos in {'ADP', 'CCONJ'}:
            # do not set to dirty
            return False
        if self.has_noun_parent_right(node):
            return True
        return False

    def add_a_before(self, node):
        if node.form in {'few', 'lot', 'new'}:
            return True
        return False