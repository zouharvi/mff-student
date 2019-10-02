#!/bin/bash

i=`head -n 1 $1`
while read line; do
	if [ $i -gt $line ]; then
		exit 1;
	else
		i=$line;
	fi
done < $1;
exit 0;
