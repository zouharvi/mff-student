#include "Greeter.h"

Greeter::Greeter(std::string& data) {
	this->data = &data;
}

void Greeter::greet(std::ostream& stream) {
	stream << *this->data;
}
