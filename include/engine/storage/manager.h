#include "models/query.h"
#include "storage/fileio.h"
#include "storage/pager.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager
{
  public:
    std::string perform_query(Query &);
    std::string open_file(std::string);
    void close_file();

  private:
    std::string create_table(Query &);
    std::string drop_table(Query &);
    std::string delete_records(Query &);
    std::string select(Query &);
    std::string insert(Query &);
    std::string truncate(Query &);
    std::string update(Query &) { return "UPDATE NOT IMPLEMENTED"; };

    std::string create_table_v1(Query &query) { return pager.add_table(query, fileio); };
    std::string drop_table_v1(Query &query) { return pager.delete_table(query, fileio); };
    std::string delete_v1(Query &query) { return pager.delete_records(query, fileio); };
    std::string insert_v1(Query &query) { return pager.add_records(query, fileio); };
    std::string select_v1(Query &query);
    std::string truncate_v1(Query &query) { return pager.truncate_table(query, fileio); };

    FILE_STATUS file_status = FILE_STATUS::FAILURE;

    Pager pager;
    FileIO fileio;
};

#endif
