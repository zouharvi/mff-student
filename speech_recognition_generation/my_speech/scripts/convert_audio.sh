#!/usr/bin/env bash

for i in *.wav
do
   sox $i -r 22050 -c 1 S$i
done
