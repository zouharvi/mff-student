#include "tokenizer.h"

Token::Token(std::string data)
{
    if(is_operation(data)) {
        type = Token::Type::OPERATION;
        switch(data[0]) {
            case '+':
                operation = Token::Operation::ADD;
                break;
            case '-':
                operation = Token::Operation::SUB;
                break;
            case '*':
                operation = Token::Operation::MUL;
                break;
            case '/':
                operation = Token::Operation::DIV;
                break;
            case '^':
                operation = Token::Operation::POW;
                break;
            case '?':
                operation = Token::Operation::PRINT;
                break;
            case '#':
                operation = Token::Operation::DROP;
                break;
        }
    } else if(is_num(data)) {
        type = Token::Type::NUMBER;
        num = stoi(data);
    } else if(is_var(data)) {
        type = Token::Type::VARIABLE;
        var = data[0];
    } else {
        throw std::runtime_error("Unknown object `" + data + "`");
    }
}

std::vector<Token> Tokenizer::tokenize(std::string_view data)
{
    std::vector<Token> tokens;

    std::string buffer = "";
    for (char c : data)
    {
        if (c == '\t' || c == ' ')
        {
            if (buffer != "")
            {
                tokens.push_back(Token(buffer));
                buffer = "";
            }
        }
        else
        {
            if(Token::is_operation(buffer) || Token::is_var(buffer)) {
                tokens.push_back(Token(buffer));
                buffer = "";
            }
            buffer += c;
        }
    }

    // we ended, but buffer may still contain something
    if (buffer != "")
    {
        tokens.push_back(Token(buffer));
        buffer = "";
    }


    return tokens;
}