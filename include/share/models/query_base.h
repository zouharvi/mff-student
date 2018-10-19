#ifndef QUERY_BASE_H
#define QUERY_BASE_H

class QueryBase {
    public:
        // overriden only by queries, that can be easily translated into other, more basic ones
        QueryBase* get_data() { return this; };

        // overriden by children
        enum Type { GENERIC, CREATE, DROP, TRUNCATE, DELETE, UPDATE, SELECT, INSERT } type = GENERIC;
};
#endif