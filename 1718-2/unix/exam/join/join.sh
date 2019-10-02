#!/bin/bash


SEPARATOR="	"
A_CMP=1
B_CMP=1
FILE_A=""
FILE_B=""
while [ $# -ne 0 ]; do
	if [ $1 = '-t' ]; then
		SEPARATOR="$1"
		shift 1
	elif [ $1 = '-1' ]; then
		A_CMP="$1"
		shift 1
	elif [ $1 = '-2' ]; then
		B_CMP="$1"
		shift 1
	elif [ "$FILE_A" = "" ]; then
		FILE_A=$1
	else
		FILE_B=$1
	fi
	shift 1
done

LINE_B=1
function next_b_line {
	head -n $LINE_B $FILE_B | tail -n 1
} 

function inc_b_line {
	LINE_B=$((LINE_B + 1))
}


while read line; do
	key_a=`echo $line | cut -d"$SEPARATOR" -f"$A_CMP"` 
	while true; do
		key_b=`next_b_line | cut -d"$SEPARATOR" -f"$B_CMP"` 
		if [ key_a != key_b ]; then
			break
		fi
		
		echo -e "$line$SEPARATOR"
		next_b_line
		inc_b_line
	done
done < $FILE_A 
