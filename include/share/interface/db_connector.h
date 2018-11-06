#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H

#include <string>
#include "models/query.h"
#include "storage/manager.h"

class DbConnector
{
  public:
    // execute a query in the db manager
    std::string perform_query(Query &);

    // pass open_file command to db manager
    std::string open_file(std::string);

    // pass close_file command to db manager
    std::string close_file();

  private:
    Manager db_manager;
};

#endif