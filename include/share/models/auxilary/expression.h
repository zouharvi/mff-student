#ifndef MODEL_EXPRESSION_H
#define MODEL_EXPRESSION_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <exception>
#include <memory>
#include "utils/text_utils.h"
#include "utils/comp_utils.h"

class Expression
{
  public:
    Expression(const std::vector<std::string> &, bool &);

    enum OPERATOR
    {
        ADD,
        SUB,
        DIV,
        MUL,
        AND,
        OR,
        CAT,
        EQ,
        GT,
        LT,
        GET,
        LET,
        NEQ
    } op;

    // raw value for column name
    std::string raw_name;

    // evaluate this expression
    std::string eval(std::map<std::string, std::string> &, bool &);

    // does a cast of internal eval (split due to linking errors with -O3 optimization level)
    template <typename T>
    T eval_cast(std::map<std::string, std::string> &vars, bool &ok)
    {
        return cast<T>(eval(vars, ok), ok);
    }
    std::set<std::string> required_vars;

  private:
    template <typename T>
    T static cast(std::string, bool &);

    std::unique_ptr<Expression> left_expr, right_expr;

    bool value_only = false;
    bool is_variable = false;
    std::string value, ops;

    bool static is_operator(std::string);
    unsigned int static get_priority(std::string);

    // error outputs
    void static err(bool &, std::string, std::vector<std::string> = std::vector<std::string>());
    void static missing_left_op(bool &, const std::string &);
    void static missing_right_op(bool &, const std::string &);
};

#endif