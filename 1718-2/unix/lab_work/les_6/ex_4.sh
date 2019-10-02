#!/bin/bash

mkdir tmp
cd tmp

getent passwd >  users
touch user
while read -r line ; do
	NAME=$(echo $line | cut -d: -f5)
	COUNT=$(echo $NAME | tr " " "\n" | wc -l)
	if [ $COUNT -ge 3 ] ; then
		echo $NAME
	fi
done < users

cd ../
rm -Rf tmp
