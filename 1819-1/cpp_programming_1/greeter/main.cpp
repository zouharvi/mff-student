#include "Greeter.h"

int main() {
std::string str("Do not write this");
	Greeter g(str);
	str = "Write this";
	g.greet(std::cout);
}
