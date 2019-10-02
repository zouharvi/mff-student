#!/bin/bash

var=0
touch "$$tmp"
while read line; do
	let "var=var+1"
	no_words=`echo "$line" | wc -w`
	real_rot=$(($var % $no_words))
	#echo "$var/$real_rot: $line";
	echo $line | tr ' ' '\n' > "$$tmp"
	cat "$$tmp" | head -n $real_rot >> "$$tmp"
	cat "$$tmp" | tail -n $no_words | tr '\n' ' '
	echo ""
done

rm "$$tmp"
