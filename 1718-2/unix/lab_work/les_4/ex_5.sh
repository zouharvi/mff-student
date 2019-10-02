#!/bin/bash

MAX=100000
MIN=0
while true; do
	GUESS=$(( ($MIN+$MAX)/2 ))
	echo $GUESS
	read ANS
	if [ $ANS = "high" ]; then
		MAX=$(( $GUESS-1  ))
	elif [ $ANS = "low" ]; then
		MIN=$(( $GUESS+1  ))
	else
		echo "nice"
		break
	fi
done
