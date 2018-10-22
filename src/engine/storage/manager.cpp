#include "storage/manager.h"

std::string Manager::open_file(std::string filename)
{
    return fileio.open_file(filename);
}

void Manager::close_file()
{
    fileio.close_file();
}

std::string Manager::perform_query(Query& query)
{
    if (query.data == nullptr)
        return "null ptr fail";

    switch(query.data->type){
        case QueryBase::DELETE:
            return delete_records(query);
            break;
        case QueryBase::CREATE:
            return create_table(query);
            break;
        case QueryBase::DROP:
            return drop_table(query);
            break;
        case QueryBase::SELECT:
            return select(query);
            break;
        default:
            return "Unknown query";
    }

    // return "";
}
