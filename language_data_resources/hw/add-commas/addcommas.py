"""tutorial.AddCommas block template."""
from udapi.core.block import Block
import sys

# nickname = Vilda

class AddCommas(Block):
    """Heuristically insert nodes for missing commas."""

    def __init__(self, language='en', **kwargs):
        super().__init__(**kwargs)
        self.language = language

    def process_node(self, node):
        # TODO: Your task: implement some heuristics
        if self.should_add_comma_before(node):
            comma = node.create_child(form=',', deprel='punct', upos='PUNCT')
            comma.shift_before_node(node)

    def should_add_comma_before(self, node):
        prev_node = node.prev_node
        # commas don't start a sentence
        if prev_node is None:
            return False

        # manual for however
        if self.language == 'en' and prev_node.lemma == 'however':
            if node.next_node != None:
                print(prev_node.compute_text() + " | " + node.compute_text() + " | " + node.next_node.compute_text(), file=sys.stderr)
                return True

        #print(node.deprel, file=sys.stderr)
       
        if node.lemma in ['the']:
            if any(n.deprel in ['appos'] for n in prev_node.children):
                print(prev_node.compute_text() + ' | ' + node.compute_text(), file=sys.stderr)
                return True

        return False
