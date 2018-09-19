#include <string>
#include <vector>
#include <iostream>
#include "utils/comp_utils.h"
using namespace std;

class VarType {
    public:
        VarType(vector<string>, bool&);
        VarType();
        void not_valid(vector<string>, bool&);

        // print this object's content
        string debug();


        enum Type {INT, TINYINT, DOUBLE, VARCHAR, BOOLEAN } type;
        size_t size; // applicable only to varchar


    private:
        // get type string name
        string get_type_name();
        static const size_t VARCHAR_MAX_SIZE = 1024;
        bool custom_size = false;
};