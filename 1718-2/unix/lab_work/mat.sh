#!/bin/bash

# filename passed as $1 argument

no_words=`cat $1 | head -n 1 | wc -w`
no_lines=`cat $1 | wc -l`

column_files=""
for i in $(seq 1 $no_words); do # promin
	cut $1 -d" " -f$i | sort -g >> "$$a$i"
	column_files="$column_files $$a$i"
done
#echo $column_files | xargs paste -d" "
paste -d" " $column_files
#echo $column_files | xargs rm
rm $column_files
