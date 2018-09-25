#include "models/expression.h"
using namespace std;

Expression::Expression(vector<string> tokens, bool& ok) {
    size_t length = tokens.size();
    
    // todo: strip parentheses left & right by slice

    size_t start_index = 0;
    size_t end_index = length - start_index;
    
    if(length == 0) {
        value = "";
        return;
    }
    if(length == 1) {
        value = tokens[0];
        return;
    }

    uint open = 0;
    uint lowest_priority = 0;
    uint lowest_priority_index = 0; 
    for(size_t i = start_index; i < end_index; i++) {
        if(tokens[i] == "(") {
            open += 1;
            continue;
        }
        if(tokens[i] == ")") {
            open -= 1;
            if(open < 0) {
                err(ok, "Expression not properly parenthesized", tokens); return;
            }
            continue;
        }
        uint priority = get_priority(tokens[i]);
            if(priority != 0) { // tokens[i] is an operator
            if(open * 100 + priority < lowest_priority || lowest_priority == 0) {
                lowest_priority_index = i;
                lowest_priority = open * 100 + priority;
            }
        }
    }

    left_expr  = new Expression(CompUtils::slice(tokens, start_index, lowest_priority_index-1), ok);
    right_expr = new Expression(CompUtils::slice(tokens, lowest_priority_index+1, end_index), ok);
    cout << "Found " << tokens[lowest_priority_index] << endl; 
}

uint Expression::get_priority(string op) {
    // level 2
    if(op == "*")   return 5;
    if(op == "/")   return 5;
    if(op == "%")   return 5;
    
    // level 3
    if(op == "+")   return 4;
    if(op == "-")   return 4;
    if(op == "||")  return 4;

    // level 5
    if(op == "NOT") return 3;
    
    // level 6, 7
    if(op == "AND") return 3;
    if(op == "OR")  return 3;

    return 0;
}

bool Expression::is_operator(string op) {
    // level 2
    if(op == "*" || op == "/" || op == "%") return true;
    
    // level 3
    if(op == "+" || op == "-" || op == "||") return true;

    // level 5
    if(op == "NOT") return true;
    
    // level 6, 7
    if(op == "AND" || op == "OR") return true;

    return false;
}


void Expression::err(bool& ok, std::string info, std::vector<std::string> tokens) {
    ok = false;
    if(!tokens.empty()) {
        cout << "Error `" << CompUtils::implode(tokens, ",") << "`";
        cout << "      ";
    }
    cout << info << endl;
}
