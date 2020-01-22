#!/usr/bin/env bash

for a in sample/*/sample.conllu; do
    printf '%50s ' $a;
    udapy -q .Wordorder < $a;
done | tee results.txt

