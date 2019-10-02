SHELL := bash

all:
	@for filename in *.py; do \
		printf "$$filename:\n\t"; \
		python3 ./$$filename; \
		printf "\n"; \
	done;
	@printf "Total number of .py files: "
	@ls *.py | wc -l