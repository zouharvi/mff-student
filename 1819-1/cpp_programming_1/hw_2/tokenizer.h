#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <sstream>

class Tokenizer
{
  public:
    struct Token
    {
        // Only when type == NUM then d is used
        union {
            char c;
            double d = 0;
        } v;

        // OP_1 has higher priority than OP_2
        // This will work even with -
        enum
        {
            LB,
            RB,
            NUM,
            VAR,
            OP_1,
            OP_2
        } type = NUM;

        void print();
    };

    // Returns partially processed tokens on error
    // Sets ok = false on imbalanced parentheses 
    static std::vector<Token> tokenize(std::string_view data, bool &ok);
};