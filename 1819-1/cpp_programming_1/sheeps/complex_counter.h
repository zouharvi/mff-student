#include <string>
#include <iostream>

class ComplexCounter {
	public:
		void process(const std::string&);
		void dump();

	private:
		uint no_sen = 0;
		uint no_char = 0;
		uint no_word = 0;
		uint no_num  = 0;
		uint no_lin = 0;
		ulong sum = 0;
};
