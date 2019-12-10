# Questions on basic types of corpora
### What is a corpus?
A structured set of usually texts (there are also speech/spoken corpora)

### How can you classify corpora? Give at least three criteria.
- Monolingual/multilingual
- Chronic/diachronic (evolution, changes)
- Annotated/unannotated
- Written/spoken

### What is an annotation? What kinds of annotation do you know?
Added information (usually of linguistic focus) usually in machine readable way

### Explain terms sentence segmentation and tokenization. Give examples on non-trivial situations. lemmatization, tagging?
Sentence segmentation is the task of establishing sentence boundaries for usually texts with missing punctiation. This is common usually
in speech recognition, where the input (without further LM processing) is just a sequence of words.

Tokenization is the task of distinguishing tokens (usually words and punctuation marks) from a sequence (usually of characters). For example 
in parsing web pages the content is filled with HTML tags, but we would like to extract just a sequence of tokens (from the language).
Problematic for languages which use something vastly different that the Latin script or similar, as an explicit word separator (space) may
be missing.

### Explain what lemmatization is and why it is used.
Finding the correct (intended) lemma for a given word form. Used for disambiguation in language models.

### Explain what tagging is and why it is used.
Tagging assigns tags to word forms in a sentence. (Morphological analysis generates all possible for a given form.)

### Explain what a balanced corpus is. Why this notion is problematic?
Ideally all possible proportions correspond to the real language, but that's impossible (without having all of the language)
Usually we just focus on a single proportion, like genre

### Explain what POS tagging is and give examples of tag sets. Give examples of situations in which tagging is non-trivial even for a human.
Assigning correct POS tags to words in a sentence. For English __Penn Treebank POS tagset__ or __Negra corpus tagset__.
Lots of sentences are ambiguous. Humans have around 5% error rates.

### Explain the main sources of variability of POS tag sets accross different corpora.
Different languages work differently. VTODO

### Explain the main property of positional tag sets. Give examples of positional and non-positional tag sets.
Prague dependency treebank (PDT, positional) vs. Penn Treebank (non-positional)
Positional tags have properties, which can be filled by different symbols - lots of combinations.

### Give examples of at least three corpora (of any type). What is their size? (very roughly, order of magnitude is enough; do not forget to mention units)
Usually measured in tokens. SYNv7 (5G tokens with interp.), Brown Corpus (1MW tokens), English Gigaword (1GW) 

# Questions on parallel corpora

### What is a parallel corpus?
Two or more corpora with alignment between some units.

### What types (levels) of alignment can be present in parallel corpora?
Document, paragraph, sentence, word/node alignment.

### Give examples of situations in which document alignment can be problematic.
Given two unorganized corpora about which we know there are documents of the same content (but in different languages), then matching documents can be problematic.

### Give examples of situations in which sentence alignment can be problematic.
Very commonly in document aligned data used for MT, since one sentence can be translated into multiple sentences and vice versa.

### Give examples of situations in which node alignment can be problematic.
Generally languages aren't translated word by word, so there is almost never a clear bijection between source and target words.

### Give at least three examples of possible sources of parallel data, and for each source describe expected advantages and disadvantes.
- Books - there's plenty of them, but only usually aligned on chapter/paragraph level
- System messages/localization - usually paragraph/sentence aligned, usually lots of language pairs, very IT domain specific 
- Subtitles - widely available, phrase aligned, but usually direct speech domain
Tools: fast_align, hunalign, Giza, Giza++, IBM models

## Questions on treebanking

### Either assign Penn Treebank POS tags to words in a given English sentence (short tagset documentation of Penn Treebank tags will be available to you), or assign CNK-style morphological tags to words in a given Czech sentence (short tagset documentation will be available to you). You can choose the language.
Ok.

### Draw a dependency tree for a given Czech or English sentence.
Ok.

### Draw a phrase-structure tree for a given Czech or English sentence.
Ok.. TODO: will there be a grammar documentation?

### Name at least four treebanks and describe their main properties.
- Penn Treebank - first one
- Prague Dependency Treebank - VTODO 
- NEGRA - VTODO
- TIGER - VTODO
- BulTreebank - HPSG bulgarian 

### Describe two main types of syntactic trees used in treebanks.
Dependency and phrase-structure trees.

### What is a trace (in phrase-structure trees).
TODO:

### How do we recognize presence/absence of a dependency relation between two words (in dependency treebanking).
One is a descendant of the other. TODO: is this all?

### Give at least two examples of situations in which the "treeness assumption" on intra-sentence dependency relations is clearly violated.
TODO:

### Give at least two examples of situations (e.g. syntactic constructions) for which annotation conventions for dependency analysis must be chosen since there are multiple solutions possible that are similarly good from the common sense view.
VTODO

### Why coordination is difficult to capture in dependency trees (compared to e.g. predicate-argument structure)?
VTODO

## Universal Dependencies

### How are Universal Dependencies different from other treebanks?
The UD grammar can easily accomodate lots of languages, which makes it ideal for studying cross-language phenomena as well as writing software, that can potentially work across the whole framework.

