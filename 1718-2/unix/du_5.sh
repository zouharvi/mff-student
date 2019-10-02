#!/bin/bash

# $1 - prefix
# $2 - suffix
function prefix_suffix() {
	# piping to functions! also cool
	while read -r line
	do
		echo "${1}$line${2}"
	done 
}

# $1 - original file name
# $2 - file line to search in
# $3 - line_number
# $4 - word to search for
# $5 - true for words, false for parts 
# $6 - true for case sensitive, false for case insensitive
function find_words_in_line_file() {
	# could be made simpler using xargs, but too lazy
	if [ $5 == true ]; then
		if [ $6 == true ]; then
			grep "$2" -e "$4" -n -x | prefix_suffix "$1:$3:" "" 
		else
			grep "$2" -e "$4" -n -x -i | prefix_suffix "$1:$3:" "" 
		fi
	else
		if [ $6 == true ]; then
			grep "$2" -e "$4" -n | prefix_suffix "$1:$3:" "" 
		else
			grep "$2" -e "$4" -n -i | prefix_suffix "$1:$3:" "" 
		fi
	fi
}

L_TMP="temporary-`date -Iseconds`"
mkdir $L_TMP
cd $L_TMP

touch files_to_search words_case_on words_case_off parts_case_on parts_case_off 

SEPARATORS=""
SEPARATORS_DEFAULT=true
for (( j=1; j< ($#); j++ )); do
    K=$(( j+1 )) 
    cv=${!j}
    nv=${!K}

    if [ "$cv" == '-i' ]; then
    	echo "$nv" >> files_to_search
    elif [ "$cv" == '-w' ]; then
    	echo "$nv" >> words_case_on 
    elif [ "$cv" == '-W' ]; then
    	echo "$nv" >> words_case_off 
    elif [ "$cv" == '-p' ]; then
    	echo "$nv" >> parts_case_on 
    elif [ "$cv" == '-P' ]; then
    	echo "$nv" >> parts_case_off 
    elif [ "$cv" == '-d' ]; then
	SEPARATORS_DEFAULT=false
	SEPARATORS="$SEPARATORS$nv" 
    fi
done

if [ $SEPARATORS_DEFAULT = true ]; then
	SEPARATORS=" "
fi

while read -r file 
do
	LINE_NO=0
	while read -r line 
	do
		LINE_FILE="line_no_$LINE_NO"
		touch "line_no_$LINE_NO"
		LINE_NO=$(( LINE_NO+1 ))

		#the squeeze option is so cool! 
		echo $line | tr -s "$SEPARATORS" "\n" > "$LINE_FILE"

		while read -r word 
		do
			find_words_in_line_file "$file" "$LINE_FILE" "$LINE_NO" "$word" true true
		done < words_case_on
		while read -r word 
		do
			find_words_in_line_file "$file" "$LINE_FILE" "$LINE_NO" "$word" true false 
		done < words_case_off
		while read -r word 
		do
			find_words_in_line_file "$file" "$LINE_FILE" "$LINE_NO" "$word" false false 
		done < parts_case_off
		while read -r word 
		do
			find_words_in_line_file "$file" "$LINE_FILE" "$LINE_NO" "$word" false true 
		done < parts_case_on
	done < "../$file"
done < files_to_search

cd ../
rm -Rf $L_TMP 
