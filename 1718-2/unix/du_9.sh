#!/bin/bash

cat $1 | awk -e '
	BEGIN {
		FS="[(), ]"	
		row = 1
		SIZE = ""
	}
	
	{
		if($1 == "graph") {
			SIZE = $2
			printf "Size: " $2 "\n";
		} else if($1 == "exist") {
			printf A[$2][$3] "\n"
		} else if($1 == "add") {
			A[$2][$3] = "1" 
			A[$3][$2] = "1" 
		} else if($1 == "delete") {
			A[$2][$3] = "0" 
			A[$3][$2] = "0" 
		} else if($1 == "degree") {
			DEG = 0
			for (x = 1; x <= SIZE; x++)
				if (A[$2][x] == "1")
					DEG ++;
			printf DEG "\n"
		} else if($1 == "neighbours") {
			do_comma = 0;
			for (x = 1; x <= SIZE; x++)
				if (A[$2][x] == "1") {
					if(do_comma == 1)
						printf ","
					do_comma = 1;
					printf x;
				}
			printf "\n"
		} else if($1 == "isolate") {
			for (x = 1; x <= SIZE; x++) {
				A[$2][x] = "0"
				A[x][$2] = "0"
			}
		} else {
			for (x = 1; x <= SIZE; x++)
				A[row][x] = $x
			row++;
		}
	}

	END {
		for (y = 1; y <= SIZE; y++) {
			for (x = 1; x <= SIZE; x++)
				printf A[y][x] " "
			printf "\n"
		}
	}
'
