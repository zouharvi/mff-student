# minimalist build setup
SHELL := bash
.DEFAULT_GOAL := zimadb
SOURCES := $(shell find src/ -type f -name *.cpp)
TEST_SOURCES := $(shell find src/*/*/ test/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
TEST_OBJECTS := $(patsubst src/%, build/%, $(TEST_SOURCES:.cpp=.o))
LIB := -lreadline -lstdc++fs
TESTLIB := -lgtest
GCC_ARGS := -Wall -Wextra -pedantic -std=c++17 -g
TEST_GCC_ARGS := -Wall -Wextra -pedantic -std=c++17
COMPILER := g++
 
zimadb: $(OBJECTS)
	@echo ""
	@echo "Linking $@"
	@mkdir -p bin
	$(COMPILER) $^ $(GCC_ARGS) -o bin/zimadb $(LIB)

build/core/%.o: src/core/%.cpp
	@echo ""
	@echo "Compiling core $<"
	@mkdir -p $(shell dirname $@)
	$(COMPILER) $(GCC_ARGS) -I include/core -I include/engine -I include/share  -c -o $@ $<

build/engine/%.o: src/engine/%.cpp
	@echo ""
	@echo "Compiling engine $<"
	@mkdir -p $(shell dirname $@)
	$(COMPILER) $(GCC_ARGS) -I include/engine -I include/share -c -o $@ $<


build/share/%.o: src/share/%.cpp
	@echo ""
	@echo "Compiling share $<"
	@mkdir -p $(shell dirname $@)
	$(COMPILER) $(GCC_ARGS) -I include/share -I include/engine -I include/core -c -o $@ $<

.PHONY: run clean re test travis size size_husak lines

run: zimadb
	@echo ""
	@echo ""
	@bin/zimadb

clean:
	@echo ""
	@echo "Removing build/ and bin/";
	rm -rf build/ 
	rm -rf bin/

re: clean run

test: zimadb
	@echo "Running all tests"
	cd "test/scripts/"; \
	for filename in *.sh; do \
		printf "\n\n===========================================\n"; \
		printf "Running test - $$filename\n"; \
		printf "===========================================\n\n"; \
		./$$filename; \
		rm -rf *.zima; \
	done;


travis: zimadb test	

size:
	find . -type f | grep -E ".(cpp|h)$$" | xargs ls -la |  awk '{ total += $$5; print }; END { print total/1024, "KB" }';
size_husak:
	find . -type f | grep -E ".(cpp|h)$$" | xargs ls -la |  awk '{ total += $$5; print }; END { print total*2/1024, "KB" }';
lines:
	find . -type f | grep -E ".(cpp|h)$$" | xargs ls | xargs cat | wc -l;
