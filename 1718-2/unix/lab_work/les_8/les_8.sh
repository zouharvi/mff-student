#!/bin/bash

for var in "$@"
do
	./sleeper.sh "$var" &
done

wait
