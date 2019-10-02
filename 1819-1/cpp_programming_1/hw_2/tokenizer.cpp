#include "tokenizer.h"

using Token = Tokenizer::Token;

void Token::print()
{
    if (type == NUM)
        std::cout << v.d;
    else if (type == VAR)
        std::cout << "x";
    else
        std::cout << " " << v.c << " ";
}

std::vector<Token> Tokenizer::tokenize(std::string_view data, bool &ok)
{
    std::vector<Token> tokens;
    int open = 0;
    for (size_t i = 0; i < data.length(); i++)
    {
        char c = data[i];
        switch (c)
        {
        case ')':
            tokens.push_back(Token{')', Token::RB});
            open--;
            if (open < 0)
            {
                ok = false;
                return tokens;
            }
            break;
        case '(':
            tokens.push_back(Token{'(', Token::LB});
            open++;
            break;
        case 'x':
            tokens.push_back(Token{'x', Token::VAR});
            break;
        case '*':
        case '/':
            tokens.push_back(Token{c, Token::OP_1});
            break;
        case '-':
        case '+':
            tokens.push_back(Token{c, Token::OP_2});
            break;
        default:
            // Skip space
            if (c == ' ')
                continue;
            if (!isdigit(c))
            {
                ok = false;
                return tokens;
            }

            std::string num;
            // Leading and trailing dots are ok
            bool used_dot = false;
            do
            {
                if (c == '.')
                    used_dot = true;
                num += c;
                c = data[++i];
            } while (isdigit(c) || (c == '.' && !used_dot));
            i--;
            
            // Nested class union initialization only since C++20 :-(
            Token tok;
            tok.type = Token::NUM;
            if(std::stringstream(num) >> tok.v.d) {
                tokens.push_back(tok);
            } else {
                ok = false;
                return tokens;
            }
        }
    }

    // Imbalanecd
    if (open != 0)
        ok = false;
    return tokens;
};