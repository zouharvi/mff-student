#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>

struct Token
{
    Token(std::string);
    Token() {};

    enum Type
    {
        NUMBER,
        VARIABLE,
        OPERATION
    } type;
    // union {
    char var;
    enum Operation
    {
        ADD,
        SUB,
        MUL,
        DIV,
        POW,
        PRINT,
        DROP
    } operation;
    int num;
    // };

    static bool is_num(std::string data)
    {
        // TODO: find prettier solution
        try
        {
            int n = stoi(data);
            return true;
        }
        catch (...)
        {
            return false;
        }
    }

    static bool is_var(std::string data)
    {
        if (data.size() != 1)
            return false;

        if (data[0] < 'a' || data[0] > 'z')
            return false;

        return true;
    }

    static bool is_operation(std::string_view data)
    {
        return (data == "+" || data == "*" || data == "/" || data == "-" || data == "^" || data == "?" || data == "#");
    }

    static void print_operation(Operation op)
    {
        switch (op)
        {
        case Operation::ADD:
            std::cout << "+";
            break;
        case Operation::DIV:
            std::cout << "/";
            break;
        case Operation::MUL:
            std::cout << "*";
            break;
        case Operation::SUB:
            std::cout << "-";
            break;
        case Operation::DROP:
            std::cout << "#";
            break;
        case Operation::PRINT:
            std::cout << "?";
            break;
        }
    }

    void print() {
        if(type == Type::OPERATION)
            print_operation(operation);
        else if(type == Type::NUMBER)
            std::cout << num;
        else if(type == Type::VARIABLE)
            std::cout << var;
    }
};

class Tokenizer
{
  public:
    static std::vector<Token> tokenize(std::string_view);

  private:
    bool full_token(std::string_view data);
};

#endif