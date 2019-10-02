#include <iostream>
#include <string>

class Greeter {

	public:
		Greeter(st::string&);
		void greet(std::ostream&);

	private:
		std::string* data;
};
