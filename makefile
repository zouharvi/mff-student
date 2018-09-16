# minimalist build setup

SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
LIB := # -L lib 

zimadb: $(OBJECTS)
	@echo ""
	@echo "Linking $^"
	@mkdir -p bin
	g++ $^ -o bin/zimadb $(LIB)

build/%.o: src/%.cpp
	@echo ""
	@echo "Compiling $<"
	@mkdir -p build
	g++ -g -Wall -I include/ -c -o $@ $<

clean:
	@echo "Removing build/ and bin/";
	rm -rf build/ 
	rm -rf bin/

test:
	@echo "Tests are not implemented"
