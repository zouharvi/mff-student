#include <string>
#include <vector>
#include "utils/comp_utils.h"
#include "models/var_type.h"
using namespace std;

class ColumnType {
    public:
        ColumnType(vector<string>, bool&);

        string name;
        VarType type;
};