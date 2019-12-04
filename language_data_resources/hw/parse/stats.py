
from udapi.core.block import Block
from collections import Counter

class Stats(Block):
    """Dependency parsing."""

    def __init__(self, language='en', **kwargs):
        super().__init__(**kwargs)
        self.language = language
        self.stats0 = []
        self.stats1 = []

    def after_process_document(self, doc):
        self.stats0 = Counter(self.stats0)
        print(self.stats0.most_common())
        print('--')
        self.stats1 = Counter(self.stats1)
        print(self.stats1.most_common(10))

    def process_tree(self, root):
        for node in root.descendants:
            self.stats0.append((node.upos, node.deprel))
            self.stats1.append((node.lemma, node.deprel))