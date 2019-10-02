#pragma once
#include <stack>
#include "tokenizer.h"

class Converter
{
  public:
    // Implementation of Shunting-yard algorithm as described in
    // https://en.wikipedia.org/wiki/Shunting-yard_algorithm
    // (special functions omitted, added unary -)
    // Sets ok = false on wrong operator parity 
    static std::vector<Tokenizer::Token> infix2postfix(std::vector<Tokenizer::Token> tokens, bool& ok);
};