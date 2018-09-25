#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <exception>
#include "utils/text_utils.h"
#include "utils/comp_utils.h"

class Expression {
    public:
        Expression(std::vector<std::string>, bool&);

        enum OPERATOR { ADD, SUB, DIV, MUL, AND, OR, CAT } op;

        // evaluate this expression
        std::string eval(std::map<std::string, std::string>&, bool&);

        // does a cast of internal eval (split due to linking errors)
        template <typename T>
        T eval_cast(std::map<std::string, std::string>&, bool&);
        set<std::string> required_vars;

    private:
        template <typename T> 
        T static cast(std::string, bool&);

        Expression *left_expr, *right_expr;
        
        bool value_only = false;
        std::string value, ops;
        
        bool static is_operator(std::string);
        uint static get_priority(std::string);
        void static err(bool&, std::string, std::vector<std::string> = std::vector<std::string>()); 
        void static missing_left_op(bool&, std::string); 
        void static missing_right_op(bool&, std::string); 
};