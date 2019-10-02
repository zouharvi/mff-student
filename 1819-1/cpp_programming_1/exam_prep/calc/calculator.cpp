#include "calculator.h"

void Calculator::eat(std::vector<Token> tokens)
{
    for (Token &token : tokens)
    {
        if (token.type == Token::Type::NUMBER || token.type == Token::Type::VARIABLE)
        {
            stack.push(std::make_unique<Expression>(token));
            continue;
        }
        if (token.type == Token::Type::OPERATION)
        {
            process_op(token.operation);
        }
    }
};

void Calculator::process_op(Token::Operation op)
{
    if (stack.size() < 1)
    {
        throw std::runtime_error("Not enough arguments on the stack.");
    }
    switch (op)
    {
    case Token::Operation::PRINT:
        stack.top()->print();
        std::cout << std::endl;
        break;
    case Token::Operation::DROP:
        stack.pop();
        break;
    default:
        if (stack.size() < 2)
        {
            throw std::runtime_error("Not enough arguments on the stack.");
        }
        std::unique_ptr<Expression> a = std::move(stack.top());
        stack.pop();
        std::unique_ptr<Expression> b = std::move(stack.top());
        stack.pop();
        stack.push(std::make_unique<Expression>(std::move(a), std::move(b), op));
    }
}