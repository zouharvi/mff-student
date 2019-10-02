#include "object.h"

ObjectPtr Object::fetch(std::string token, std::map<std::string, ObjectPtr> &vars)
{
    if(Tokenizer::check_var_name(token)) {
        if (vars.find(token) != vars.end())
            return vars[token];
        else
            throw std::runtime_error("Unknown variable");
    }
    else
        return std::make_shared<Number>(token);
}

ObjectPtr Object::create(std::string token_left, std::string token_right, std::map<std::string, ObjectPtr> &vars)
{
    return std::make_shared<Cell>(fetch(token_left, vars), fetch(token_right, vars));
}