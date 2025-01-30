#!/bin/bash
for fullfile in ./data/hulth2003_src/*; do
    echo $fullfile
    for ((i=0; i<=4; i++)); do
        filename=$(basename -- "$fullfile")
        extension="${filename##*.}"
        filename="${filename%.*}"
        cp $fullfile "./data/hulth2003_all/$filename-$i.$extension"
    done
done