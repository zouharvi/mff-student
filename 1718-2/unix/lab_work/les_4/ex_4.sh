#!/bin/bash

GOAL=$RANDOM
echo "guess: "

while true; do
	read GUESS
	if ((GOAL < GUESS)); then
		echo "too high"
	elif ((GOAL > GUESS)); then
		echo "too low"
	else
		echo "correct"
		break
	fi
done