### Describe the CoNLL-U format used in Universal Dependencies.
The file is divided up to segments for each sentence. There is a line with surface representation of the whole sentence (human readable space separated words together with punct.)
Enumeration of nodes follow. There is always an implicit `root` node with index `0`. Each node has a parent assigned (it's order). Each node also contains usually lemma, morphological
and syntactic annotation.

### When working with Universal Dependencies which tools are suitable for automatic parsing, manual annotation, querying, automatic transformations and validity checking? Name at least one tool for each task.
TODO: - like default core blocks?

## Other phenomena for which annotated corpora exist

### Explain what coreference is and how it can be annotated.
TODO:
Coreference - multiple words in a sentence/paragraph refer to the same object (denotát). Usually the first one is a noun or a proper name and the second one is a pronoun. 

### Explain what named entities are and how they can be annotated.
TODO:
A real world object, which can be denoted with a proper name.

### Explain what sentiment (in the context of NLP) is and how it can be annotated.
Identification of subjective attitudes from the text. TODO: covered only breafly, how to annotate?

## Lexical data resources
### What is WordNet? What do its nodes and edges represent?
Nodes are synsets, edges are relations (hypernyms, hyponms)
Y is hyperonym of X if every X is also Y
hyponyms vice versa

### What is EuroWordNet? How the interlinking through the hub language works?
TODO: hub language?

### What is a synset?
A group of synonyms.

### What is polysemy? Give examples.
Similar to homonymy (accidential lexical match). Generally a word or a phrase having multiple meanings. Such senses are different, but related.
Man - the humankind, or the human male

### Explain the difference between the notions of polysemy and homography. Why this distinction is non-trivial to make?
Homophones - same pronunciation
Homographs - same writing
Homographs + homophones = homonyms
See above.

### Give an example of an NLP tool/lexicon that captures inflectional morphology, explain what it can be used for and describe its main properties.
MorphoDiTa
http://ufal.mff.cuni.cz/morphodita

### Give an example of a NLP tool/lexicon that captures derivational morphology, explain what it can be used for and describe its main properties.
DeriNet, part of Universal Derivations (UDer)
https://ufal.mff.cuni.cz/derinet

### What is valency? Give an example of a data resource that captures valency and describe its main properties.
The number and types of arguments, that bind with a specific verb. Examples are intransitive, transitive and ditransitive verbs.
Moreover it distinguishes functors, such as actor, patient, effect, locative. Vallex at MFF.
TODO: Is FrameNet also a valency dictionary, or is it somewhat more general?

## Evaluation
### Give at least two examples of situations in which measuring a percentage accuracy is not adequate.
Evaluating system for tumor detection. It can easily get 99% by predicting False, but that's just because of true negatives.
Evaluating system for comma insertion. It can easily get high accuracy by predicting Not-comma, but that's just because of true negatives.

### Explain: precision, recall
Solution to the accuracy paradox/problem. TP/(TP+FP) and TP/(TP+FN)

### What is F-measure, what is it useful for?
A combination of both precision and recall. It penalizes systems with focus on only one of the two. Usually F1, but generally
Fb (recall is b times more important than precision) = (1+b) (prec * recall) / (b^2 prec + recall)

### What is k-fold cross-validation?
VTODO

### Explain BLEU (the exact formula not needed, just the main principles).
John John John John | john loves his sister Mary (100% unigram precision)
The formula is bascially a geometric mean of p1, p2, p3, p4

Unigram precision on words (actually an accuracy) = #words in both/#words in translated
Bigram precision on words (actually an accuracy) = #bigrams in both/#bigrams in translated
...


### Explain the purpose of brevity penalty in BLEU.
It's easy to cheat by translating only easily translated sentences.

TODO: - self study

### What is Labeled Attachment Score (in parsing)?
The percentage of words that are assigned both the correct syntactic head and the correct dependency label.

### What is Word Error Rate (in speech recognition)?
Computed from the Levenshtein distance between true and predicted word sequence as (#sub+#ins+#del)/total.
TODO: or is it (#sub+#ins+#del)/(#sub+#del+#cor)

### What is inter-annotator agreement? How can it be measured?
Measure of how well can two different annotators make the same decision for a certain category. Usualy the trace of
normalized confusion matrix (normalized so that it all sums to 1)

### What is Cohen's kappa?
A measure of how significant an agreement between two annotators is. Let `p_o` be observed agreement and `p_e` agreement by chance,
then `k = (p_o-p_e)/(1-p_e)`. It becomes obvious when it's drawn on a line segment.

## Questions on licensing
- In the Czech legal system, if you create an artifact, who/what protects your author's rights?
- In the Czech legal system, if you create an artifact, what should you do in order to allow an efficient protection of your author's rights?
- In the Czech legal system, if you create an artifact and you want to make it usable by anyone for free, what should you do?
- In the Czech legal system, what are the implications of attaching a copyright notice (e.g. "(C)opyright Josef Novák, 2018") compared to simply mentioning the author's name?
- What is the difference between moral and economic authors' rights? How can you transfer them to some other person/entity?
- Explain main features of GNU GPL.
- Explain main features of Creative Commons.
- There are four on-off elements defined in the Creative Commons license family (by, nc, sa, nd). Why it does not lead to 2^4=16 possible licenses?