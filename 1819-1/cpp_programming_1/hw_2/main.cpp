#include <iostream>
#include "tokenizer.h"
#include "converter.h"
#include "expression.h"

/*
    General note on exceptions:
    This code does not use exceptions for invalid inputs (both on invalid tokens
    and operator semantics). Invalid inputs are expected and thus are part of
    the standard code flow. There are numerous resources on why using exceptions in
    this case is a bad idea (just Google `exceptions as control flow`). Performance
    and (sometimes) unexpected behavior are the main reasons for this decision.
    Signal booleans are passed as a reference and are expected to be set to false
    on any error. -VZ
*/

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        bool ok = true;
        auto infix = Tokenizer::tokenize(line, ok);

        if(!ok) {
            std::cout << "Input error" << std::endl;
            continue;
        }

        if(infix.empty()) {
            std::cout << std::endl;
            continue;
        }

        auto postfix = Converter::infix2postfix(infix, ok);

        if(!ok) {
            std::cout << "Input error" << std::endl;
            continue;
        }

        auto root = Expression::build(postfix, ok);
        root->derive();
        root->simplify();
        root->traverse_infix();
        std::cout << std::endl;
    }
}
