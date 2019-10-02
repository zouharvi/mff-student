#!/bin/bash


funkce() {
	L="temporary-`date -Iseconds`"
	mkdir $L
	echo "$1" > $L/group_name 
	sort -t: -k1 "$GROUP" > $L/group_s1
	sort -t: -k3 "$GROUP" > $L/group_s3
	join -t: -11 -21 $L/group_name $L/group_s1 | cut -d: -f3 > $L/group_id
	sort -t: -k4 "$PASSWD" > $L/passwd_s4
	sort -t: -k1 "$PASSWD" > $L/passwd_s1
	# grep, but not grep; get first pass users 
	join -t: -11 -21 $L/group_name $L/group_s1 | cut -d: -f4 | tr ',' '\n' > $L/users_first 
	# get primary group
	#cut -d: -f3,1 "$PASSWD"
	join -t: -14 -21  $L/passwd_s4 $L/group_id | cut -d: -f2 > $L/users_second
	cat $L/users_first $L/users_second | sort | uniq > $L/users_all 
	join -t: -11 -21 $L/users_all $L/passwd_s1 | cut -d: -f5 | cut -d, -f1 
	rm -Rf $L
}

cat <<EOF > passwd-file
idris:x:1000:1000:Oliver Masek,,,:/home/idris:/bin/bash
prys:x:1001:1001:Pavel Rysavy,,,:/home/prys:/bin/bash
lynx:x:100:1002:Linda Zahalkova,,,:/home/lyn:/bin/bash
EOF
cat <<EOF > group
users:x:100:idris,prys,lynx
admin:x:120:idris
unix:x:121:prys,lynx
idris:x:1000:
prys:x:1001:
lynx:x:1002:
anaconda:x:1001
EOF

PASSWD="passwd-file"
GROUP="group"

funkce unix 
