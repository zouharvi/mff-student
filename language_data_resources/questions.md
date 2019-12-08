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
Different languages work differently. TODO

### Explain the main property of positional tag sets. Give examples of positional and non-positional tag sets.
Prague dependency treebank (PDT, positional) vs. Penn Treebank (non-positional)
Positional tags have properties, which can be filled by different symbols - lots of combinations.

### Give examples of at least three corpora (of any type). What is their size? (very roughly, order of magnitude is enough; do not forget to mention units)
Usually measured in tokens. SYNv7 (5G tokens with interp.), Brown Corpus (1MW tokens), English Gigaword (1GW) 

# Questions on parallel corpora
### What is a parallel corpus?


- What types (levels) of alignment can be present in parallel corpora?
- Give examples of situations in which document alignment can be problematic.
- Give examples of situations in which sentence alignment can be problematic.
- Give examples of situations in which node alignment can be problematic.
- Give at least three examples of possible sources of parallel data, and for each source describe expected advantages and disadvantes.

## Questions on treebanking
- Either assign Penn Treebank POS tags to words in a given English sentence (short tagset documentation of Penn Treebank tags will be available to you), or assign CNK-style morphological tags to words in a given Czech sentence (short tagset documentation will be available to you). You can choose the language.
- Draw a dependency tree for a given Czech or English sentence.
- Draw a phrase-structure tree for a given Czech or English sentence.
- Name at least four treebanks and describe their main properties.
- Describe two main types of syntactic trees used in treebanks.
- What is a trace (in phrase-structure trees).
- How do we recognize presence/absence of a dependency relation between two words (in dependency treebanking).
- Give at least two examples of situations in which the "treeness assumption" on intra-sentence dependency relations is clearly violated.
- Give at least two examples of situations (e.g. syntactic constructions) for which annotation conventions for dependency analysis must be chosen since there are multiple solutions possible that are similarly good from the common sense view.
- Why coordination is difficult to capture in dependency trees (compared to e.g. predicate-argument structure)?

## Universal Dependencies
- How are Universal Dependencies different from other treebanks?
- Describe the CoNLL-U format used in Universal Dependencies.
- When working with Universal Dependencies which tools are suitable for automatic parsing, manual annotation, querying, automatic transformations and validity checking? Name at least one tool for each task.

## Other phenomena for which annotated corpora exist
- Explain what coreference is and how it can be annotated.
- Explain what named entities are and how they can be annotated.
- Explain what sentiment (in the context of NLP) is and how it can be annotated.

## Lexical data resources
- What is WordNet? What do its nodes and edges represent?
- What is EuroWordNet? How the interlinking through the hub language works?
- What is a synset?
- What is polysemy? Give examples.
- Explain the difference between the notions of polysemy and homography. Why this distinction is non-trivial to make?
- Give an example of an NLP tool/lexicon that captures inflectional morphology, explain what it can be used for and describe its main properties.
- Give an example of a NLP tool/lexicon that captures derivational morphology, explain what it can be used for and describe its main properties.
- What is valency? Give an example of a data resource that captures valency and describe its main properties.

## Evaluation
- Give at least two examples of situations in which measuring a percentage accuracy is not adequate.
- Explain: precision, recall
- What is F-measure, what is it useful for?
- What is k-fold cross-validation ?
- Explain BLEU (the exact formula not needed, just the main principles).
- Explain the purpose of brevity penalty in BLEU.
- What is Labeled Attachment Score (in parsing)?
- What is Word Error Rate (in speech recognition)?
- What is inter-annotator agreement? How can it be measured?
- What is Cohen's kappa?

## Questions on licensing
- In the Czech legal system, if you create an artifact, who/what protects your author's rights?
- In the Czech legal system, if you create an artifact, what should you do in order to allow an efficient protection of your author's rights?
- In the Czech legal system, if you create an artifact and you want to make it usable by anyone for free, what should you do?
- In the Czech legal system, what are the implications of attaching a copyright notice (e.g. "(C)opyright Josef Novák, 2018") compared to simply mentioning the author's name?
- What is the difference between moral and economic authors' rights? How can you transfer them to some other person/entity?
- Explain main features of GNU GPL.
- Explain main features of Creative Commons.
- There are four on-off elements defined in the Creative Commons license family (by, nc, sa, nd). Why it does not lead to 2^4=16 possible licenses?
