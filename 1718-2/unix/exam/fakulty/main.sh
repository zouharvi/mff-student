#!/bin/bash

awk '
	BEGIN { printf "aaa\n" }
	{
		uni[$1]
		print "("$1") {"
		print "name "$2
		print "}"
	}
	END { printf "END\n" }
' uni
