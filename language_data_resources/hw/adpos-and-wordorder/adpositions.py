"""tutorial.Adpositions block template.

Example usage::

 for a in */sample.conllu; do
    printf '%50s ' $a;
    udapy tutorial.Adpositions < $a;
 done | tee results.txt

 # What are the English postpositions?
 cat UD_English/sample.conllu | udapy -TM util.Mark \
   node='node.upos == "ADP" and node.parent.precedes(node)' | less -R
"""
from udapi.core.block import Block


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
            else: 
                self.postpositions += 1
                if node.feats['AdpType'] in ['Prep', 'Voc']:
                    self.disagreement += 1

    def process_end(self):
        total = self.prepositions + self.postpositions or 1
        prep = 100 * self.prepositions / total
        post = 100 * self.postpositions / total
        print(f'prepositions {prep:.2f}, postpositions {post:.2f}, count disagreement {self.disagreement}')

