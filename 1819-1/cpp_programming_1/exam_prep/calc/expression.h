#include <memory>
#include <iostream>
#include <map>
#include "tokenizer.h"

struct Expression
{
    Expression(Token t) : base(t)
    {
        simple = true;
    };
    Expression(std::unique_ptr<Expression> a, std::unique_ptr<Expression> b, Token::Operation op) : left(std::move(a)), right(std::move(b)), operation(op)
    {
        simple = false;
        simplify();
    };

    void substitute(std::pair<std::string, std::unique_ptr<Expression>> var) {

    };

    void simplify() {
        if(simple) 
            return;

        left->simplify();
        right->simplify();

        if(left->is_numeric() && right->is_numeric()) {
            simple = true;
            base.type = Token::Type::NUMBER;
            switch(operation) {
                case Token::Operation::ADD:
                    base.num = left->base.num + right->base.num;
                    break;
                case Token::Operation::SUB:
                    base.num = left->base.num - right->base.num;
                    break;
                case Token::Operation::MUL:
                    base.num = left->base.num * right->base.num;
                    break;
                case Token::Operation::DIV:
                    base.num = left->base.num / right->base.num;
                    break;
                case Token::Operation::POW:
                    // throw std::runtime_error("POW not implemented yet.");
                    if(!left->is_numeric() || left->base.num < 1) 
                        throw std::runtime_error("We only support positive numeric powers.");
                    std::unique_ptr<Expression> root = std::move(left->clone());
                    for(uint i = 1; i <= left->base.num; ++i) {
                        std::unique_ptr<Expression> backup = std::move(left->clone());
                        left = std::move(std::make_unique<Expression>(std::move(backup), std::move(root), Token::Operation::MUL));
                    }
                    break;
            }
        }
    };

    std::unique_ptr<Expression> clone() {
        if(simple) {
            std::cout << "A" << std::endl;
            return std::move(std::make_unique<Expression>(base));
            std::cout << "B" << std::endl;
        }
        else {
            std::cout << "C" << std::endl;

            return std::move(std::make_unique<Expression>(std::move(left->clone()), std::move(right->clone()), operation));
            std::cout << "D" << std::endl;

        }
    }

    bool is_numeric() {
        return(simple && base.type == Token::Type::NUMBER);
    };

    void print() {
        if(simple) {
            base.print();
            std::cout << " ";
        } else {
            left->print();
            right->print();
            Token::print_operation(operation);
            std::cout << " ";
        }
    };

    bool simple = true;
    std::unique_ptr<Expression> left, right;

    Token::Operation operation;
    Token base;
};