#!/bin/bash

if [ $# -eq 0 ]; then
	echo "No mode specified (record/server)"
	exit
fi

if [ $1 = "record" ]; then
	if [ $# -eq 1 ]; then
		cut -d"	" -f"2,3,4,5,6" datab
	elif [ $# -eq 6 ]; then
		echo "afds"
	fi
elif [ $1 = "server" ]; then
	echo "server"
fi
