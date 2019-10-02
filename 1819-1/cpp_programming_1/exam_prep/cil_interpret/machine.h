#include <iostream>
#include <fstream>
#include <exception>
#include <stack>
#include <map>
#include "tokenizer.h"

class Machine {
    public:
        Machine(const std::string&);
    private:
        void process();
        std::stack<int> stack;
        int registers[10];
        int ip = 0; // instruction pointer
        std::map<std::string, int> labels;

        std::ifstream file;
        std::vector<std::vector<Token>> instructions;
        bool file_ok = true;
};