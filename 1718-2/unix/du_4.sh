#!/bin/bash

#tmp dir
L_TMP="temporary-`date -Iseconds`"
if mkdir $L_TMP; then
	cd $L_TMP
# nedelame zadny input validation, ale coz
	BALANCE=$1
	FINISH=false
	# create file from stdin
	if [ $# -eq 1 ]; then
		cat > input
	else
		cp "../$2" input
	fi

	# cut input
	cut -d";" -f 1 input > msg_1
	cut -d";" -f 2 input > mon
	cut -d";" -f 3 input > msg_2

	# process input
	touch output
	
	# dirty, heavy
   	exec 3<msg_1
   	exec 4<mon
   	exec 5<msg_2

	while IFS= read -r f1 <&3
   	      IFS= read -r f2 <&4
   	      IFS= read -r f3 <&5
	do
		BALANCE=$(( $BALANCE + $f2 ))
		echo -n "$f2;"
		echo -n "$BALANCE;"
		echo -n "$f3;"  
		echo "$f1"
	done >> output

	if [ $# -le 2 ]; then
		cat output
	else
		mv output "../$3"
	fi

	cd ../
	rm -r $L_TMP
#else
# mkdir outputs an error instead of me
fi
