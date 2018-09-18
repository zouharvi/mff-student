# minimalist build setup
.DEFAULT_GOAL := zimadb
SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
LIB := -lreadline

zimadb: $(OBJECTS)
	@echo ""
	@echo "Linking $@"
	@mkdir -p bin
	g++ $^ -o bin/zimadb $(LIB)

build/core/%.o: src/core/%.cpp
	@echo ""
	@echo "Compiling core $<"
	@mkdir -p $(shell dirname $@)
	g++ -g -Wall -I include/core -I include/share  -c -o $@ $<

build/engine/%.o: src/engine/%.cpp
	@echo ""
	@echo "Compiling engine $<"
	@mkdir -p $(shell dirname $@)
	g++ -g -Wall -I include/engine -I include/share -c -o $@ $<


build/share/%.o: src/share/%.cpp
	@echo ""
	@echo "Compiling share $<"
	@mkdir -p $(shell dirname $@)
	g++ -g -Wall -I include/share -c -o $@ $<

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
