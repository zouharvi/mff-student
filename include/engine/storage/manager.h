#include "models/query.h"
#include "storage/fileio.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager {
    public:
        std::string perform_query(Query&);
        bool open_file(std::string);
        void close_file();

    private:
        std::string create_table(Query& query) {return fileio.create_table(query);};
        std::string drop_table(Query& query) {return fileio.drop_table(query);};
        std::string delete_records(Query&) {};
        //std::string insert(Query&);
        //std::string update(Query&)
        std::string select(Query&) {};
        


        FileIO fileio;
};

#endif
