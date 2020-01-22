from udapi.core.block import Block
import sys

class Adpositions(Block):
    """Compute the number of prepositions and postpositions."""

    def __init__(self, **kwargs):
        """Create the Adpositions block object."""
        super().__init__(**kwargs)
        self.prepositions = 0
        self.postpositions = 0
        self.disagreement = 0

    def process_node(self, node):
        if node.upos == "ADP":
            if node.ord < node.parent.ord:
                self.prepositions += 1
                if node.feats['AdpType'] == 'Post':
                    self.disagreement += 1
                    print(f'Post: {node.root.compute_text()}', file=sys.stderr)
            else: 
                self.postpositions += 1
                if node.feats['AdpType'] in ['Prep', 'Voc']:
                    self.disagreement += 1
                    print(f'Prep/Voc: {node.root.compute_text()}', file=sys.stderr)

    def process_end(self):
        total = self.prepositions + self.postpositions or 1
        prep = 100 * self.prepositions / total
        post = 100 * self.postpositions / total
        print(f'prepositions {prep:6.2f}, postpositions {post:6.2f}, count disagreement {self.disagreement}')
