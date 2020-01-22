#!/usr/bin/env bash

for a in sample/*/dev.conllu; do
    echo "----------------------- $a"
    udapy -TM util.Mark \
 	node='node.upos == "ADP" and (node.precedes(node.parent) and node.feats["AdpType"] == "Post") or (not node.precedes(node.parent) and node.feats["AdpType"] in ["Prep", "Voc"])' < $a
done | tee tmp.txt

