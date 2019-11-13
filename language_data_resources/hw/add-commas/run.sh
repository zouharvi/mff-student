#!/usr/bin/env bash

cd sample
cp UD_English/dev.conllu gold.conllu
cat gold.conllu | udapy -s \
  util.Eval node='if node.form==",": node.remove(children="rehang")' \
  > without.conllu

cd ..
# substitute the next line with your solution
cat sample/without.conllu | udapy -s .AddCommas language=en > pred.conllu

# evaluate
udapy \
  read.Conllu files=sample/gold.conllu zone=en_gold \
  read.Conllu files=pred.conllu zone=en_pred \
  eval.F1 gold_zone=en_gold focus=,
 
