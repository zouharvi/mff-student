#include "converter.h"

using Token = Tokenizer::Token;

std::vector<Token> Converter::infix2postfix(std::vector<Token> tokens, bool &ok)
{
    std::vector<Token> postfix;
    std::stack<Token> dock;
    for (Token t : tokens)
    {
        if (t.type == Token::NUM || t.type == Token::VAR)
        {
            postfix.push_back(t);
        }
        else if (t.type == Token::OP_1 || t.type == Token::OP_2)
        {
            while (!dock.empty() && (t.type == Token::OP_2 ||
                    (t.type == Token::OP_1 && dock.top().type == Token::OP_1)) && dock.top().type != Token::LB)
            {
                postfix.push_back(dock.top());
                dock.pop();
            }
            dock.push(t);
        }
        else if (t.type == Token::LB)
        {
            dock.push(t);
        }
        else if (t.type == Token::RB)
        {
            if (dock.empty())
            {
                ok = false;
                return postfix;
            }
            while (dock.top().type != Token::LB)
            {
                postfix.push_back(dock.top());
                dock.pop();
                if (dock.empty())
                {
                    ok = false;
                    return postfix;
                }
            }
            dock.pop();
        }
    }

    // Clean the stack
    while (!dock.empty())
    {
        postfix.push_back(dock.top());
        dock.pop();
    }

    // Validate operator parity
    int open = 0;
    for (Token t : postfix)
    {
        if (t.type == Token::NUM || t.type == Token::VAR)
        {
            open += 1;
        }
        else if (t.type == Token::OP_1 || t.type == Token::OP_2)
        {
            if (t.v.c != '-')
            {
                open -= 2;
                if (open < 0)
                    ok = false;
                open += 1;
            }
            else
            {
                if (open == 2)
                    open = 1;
                else if (open == 1)
                    open = 1;
                else
                    open -= 1;
            }
        }
    }

    // Stack has to be of size 1
    if (open != 1)
        ok = false;

    return postfix;
}