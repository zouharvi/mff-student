import regex as re
from math import log
import glob

r1 = re.compile(r"[^\p{L}]")

class DocAll:
    def __init__(self, sws, g_abstr):
        self.data = dict()
        self.no_documents = 0

        for entry in glob.glob(g_abstr):
            self.no_documents += 1
            with open(entry, 'r') as f:
                text = f.read().lower()
            cset = set([x for x in re.split(r1, text) if not x in sws])

            for word in cset:
                if not word in self.data:
                    self.data[word] = 0
                self.data[word] += 1

    def term_idf(self, term):
        total = self.data.get(term, 1)
        return log(self.no_documents, 10.0) / total