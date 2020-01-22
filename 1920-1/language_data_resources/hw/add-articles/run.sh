#!/usr/bin/env bash

cd sample
cp UD_English/train.conllu gold.conllu
cat gold.conllu | udapy -q -s \
  util.Eval node='if node.upos=="DET" and node.lemma in {"a", "the"}: node.remove(children="rehang")' \
  > without.conllu

cd ..
# substitute the next line with your solution
cat sample/without.conllu | udapy -s .AddArticles > pred.conllu

# evaluate
udapy -q \
  read.Conllu files=sample/gold.conllu zone=en_gold \
  read.Conllu files=pred.conllu zone=en_pred \
  eval.F1 gold_zone=en_gold focus='(?i)an?|the'

# cat train.conllu | grep -E '^# text = ' | sed 's/# text = //g' > train.txt