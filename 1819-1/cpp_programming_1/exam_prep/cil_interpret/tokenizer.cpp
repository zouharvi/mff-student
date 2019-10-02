#include "tokenizer.h"

bool is_number(std::string_view val) {
    if(val.length() == 0) return false; // empty string
    else if (val[0] == '-') { // negative number
        for(int i = 1; i < val.length(); i++) {
            if(!std::isdigit(val[i])) return false;
        }
        return true;
    } else { // non-negative number
        for(int i = 1; i < val.length(); i++) {
            if(!std::isdigit(val[i])) return false;
        }
        return true;
    }
}


Token::Token(std::string_view val)
{
    // instruction is default
    token_type = TOKEN_TYPE::INSTRUCTION;
    if (val == "ldconst")
        instruction_type = INSTRUCTION_TYPE::LDCONST;
    else if (val == "stloc")
        instruction_type = INSTRUCTION_TYPE::STLOC;
    else if (val == "ldloc")
        instruction_type = INSTRUCTION_TYPE::LDLOC;
    else if (val == "pop")
        instruction_type = INSTRUCTION_TYPE::POP;
    else if (val == "out")
        instruction_type = INSTRUCTION_TYPE::OUT;
    else if (val == "add")
        instruction_type = INSTRUCTION_TYPE::ADD;
    else if (val == "mul")
        instruction_type = INSTRUCTION_TYPE::MUL;
    else if (val == "sub")
        instruction_type = INSTRUCTION_TYPE::SUB;
    else if (val == "div")
        instruction_type = INSTRUCTION_TYPE::DIV;
    else if (val == "lt")
        instruction_type = INSTRUCTION_TYPE::LT;
    else if (val == "gt")
        instruction_type = INSTRUCTION_TYPE::GT;
    else if (val == "goto")
        instruction_type = INSTRUCTION_TYPE::GOTO;
    else if (val == "brt")
        instruction_type = INSTRUCTION_TYPE::BRT;
    else if (val == "brf")
        instruction_type = INSTRUCTION_TYPE::BRF;
    else if (val.back() == ':') // label
    {
        token_type = TOKEN_TYPE::LABEL_DEF;
        label = val.substr(0, val.length()-1);
    } else if (is_number(val)) // number
    {
        token_type = TOKEN_TYPE::NUMBER;
        num = std::stoi(std::string(val));
    } else {
        // TODO: can anything be a label?
        token_type = TOKEN_TYPE::LABEL_REF;
        label = val;
        // throw std::runtime_error("Undefined token: `" + std::string(val) + "`");
    }
}