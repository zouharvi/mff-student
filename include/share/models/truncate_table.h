#include <vector>
#include <string>
#include "query_base.h"
#include "utils/text_utils.h"
using namespace std;

class TruncateTable : public QueryBase {
    public:
        TruncateTable(vector<string>, QueryCommand&);
        string table_name;
};