from udapi.core.block import Block
import sys, random

class NounClusters(Block):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def condA1(self, node):
        return node.prev_node.parent == node
    def condA2(self, node):
       return node.upos == 'NOUN' and node.prev_node.upos == 'NOUN' 
    def condA3(self, node):
        return (node.feats['Case'] == '') or node.prev_node.feats['Case'] == '' or (node.feats['Case'] != node.prev_node.feats['Case'])

    def condB1(self, node):
        return node.upos == 'NOUN' and node.feats['Case'] == ''

    def condC1(self, node):
        return (node.feats['Case'] != node.parent.feats['Case']) or (node.feats['Case'] == '' and node.parent.feats['Case'])
    def condC2(self, node):
        return node.ord < node.parent.ord
    def condC3(self, node):
       return node.upos == 'NOUN' and node.parent.upos == 'NOUN' 

    def process_node(self, node):
        if True and self.condC1(node) and self.condC2(node) and self.condC3(node):
            print(f'\n{node.form} {node.parent.form}')
            print(node.root.compute_text())
        elif False and node.prev_node != None and self.condA1(node) and self.condA2(node) and self.condA3(node):
            print(f'\n{node.prev_node.form} {node.form}')
            print(node.root.compute_text())
        elif False and self.condB1(node):
            print(f'\n{node.prev_node.form} {node.form}')
            print(node.root.compute_text())
