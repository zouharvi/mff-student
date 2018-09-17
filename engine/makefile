# minimalist build setup to be used by Petr

.DEFAULT_GOAL := engine
SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))

engine: $(OBJECTS)
	@echo "$(OBJECTS)"
	@echo "Creating libzimadbe.a from $^"
	@mkdir -p bin
	ar -cvq bin/libzimadbe.a $^

build/%.o: src/%.cpp
	@echo ""
	@echo "Compiling $<"
	@mkdir -p build
	g++ -g -Wall -I include/ -c -o $@ $<

clean:
	@echo ""
	@echo "Removing build/ and bin/";
	rm -rf build/ 
	rm -rf bin/