#!/bin/env bash

TASK1_SOLVER="./task1.py"
TASK2_SOLVER="./task2.py"

cat vstupy/reseni1.txt | grep "vstup1-[0-9].*" | cut -f1 | cut -d' ' -f2 > reseni1_clean
> reseni1_local
for filename in vstupy/vstup1-*; do
    if echo "$filename" | grep "[cs][0-9]" >> /dev/null; then
        continue;
    fi
    echo "$filename"
    res=`cat $filename | $TASK1_SOLVER > tmp && glpsol -m tmp | grep 'OUTPUT:' | cut -d' ' -f2`
    echo "$res" >> reseni1_local
done
echo "ROZDIL v TASK1:"
diff reseni1_local reseni1_clean


# echo -e "\n\n"
# cat vstupy/reseni2.txt | grep "vstup2-[0-9].*" | cut -f1 | cut -d' ' -f2 > reseni2_clean
# > reseni2_local
# for filename in vstupy/vstup2-*; do
#     if echo "$filename" | grep "[s][0-9]" >> /dev/null; then
#         continue;
#     fi
#     echo "$filename"
#     res=`cat $filename | $TASK2_SOLVER > tmp && glpsol -m tmp | grep 'OUTPUT:' | cut -d' ' -f2`
#     echo "$res" >> reseni2_local
# done
# echo "ROZDIL v TASK2:"
# diff reseni2_local reseni2_clean