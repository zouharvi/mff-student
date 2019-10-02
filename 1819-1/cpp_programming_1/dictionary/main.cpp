#include "Dictionary.h"

using namespace std;

// TODO: change this to deque
vector<string> split_by_space(string s) {
	string buff = "";
	vector<string> r;

	for(char c : s) {
		if(c == ' ') {
			if(buff.length() != 0) {
				r.push_back(buff);
				buff = "";
			}
		} else {
			buff += c;
		}
	}
	if(buff.length() != 0) {
		// It's 2018. Why is still someone using CRLF?
		if(buff[buff.length()-1] == '\r')
			buff.pop_back();
		r.push_back(buff);
	}


	return r;
}


int main() {
	Dictionary dic;
	
	string line;
	while(getline(cin,line)) {
		dic.process(split_by_space(line));
	}
	return 0;
}
