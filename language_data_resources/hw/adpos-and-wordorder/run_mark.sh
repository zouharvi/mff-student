#!/usr/bin/env bash

for a in sample/*/sample.conllu; do
    printf '%50s ' $a;
    udapy -q \
    util.Eval node='node.misc = ""' \
    util.Mark node='node.upos != "ADP" and node.feats["AdpType"] in ["Post", "Voc", "Prep"]' \
    write.TextModeTrees attributes='form,upos,feats,misc' marked_only=1 color=1 < $a
done | tee results.txt

