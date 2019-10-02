#!/bin/bash

while read line second; do
	echo $line,$second
done << END_READ
ahoj tt
ja
jsem
vilda aa a
END_READ
