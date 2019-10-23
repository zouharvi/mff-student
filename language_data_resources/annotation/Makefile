strip:
	cat ptakopet_c4.log | grep CONFIRM | cut -d"," -f3,4,5 > clean_all.log
	awk 'length($0) < 140' clean_all.log > strip.log
	sed -i -e 's/^/,/' strip.log > /dev/null
	rm clean_all.log
