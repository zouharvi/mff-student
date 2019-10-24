all: extract run clean

strip:
	cat ptakopet_c4.csv | grep CONFIRM | cut -d"," -f3,4,5 > clean_all.csv
	awk 'length($0) < 140' clean_all.csv > strip.csv
	sed -i -e 's/^/,/' strip.csv > /dev/null
	rm clean_all.csv

extract:
	@cut -d"," -f1 strip_0.csv > tmp_0
	@cut -d"," -f1 strip_1.csv > tmp_1
	@#awk -v OFS="," -F"," '{print $5,$2,$3,$4}' strip_1.csv > strip_2.csv

clean:
	@rm -rf tmp_{0,1}

run:
	@./main.py tmp_0 tmp_1
