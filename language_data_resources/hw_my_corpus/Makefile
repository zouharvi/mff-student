all: clean fetch_books process
process: tokenize occurences clean_post

tokenize:
	./tokenize.py < books_raw > books_tokens

occurences:
	# count occurences | sort by occurences | select 50 top
	sort books_tokens | uniq -c | sort -n -r | head -n 50 | tee books_freq
	@echo 'Total number of tokens:' `wc -l < books_tokens`
	@echo 'Unformatted output saved in tokens_50'
	@cat books_freq | sed -E 's/^\s+//g' | cut -d' ' -f2 > tokens_50

define fetch_gutenberg 
	curl -s 'http://www.gutenberg.org/files/$(1)/$(1)-0.txt' >> books_raw
endef
fetch_books:
	# Fetching books from Gutenberg
	$(call fetch_gutenberg,28014)
	$(call fetch_gutenberg,34079)
	$(call fetch_gutenberg,8119)
	$(call fetch_gutenberg,34079)
	$(call fetch_gutenberg,34635)
	$(call fetch_gutenberg,27062)
	$(call fetch_gutenberg,30407)
	$(call fetch_gutenberg,15201)
	$(call fetch_gutenberg,6000)
	$(call fetch_gutenberg,31531)
	$(call fetch_gutenberg,35301)
	$(call fetch_gutenberg,31536)

	# Fetching the Bible from OPUS
	wget -q "https://object.pouta.csc.fi/OPUS-bible-uedin/v1/mono/pl.txt.gz"
	gzip -d pl.txt.gz
	cat pl.txt >> books_raw

clean: clean_post
	rm -f books_raw tokens_50

clean_post:
	rm -f books_{tokens,tokenized,freq} pl.txt{.gz,}
