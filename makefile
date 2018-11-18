# minimalist build setup
.DEFAULT_GOAL := zimadb
SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
LIB := -lreadline
GCC_ARGS := -Wall -Wextra -pedantic -std=c++17 -O3

zimadb: $(OBJECTS)
	@echo ""
	@echo "Linking $@"
	@mkdir -p bin
	g++ $^ $(GCC_ARGS) -o bin/zimadb $(LIB)

build/core/%.o: src/core/%.cpp
	@echo ""
	@echo "Compiling core $<"
	@mkdir -p $(shell dirname $@)
	g++ $(GCC_ARGS) -I include/core -I include/engine -I include/share  -c -o $@ $<

build/engine/%.o: src/engine/%.cpp
	@echo ""
	@echo "Compiling engine $<"
	@mkdir -p $(shell dirname $@)
	g++ $(GCC_ARGS) -I include/engine -I include/share -c -o $@ $<


build/share/%.o: src/share/%.cpp
	@echo ""
	@echo "Compiling share $<"
	@mkdir -p $(shell dirname $@)
	g++ $(GCC_ARGS) -I include/share -I include/engine -I include/core -c -o $@ $<

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

test:
	@echo "Tests are not implemented"

travis: zimadb test	

size:
	find . -type f | grep -E ".(cpp|h)$$" | xargs ls -la |  awk '{ total += $$5; print }; END { print total/1024, "KB" }';
