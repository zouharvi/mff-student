#include <iostream>
#include <memory>
#include <vector>

class AbstractVal;
class IntVal;
class StringVal;
using valptr = std::unique_ptr<AbstractVal>;

class AbstractVal {
public:
    virtual ~AbstractVal() {}
    virtual void print() = 0;
    virtual void copyFrom(AbstractVal& av) = 0;
    virtual void copyTo(IntVal&) = 0;
    virtual void copyTo(StringVal&) = 0;
};

class IntVal : public AbstractVal {
public:
    IntVal(int val): val(val) {}
    void print() override { std::cout << val; };
    void copyFrom(AbstractVal& av) { av.copyTo(*this); };
    void copyTo(IntVal& exv);
    void copyTo(StringVal& exv);
public:
    int val;
};

class StringVal : public AbstractVal {
public:
    StringVal(std::string val): val(val) {}
    void print() override { std::cout << val; };
    void copyFrom(AbstractVal& av) { av.copyTo(*this); };
    void copyTo(StringVal& exv);
    void copyTo(IntVal& exv);
public:
    std::string val;
};

void IntVal::copyTo(IntVal& v2) { v2.val = val; };
void IntVal::copyTo(StringVal& v2) { v2.val = std::to_string(val); };
void StringVal::copyTo(IntVal& v2) { v2.val = std::stoi(val); };
void StringVal::copyTo(StringVal& v2) { v2.val = val; };
