#!/bin/bash

# (file_name, n)

TMP_FILE=ex_1_tmp
head -n $2 $1
N=`expr $2 + 1`
tail -n +$N $1 > $TMP_FILE
mv $TMP_FILE $1
