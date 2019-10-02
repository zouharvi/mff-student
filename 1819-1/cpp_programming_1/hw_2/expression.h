#pragma once
#include <vector>
#include <memory>
#include <stack>
#include "tokenizer.h"

class Expression
{
    using Token = Tokenizer::Token;

  public:
    // Operator, num, variable, ..
    Token t;
    // Children
    std::unique_ptr<Expression> left, right;

    // Builds an expression tree from tokens in postfix order
    static std::unique_ptr<Expression> build(std::vector<Token> &tokens, bool &ok);

    Expression(Token t) : t(t){};

    // Derive & simplify according to assignment rules
    void derive();
    void simplify();

    void swap_children(std::unique_ptr<Expression> &tl, std::unique_ptr<Expression> &tr);
    std::unique_ptr<Expression> clone();

    // Prints out the tree in infix order (with full parentheses)
    void traverse_infix();


    // These two functions could be delegated to tokens, but for future
    // extensions to n-ary operators we may want to keep them here
    bool is_simple()
    {
        return (t.type == Token::NUM) || (t.type == Token::VAR);
    }

    bool is_num(double d)
    {
        return (t.type == Token::NUM) && (t.v.d == d);
    }
};