#!/bin/awk -f

/^#.*$/ {  buff=buff"\n"$0; }
/^[^#].*$/ {print $0; }
END { print buff; }
