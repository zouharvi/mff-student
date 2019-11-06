from udapi.core.block import Block

class Wordorder(Block):
    def __init__(self, **kwargs):
        """Create the Adpositions block object."""
        super().__init__(**kwargs)
        self.VSOs = []

    def process_node(self, node):
        if node.upos == "VERB":
            out = [node.ord]
            #print([node.deprel for node in node.children])
            for child in node.children:
                if 'subj' in child.deprel:
                    out.append(child.ord)
            for child in node.children:
                if 'obj' in child.deprel:
                    out.append(child.ord)
            if len(out) == 3:
                self.VSOs.append(out)

    def process_end(self):
        sov = 0
        osv = 0
        ovs = 0
        svo = 0
        vso = 0
        vos = 0
        for ordering in self.VSOs:
            v = ordering[0]
            s = ordering[1]
            o = ordering[2]
            if s < o and o < v:
                sov += 1
            if o < s and s < v:
                osv += 1
            if o < v and v < s:
                ovs += 1
            if s < v and v < o:
                svo += 1
            if v < s and s < o:
                vso += 1
            if v < o and o < s:
                vos += 1
        maxVSOs = max([sov, osv, ovs, svo, vso, vos])
        total = sum([sov, osv, ovs, svo, vso, vos])
        print(f'SOV: {sov/total:4.2f}, OSV: {osv/total:4.2f}, OVS: {ovs/total:4.2f}, SVO: {svo/total:4.2f}, VSO: {vso/total:4.2f}, VOS: {vos/total:4.2f}')
