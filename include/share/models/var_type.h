#include <string>
#include <iostream>
using namespace std;

class VarType {
    public:
        VarType(string, bool&);
        VarType();
        void not_valid(const string&);

        enum Type {INT, TINYINT, DOUBLE, VARCHAR, BOOLEAN } type;
        size_t size; // applicable only to varchar

};