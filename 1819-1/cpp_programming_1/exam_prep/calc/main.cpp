#include <iostream>
#include <exception>
#include "calculator.h"

int main()
{
    Calculator calc;
    std::string line;
    while(getline(std::cin, line)) {
        try {
            calc.eat(Tokenizer::tokenize(line));
        } catch(std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}