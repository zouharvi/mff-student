#include "interface/db_connector.h"
#include <iostream>

std::string DbConnector::perform_query(Query& query)
{
    return db_manager.perform_query(query);
}