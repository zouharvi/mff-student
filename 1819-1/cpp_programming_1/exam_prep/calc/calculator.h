// TODO: inputinclude guards
#include <stack>
#include <vector>
#include "tokenizer.h"
#include "expression.h"

class Calculator
{
    public:
        void eat(std::vector<Token> token);

    private:
        void process_op(Token::Operation);

        std::stack<std::unique_ptr<Expression>> stack;
};