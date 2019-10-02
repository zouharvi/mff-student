#!/bin/bash

recur() {
	local dir=$1
	local prefix=$2
	local file
	local mid="├── "
	local pre=""
 	if [ "$3" -eq "0" ]; then
		local mid="│  "
		local pre="├── "
	fi
	local last_file=""
  	for file in "$dir"/*; do
		last_file=$file;
	done
	for file in "$dir"/*; do
		if [ "$file" == $last_file ]; then
			local pre=""
			local mid="└── "
 			if [ "$3" -eq "0" ]; then
				local mid="│  "
				local pre="└── "
			fi
		fi
		if [ -e "$file" ] || [ -L "$file" ]; then
			bas=`basename $file`
			if [ -d "$file" ]; then
    				echo "${mid}${prefix}${pre}${bas}"

 				if [ "$3" -eq "0" ]; then
    					recur "$file" "${prefix}    " "0"
				else
    					recur "$file" "${prefix} " "0"
				fi
    			else
    				echo "${mid}${prefix}${pre}${bas}"
    			fi
    		fi
  	done
}

if [ "$#" -eq "0" ]; then
	root=`pwd`
else
	root=$1
fi
echo $root 
recur $root "" "1" 
