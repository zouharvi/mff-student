#include "models/query.h"
#include "storage/fileio.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager {
    public:
        std::string perform_query(Query);
        bool open_file(std::string);
        void close_file();

    private:
        std::string create_table(CreateTable* data) {return fileio.create_table(data);};
        std::string drop_table(DropTable* data) {return fileio.drop_table(data);};
        std::string delete_records(Delete*) {};
        //std::string insert(Insert*);
        //std::string update(Update*)
        std::string select(Select*) {};
        


        FileIO fileio;
};

#endif
