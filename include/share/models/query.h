#include <vector>
#include <string>
#include <iostream>
#include "create_table.h"
#include "drop_table.h"
#include "truncate_table.h"
#include "utils/text_utils.h"
using namespace std;

class Query {
    public:
        Query(vector<string>);
        QueryCommand command;
        QueryBase* data;

        // TODO: this needs to be discussed, use void ptr, or
        // this weird union?
        // union {
        //     string* error;
        //     DropTable* drop;
        //     TruncateTable* truncate;
        // } data;

    private:
        // this shouldn't compile unless QueryType is a subclass of QueryBase
        template <class QueryType> void try_parse(vector<string>);
};