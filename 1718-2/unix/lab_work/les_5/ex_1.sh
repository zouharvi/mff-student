#!/bin/bash

TMP=veverka
TMP2=veverka2
cp $1 $TMP
while read -r line
do
	tail -n 1 $TMP
	head -n -1 $TMP > $TMP2
	cp $TMP2 $TMP
done < $1

rm $TMP
rm $TMP2
