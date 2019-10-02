#ifndef OBJECT_H_
#define OBJECT_H_

#include <memory>
#include <vector>
#include <map>
#include <iostream>

#include "tokenizer.h"

class Object;
class Number;
class Cell;

using ObjectPtr = std::shared_ptr<Object>;
using CellPtr = std::shared_ptr<Cell>;

struct Object
{
    virtual void print() = 0;
    virtual ObjectPtr get_left() = 0;
    virtual ObjectPtr get_right() = 0;

// TODO move to Machine
    static ObjectPtr fetch(std::string token, std::map<std::string, ObjectPtr> &vars);
    static ObjectPtr create(std::string token_left, std::string token_right, std::map<std::string, ObjectPtr> &vars);
};

struct Number : public Object
{
    Number(std::string value_)
    {
        try
        {
            value = stoi(value_);
        }
        catch (...)
        {
            throw std::runtime_error("Syntax error"); // Creating a number variable from a string not representing a number
        }
    };

    virtual ObjectPtr get_left() override
    {
        throw std::runtime_error("Invalid operation"); // get_left on Number
    };
    virtual ObjectPtr get_right() override
    {
        throw std::runtime_error("Invalid operation"); // get_right on Number
    };
    virtual void print()
    {
        std::cout << value;
    };

  private:
    int value;
};

struct Cell : public Object
{
    Cell(ObjectPtr left_, ObjectPtr right_) : left(left_), right(right_){};
    virtual void print()
    {
        std::cout << "(";
        left->print();
        std::cout << ",";
        right->print();
        std::cout << ")";
    };
    virtual ObjectPtr get_left() override
    {
        return left;
    };
    virtual ObjectPtr get_right() override
    {
        return right;
    };

  private:
    ObjectPtr left, right;
};

#endif