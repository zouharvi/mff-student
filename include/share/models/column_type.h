#include <string>
#include <vector>
#include "utils/comp_utils.h"
#include "utils/text_utils.h"
#include "models/var_type.h"
using namespace std;

class ColumnType {
    public:
        ColumnType(vector<string>, bool&);

        // print this object's content
        string debug();

        string name;
        VarType type;
        bool not_null = false;
        bool primary_key = false;
        enum {ASC, DESC} sort_order = ASC; 
};