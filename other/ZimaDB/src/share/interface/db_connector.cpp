#include "interface/db_connector.h"
#include <iostream>

std::string DbConnector::perform_query(Query &query)
{
    return db_manager.perform_query(query);
}

std::string DbConnector::open_file(std::string filename)
{
    return db_manager.open_file(filename);
}

std::string DbConnector::close_file()
{
    db_manager.close_file();
    return "File closed";
}