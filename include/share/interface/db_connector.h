#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H

#include <string>

#include "models/query.h"
#include "storage/manager.h"

class DbConnector {
    public:
        std::string perform_query(Query&);
        std::string open_file(std::string);
        void close_file();

    private:
        Manager db_manager;
};

#endif