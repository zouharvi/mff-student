#!/bin/bash

TMP_TIME=`date +"%s"`
TMP_DIR="_tmp_dir_$TMP_TIME"
mkdir "$TMP_DIR"

# run given script
cd "$TMP_DIR"
"../$1" 
cd ../

ls "$TMP_DIR"
rm -R "$TMP_DIR"
