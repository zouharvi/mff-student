strip:
	cat ptakopet_c4.csv | grep CONFIRM | cut -d"," -f3,4,5 > clean_all.csv
	awk 'length($0) < 140' clean_all.csv > strip.csv
	sed -i -e 's/^/,/' strip.csv > /dev/null
	rm clean_all.csv
