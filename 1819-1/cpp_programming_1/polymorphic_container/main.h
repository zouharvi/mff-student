#include <iostream>
#include <memory>
#include <vector>

class AbstractVal {
public:
    virtual ~AbstractVal() {}
    virtual void print() = 0;
    virtual std::unique_ptr<AbstractVal> clone() = 0;
};
using valptr = std::unique_ptr<AbstractVal>;

class IntVal : public AbstractVal {
public:
    IntVal(int val): val(val) {}
    void print() override { std::cout << val << std::endl; };
    valptr clone() override { return std::make_unique<IntVal>(*this);  }

private:
    int val;
};

class StringVal : public AbstractVal {
public:
    StringVal(std::string val): val(val) {}
    void print() override { std::cout << val << std::endl; };
    valptr clone() override { return std::make_unique<StringVal>(*this);  }

private:
    std::string val;
};

class ComplexVal : public AbstractVal {
public:
    ComplexVal(double val1, double val2): val1(val1), val2(val2) {}
    void print() override { std::cout << val1 << "+" << val2 << "i" << std::endl; };
    valptr clone() override { return std::make_unique<ComplexVal>(*this);  }

private:
    double val1, val2;
};

class FractionVal : public AbstractVal {
public:
    FractionVal(double val1, double val2): val1(val1), val2(val2) {}
    void print() override { std::cout << val1 << "/" << val2 << std::endl; };
    valptr clone() override { return std::make_unique<FractionVal>(*this);  }

private:
    double val1, val2;
};

class DoubleVal : public AbstractVal {
public:
    DoubleVal(double val1): val1(val1) {}
    void print() override { std::cout << val1 << std::endl; };
    valptr clone() override { return std::make_unique<DoubleVal>(*this);  }

private:
    double val1;
};


class Seznam {
public:
    Seznam() {};
    Seznam( const Seznam& s) {
        clone (s);
    };
    void add( valptr p ) { pole.push_back( move( p)); }
    void print()
        { for(auto&& x : pole ) { x->print(); } };
    Seznam& operator=(const Seznam& s)
    {
        if( this == &s)  return *this;
        pole.clear(); 
        clone( s ); 
        return *this;
    }

private:
    std::vector<valptr> pole;
    void clone( const Seznam& s ) { for( auto&& x : s.pole ) pole.push_back( x->clone() ); }

};

// int main() {
// 	Seznam s;
// 	s.add(std::make_unique<IntVal>(123));
// 	s.add(std::make_unique<StringVal>("lorem ipsum"));
// 	s.add(std::make_unique<DoubleVal>(3.14159));
// 	s.add(std::make_unique<ComplexVal>(42, 2));
// 	s.add(std::make_unique<FractionVal>(10, 16));

// 	s.print();

// 	return 0;
// }
