#include "interface/db_connector.h"

std::string DbConnector::perform_query(Query query)
{
    db_manager.perform_query(query);
}