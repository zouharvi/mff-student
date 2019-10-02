#!/bin/bash

if [ $# -eq 0 ]; then
	for file in rfc-*.txt; do
		if [ $file != "rfc-*.txt" ]; then
			file2=`echo $file | sed -e "s/^rfc-\([0-9]*\).txt/\1/"`
			if grep $file2 rfc-loc > /dev/null; then
				:
			else
				echo "$file2 not found in rfc-loc"
				echo "To remove file, press enter. To add to section, write the section name and press enter."
				read section
				if [ "$section" = "" ]; then
					rm $file
				else
					if grep "\-\-\-\-\- $section:" rfc-loc > /dev/null; then
						index=`grep -n "\-\-\-\-\- $section:" rfc-loc | cut -d: -f1`
						index_p=$((index + 1))
						head -n $index rfc-loc > "$$-tmp"
						echo "$file2" >> "$$-tmp"
						echo $index_p
						tail -n "+$index_p" rfc-loc >> "$$-tmp" 
						mv "$$-tmp" rfc-loc
					else
						echo -e "----- $section:\n$file2" >> rfc-loc 
					fi
				fi
			fi
		fi
	done 
fi
