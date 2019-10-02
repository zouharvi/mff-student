#!/bin/bash

while read -r line
do
	IFS=' ' read -r -a array <<< "$line"
	sum=$(( 0 ))
	for element in "${array[@]}"
	do
		sum=$(( $sum + $element ))
	done
	echo "$line $sum"
done < $1

