#!/bin/bash

#tmp dir
L_TMP="temporary-`date -Iseconds`"
mkdir -p $L_TMP
cd $L_TMP

#separate columns
cut -d: ../jmena.in -f"1" > ids
cut -d: ../jmena.in -f"2" > names
cut -d: ../jmena.in -f"3" > ips

#swap names, sort, swap again
cut -d" " -f"1" names > names_1
cut -d" " -f"2" names > names_2
paste -d" " names_2 names_1 ids ips | sort > stuff_swapped 
cut -d" " -f"1" stuff_swapped > names_swapped_1
cut -d" " -f"2" stuff_swapped > names_swapped_2
cut -d" " -f"3" stuff_swapped > ids_swapped
cut -d" " -f"4" stuff_swapped > ips_swapped
paste -d" " names_swapped_2 names_swapped_1 > names_swapped

#decorate names, finish
paste -d"()" /dev/null names_swapped /dev/null > names_decor
paste ips_swapped ids_swapped names_decor > ../jmena.out

#clean up
cd ../
rm -Rf $L_TMP
