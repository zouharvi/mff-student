# minimalist build setup

SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
LIB := # -L lib 

zimadb: $(OBJECTS) engine/bin/libzimadbe.a
	@echo ""
	@echo "Linking $^"
	@mkdir -p bin
	g++ $^ -o bin/zimadb $(LIB)

build/%.o: src/%.cpp
	@echo ""
	@echo "Compiling $<"
	@mkdir -p build
	g++ -g -Wall -I include/ -c -o $@ $<

engine/bin/libzimadbe.a: 
	@echo ""
	@echo "Building the engine"
	@$(MAKE) -C engine --no-print-directory  engine

clean:
	@echo ""
	@echo "Removing build/ and bin/";
	rm -rf build/ 
	rm -rf bin/
	@echo ""
	@echo "Now cleaning the engine";
	@$(MAKE) -C engine --no-print-directory clean

test:
	@echo "Tests are not implemented"