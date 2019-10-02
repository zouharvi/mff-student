#include <iostream>
#include <string>
#include "complex_counter.h"

using namespace std;

int main() {
	ComplexCounter cc;

	string all, line;
	// ¯\_(ツ)_/¯
	while (cin.good())
		all += cin.get(); 

	// remove the last (garbled) char
	all.pop_back();
	cc.process(all);
	cc.dump();
}
