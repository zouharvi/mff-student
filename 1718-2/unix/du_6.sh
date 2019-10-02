#!/bin/bash


L_TMP="temporary-`date -Iseconds`"
mkdir $L_TMP
cp $1 "$L_TMP/src"
cp $2 "$L_TMP/rules"
cd $L_TMP

# 1st level sed: % separator
# 2nd level sed: # separator

# ^$ are redundant i know
sed -r -e 's%^(.*) --> (.*)$%s#\1#\2#%g; s%^(.*) <-- (.*)$%s#\2#\1#%g; s%^(.*) -(.*)-> (.*)$%\2s#\1#\3#%g; s%^(.*) <-(.*)- (.*)$%\2s#\3#\1#%g;' rules > rules_sed

sed -r -f rules_sed src 

cd ../
rm -Rf $L_TMP 
