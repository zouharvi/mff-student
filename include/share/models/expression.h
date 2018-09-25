#include <vector>
#include <string>
#include <iostream>
#include "utils/text_utils.h"
#include "utils/comp_utils.h"

class Expression {
    public:
        Expression(std::vector<std::string>, bool&);

        std::string value;
        Expression *left_expr, *right_expr;
        enum OPERATOR { ADD, SUB, DIV, MUL, AND, OR, CAT };

        bool static is_operator(std::string);
        uint static get_priority(std::string);
        void err(bool&, std::string, std::vector<std::string> = std::vector<std::string>()); 
};