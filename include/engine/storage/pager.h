#include <string>

#include "storage/fileio.h"
#include "storage/btree.h"
#include "models/query.h"
#include "models/queries/select.h"

#ifndef PAGER_H
#define PAGER_H

struct HeaderData;
struct TableDefinition;

class Pager {
    public:
    std::string add_table(Query&, FileIO&);
    std::string delete_table(Query&, FileIO&);
    std::string add_records(Query&, FileIO&);
    std::string delete_records(Query&, FileIO&);
    std::vector<std::map<std::string, std::string>> select(TableName&, FileIO&);
    std::vector<std::map<std::string, std::string>> select(TableName*&, FileIO&);
    
    private:
    BTree btree;

    static constexpr std::size_t BASE_TABLE_TREE_ROOT = 1;
    bool add_freelist_page(std::size_t, FileIO&);
    HeaderData get_header_data(FileIO&);
    std::string create_freelist_page(std::size_t successor, std::size_t page_size);
    std::size_t get_freelist_page_sucessor(std::size_t page_nr, FileIO&);

    
    bool write_header_page(HeaderData, FileIO&);
    bool write_header_page(FileIO&);
    std::string create_header_page(HeaderData, std::size_t);
    
    std::vector<std::map<std::string, std::string>> parse_data_page(std::size_t page_nr, TableDefinition table_def, FileIO&);
    std::string create_data_page(std::vector<std::map<std::string, std::string>> rows, TableDefinition table_def, std::size_t page_size);
    bool write_data_page(std::size_t page_nr, std::vector<std::map<std::string, std::string>> rows, TableDefinition table_def, FileIO&);

    bool write_table_page(std::size_t page_nr, TableDefinition table_def, FileIO&);
    TableDefinition parse_table_page(std::string& page, FileIO&);
    TableDefinition get_table_definition(std::size_t page_nr, FileIO& fileio);
    std::size_t get_next_definition_page(std::size_t page_nr, FileIO&);


    std::size_t get_empty_page_address(FileIO&);
};

struct HeaderData {
    std::size_t first_free_page;
    std::size_t last_page_number;
};

struct TableDefinition {
    std::vector<std::tuple<VarType::Type, std::size_t, std::string>> columns;
    std::size_t primary;
    std::size_t empty_data_page;
    std::size_t next_id;
    std::size_t last_used_char;
    std::size_t next_definition;

    std::size_t get_row_size()
    {
        std::size_t SIZES[] = {4, 1, 4, 0 /* N/A */, 1};
        std::size_t result = 0;
        for(auto it: columns)
        {
            if(std::get<0>(it) == VarType::VARCHAR)
            {
                result += std::get<1>(it);
            }
            else
            {
                result += SIZES[static_cast<std::size_t>(std::get<0>(it))];
            }
        }
        return result;
    }

    void fill(CreateTable*);
};

#endif