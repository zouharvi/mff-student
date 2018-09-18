#include <string>
#include "models/var_type.h"
using namespace std;

class ColumnType {
    public:
        ColumnType(string, string, bool&);

        string name;
        VarType type;
};