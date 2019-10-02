#!/bin/bash

# 1
cat /etc/passwd | cut -d: -f "1" | tee _tmp_users |sort | uniq 

# 2
cat /etc/passwd | cut -d: -f "3" | tee _tmp_uids | sort | uniq

# 3
cat /etc/passwd | cut -d: -f "6" | tee _tmp_homes
paste -d: _tmp_uids _tmp_homes _tmp_users | tee _tmp_blueberry 

# 4
cat /etc/passwd | cut -d: -f "7" | sort | uniq | wc -l | tee _tmp_unique_b
