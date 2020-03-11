from features import scan

def evaluate(data, states):
    prolixState = list(zip(data.prolix, states))
    def extractProlixPrefix(wordProlix):
        out = []
        for word in wordProlix:
            prolix = prolixState.pop(0)
            if word != prolix[0]:
                raise Exception(f'Prolix "{prolix[0]}" not matching')
            out.append(prolix)
        return out

    wTP = 0
    wFP = 0
    wTN = 0
    wFN = 0
    total = 0

    for word, BOS in data.wordsBOS:
        wordProlix = scan(word)
        prolixPrefix = extractProlixPrefix(wordProlix)
        print(prolixPrefix, '|||||', wordProlix)
        assert(len(prolixPrefix) == len(wordProlix))

        # prolixPrefix[0] should be a word beginning
        if prolixPrefix[0] != 0:
            wTP += 1
        else:
            wFN += 1
        
        for _prolix, state in prolixPrefix[1:]:
            print(state)
            if state != 0:
                wFP += 1
            else:
                wTN += 1

        total += len(prolixPrefix)
    
    # wTP /= total
    # wFP /= total
    # wTN /= total
    # wFN /= total
    print('Word-level: ')
    print(f'TP: {wTP}%, FP: {wFP}%')
    print(f'FN: {wFN}%, TN: {wTN}%')

# evaluate(dataH, predictedStates)