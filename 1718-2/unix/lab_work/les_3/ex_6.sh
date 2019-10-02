#!/bin/bash

getent passwd | cut -d: -f "5" | sort | uniq -d > _tmp
cat _tmp | cut -d" " -f "1" > _tmp_1
cat _tmp | cut -d" " -f "2" > _tmp_2
paste -d" " _tmp_2 _tmp_1 | tr [a-z] [A-Z] | sort 
