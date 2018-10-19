#include "storage/manager.h"

bool Manager::open_file(std::string filename)
{
    return fileio.open_file(filename);
}

std::string Manager::perform_query(Query query)
{
    switch(query.data->type){
        case QueryBase::DELETE:
            delete_records(static_cast<Delete*>(query.data));
            break;
        case QueryBase::CREATE:
            return create_table(static_cast<CreateTable*>(query.data));
            break;
        case QueryBase::DROP:
            drop_table(static_cast<DropTable*>(query.data));
            break;
        case QueryBase::SELECT:
            return select(static_cast<Select*>(query.data));
            break;
        default:
            return "Unknown query";
    }

    return "";
}
