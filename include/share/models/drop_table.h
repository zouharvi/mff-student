#include <vector>
#include <string>
#include "query_base.h"
#include "utils/text_utils.h"
using namespace std;

class DropTable : public QueryBase {
    public:
        DropTable(vector<string>, QueryCommand&);
        string table_name;
};