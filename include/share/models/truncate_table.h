#include <vector>
#include <string>
#include "query_base.h"
#include "utils/text_utils.h"

class TruncateTable : public QueryBase {
    public:
        TruncateTable(std::vector<std::string>, QueryCommand&);
        std::string table_name;
};