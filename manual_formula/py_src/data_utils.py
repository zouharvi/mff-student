import regex as re

def compute_frq_deg(candidates):
    frq_map = dict()
    deg_map = dict() 

    for cset in candidates:
        for w1 in cset:
            if w1 not in frq_map:
                frq_map[w1] = 0
            frq_map[w1] += 1

            if w1 not in deg_map:
                deg_map[w1] = set()

            for w2 in cset:
                deg_map[w1].add(w2)

    deg = {x:len(v) for x,v in deg_map.items() }

    return (frq_map, deg)


r2 = re.compile(r".*ed")
def word_heuristics(candidate):
    return re.match(r2, candidate[-1]) or len(candidate[0]) <= 3

r3 = re.compile(r"\p{Lu}.+")
def create_candidates(words, sws):
    buffer = []
    candidates = []

    for word in words:
        if word.lower() in sws:
            if len(buffer) != 0:
                if not word_heuristics(buffer):
                    candidates.append(buffer)
                buffer = []
        elif re.match(r3, word): 
            if len(buffer) != 0:
                if not word_heuristics(buffer):
                    candidates.append(buffer)
                buffer = []
            buffer.append(word.lower())
        else:
            buffer.append(word.lower())

    return candidates
