#include <vector>
#include <string>
#include "drop_table.h"
#include "truncate_table.h"
#include "utils/text_utils.h"
using namespace std;

class Query {
    public:
        Query(vector<string>);

        enum {DROP, TRUNCATE, ERROR} command;

        // TODO: this needs to be discussed, use void ptr, or
        // this weird union?
        union {
            string* error;
            DropTable* drop;
            TruncateTable* truncate;
        } data;

        // void* data_ptr;

};