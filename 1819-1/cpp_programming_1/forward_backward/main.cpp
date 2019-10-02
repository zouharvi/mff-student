#include <deque>
#include <string>
#include <iostream>

int main() {
	std::deque<int> st;
	bool flip = true;

	size_t total = 0;
	for(int num; std::cin >> num; total++) {
		if(flip)
			st.push_back(num);
		else
			st.push_front(num);

		flip = !flip;
	}
	
	for(size_t i = 0; i < total; i++) {
		if(flip) {
			std::cout << st.front() << " ";
			st.pop_front();
		} else {
			std::cout << st.back() << " ";
			st.pop_back();
		}
	}

	// newline and clear buff
	std::cout << std::endl;
}
