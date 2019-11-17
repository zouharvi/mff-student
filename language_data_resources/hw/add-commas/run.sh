#!/usr/bin/env bash

cd sample
cp UD_Czech/train.conllu gold.conllu
cat gold.conllu | udapy -q -s \
  util.Eval node='if node.form==",": node.remove(children="rehang")' \
  > without.conllu

cd ..
# substitute the next line with your solution
cat sample/without.conllu | udapy -s .AddCommas language=cs > pred.conllu
# cat pred.conllu | udapy -s .AddCommas language=cs > pred2.conllu

# evaluate
udapy -q \
  read.Conllu files=sample/gold.conllu zone=en_gold \
  read.Conllu files=pred.conllu zone=en_pred \
  eval.F1 gold_zone=en_gold focus=,
 
