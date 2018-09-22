#include <vector>
#include <string>
#include "query_base.h"
#include "utils/text_utils.h"

class TruncateTable : public QueryBase {
    public:
        TruncateTable(std::vector<std::string>, bool&);
        std::string table_name;
        QueryBase* get_data();
};