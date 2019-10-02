#include <string>
#include <memory>
#include <iostream>

class General;

using GeneralUnique = std::unique_ptr<General>;

class General
{
  public:
    virtual void print() = 0;
    virtual GeneralUnique add(GeneralUnique gu) = 0; // as left
    virtual GeneralUnique add_right_operand(int) = 0; // as right
    virtual GeneralUnique add_right_operand(std::string) = 0; // as right
};

class GString : public General
{
  public:
    GString(std::string value_) : value(value_) {}
    std::string value;
    void print() override
    {
        std::cout << "GString: " << value << std::endl;
    }
    virtual GeneralUnique add(GeneralUnique gu) {
        std::cout << "String add is being called" << std::endl;
        return gu->add_right_operand(value);
    }; // as left

    virtual GeneralUnique add_right_operand(int second) override {
        return std::make_unique<GString>(value + std::to_string(second));
    }
    
    virtual GeneralUnique add_right_operand(std::string second) override {
        return std::make_unique<GString>(value + second);
    }


};

class GInt : public General
{
  public:
    GInt(int value_) : value(value_) {}
    int value;
    virtual void print() override
    {
        std::cout << "GInt: " << value << std::endl;
    }
    virtual GeneralUnique add(GeneralUnique gu) {
        std::cout << "Int add is being called" << std::endl;
        return gu->add_right_operand(value);
    }; // as left


    virtual GeneralUnique add_right_operand(int second) override {
        return std::make_unique<GInt>(value + second);
    }
    
    virtual GeneralUnique add_right_operand(std::string second) override {
        return std::make_unique<GString>(std::to_string(value) + second);
    }
};