#!/bin/sh
echo "" >./hmm0/hmmdefs #
head -n 3 ./hmm0/proto > ./hmm0/macros
cat ./hmm0/vFloors >> ./hmm0/macros
for w  in `cat ./textual/monophones0`
do
 cat ./hmm0/proto | sed "s/proto/$w/g"|sed "1 d"|sed "1 d"|sed "1 d" >> ./hmm0/hmmdefs
done
