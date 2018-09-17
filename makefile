# minimalist build setup
.DEFAULT_GOAL := zimadb
SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
LIB := -lreadline -lcurses

zimadb: $(OBJECTS) engine/bin/libzimadbe.a
	@echo ""
	@echo "Linking $@"
	@mkdir -p bin
	g++ $^ -o bin/zimadb $(LIB)

build/%.o: src/%.cpp
	@echo ""
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	g++ -g -Wall -I include/ -c -o $@ $<

engine/bin/libzimadbe.a: 
	@echo ""
	@echo "Building the engine"
	@$(MAKE) -C engine --no-print-directory  engine

run: zimadb
	@echo ""
	@echo ""
	@bin/zimadb

clean:
	@echo ""
	@echo "Removing build/ and bin/";
	rm -rf build/ 
	rm -rf bin/
	@echo ""
	@echo "Cleaning the engine";
	@$(MAKE) -C engine --no-print-directory clean

test:
	@echo "Tests are not implemented"
