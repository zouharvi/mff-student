#include <algorithm>
#include <cassert>

#include "storage/pager.h"
#include "storage/dbfile.h"
#include "storage/errors.h"

std::string Pager::add_table(Query& query, FileIO& fileio)
{
    CreateTable* data = (CreateTable *)(query.data.get());
    if(data->primary_key == nullptr)
    {
        bool ok = true;
        std::vector<std::string> id_definition = { "zimaid", "PRIMARY", "KEY",  "INT" };
        data->columns.push_back(ColumnType(id_definition, ok));
        data->primary_key = &(data->columns[data->columns.size()-1]);
    }

    std::size_t definition_page_nr = get_empty_page_address(fileio);
    std::size_t root_tree_page = get_empty_page_address(fileio);

    std::pair<std::size_t, std::size_t> pair_pointer = std::make_pair(definition_page_nr, root_tree_page);
    
    btree.insert(BASE_TABLE_TREE_ROOT, data->table_name, pair_pointer, fileio);

    bool ok = btree.build_root(root_tree_page, static_cast<int>(data->primary_key->type.type), fileio);
    TableDefinition table_def;
    table_def.fill(data);
    ok = ok && write_table_page(definition_page_nr, table_def, fileio);

    return ok ?
        "Created table" :
        "Failed to create table";
}

std::string Pager::delete_table(Query& query, FileIO& fileio)
{
    DropTable* data = (DropTable *)(query.data.get());
    std::pair<std::size_t, std::size_t> address = btree.find_btree_location(BASE_TABLE_TREE_ROOT, data->table_name, fileio);

    auto pointer = btree.find(address, fileio);
    std::vector<std::size_t> page_numbers = btree.get_all_tree_pages(pointer.first, fileio);

    btree.delete_position(address, fileio);

    for(auto page_nr: page_numbers)
    {
        add_freelist_page(page_nr, fileio); // This is almost surely extremely inefficient in disk writes
    }

    add_freelist_page(pointer.second, fileio); // The table definition page
    // TODO: this will break when table definition page lengthening is implemented
}

std::string Pager::add_records(Query& query, FileIO& fileio)
{
    Insert* data = (Insert *)(query.data.get());

    auto pointer = btree.find(BASE_TABLE_TREE_ROOT, data->table_name->name, fileio);
    auto table_def = get_table_definition(pointer.second, fileio);

    std::string primary_name = std::get<2>(table_def.columns[table_def.primary]);
    std::size_t primary_index, i;
    for(i = 0; i < data->columns.size(); ++i)
    {
        if(data->columns[i] == primary_name)
        {
            primary_index = i;
            break;
        }
    }

    if(i == data->columns.size() && primary_name != "zimaid")
    {
        return error_msg(ErrorId::no_primary_key_insert);
    }
    else if (primary_name == "zimaid")
    {
        bool ok = true;
        data->columns.push_back("zimaid");
        std::vector<std::string> id = {std::to_string(table_def.next_id)};
        data->expressions.push_back(Expression(id, ok));
        table_def.next_id++;
    }

    std::vector<std::map<std::string, std::string>> page_data;
    std::map<std::string, std::string> row, dummy = std::map<std::string, std::string>();
    bool ok = true;

    for(i = 0; i < data->columns.size(); ++i)
    {
        row.insert(std::make_pair(data->columns[i], data->expressions[i].eval(dummy, ok))); // These should all be constant, so no checks for validity should be necessary
    }

    std::size_t datapage_nr = table_def.empty_data_page == 0 ? get_empty_page_address(fileio) : table_def.empty_data_page;

    if(table_def.empty_data_page != 0)
    {
        page_data = parse_data_page(datapage_nr, table_def, fileio);
    }

    page_data.push_back(row);

    ok = write_data_page(datapage_nr, page_data, table_def, fileio);

    ok = ok && write_table_page(pointer.first, table_def, fileio);

    return ok ? "Row inserted" : error_msg(ErrorId::io_error);
}

std::string Pager::delete_records(Query& query, FileIO& fileio)
{
    Delete* data = (Delete *)(query.data.get());
    auto pointer = btree.find(BASE_TABLE_TREE_ROOT, data->table_name->name, fileio);
    auto locations = btree.find_all_locations(pointer.first, fileio);
    auto table_def = get_table_definition(pointer.second, fileio);

    std::sort(locations.begin(), locations.end(), [] (auto & a, auto & b) { return a.first.first < b.first.first || (a.first.first == b.first.first && a.first.second < b.first.second); });

    std::vector<std::map<std::string, std::string>> page_rows;
    std::vector<std::pair<std::size_t, std::size_t>> to_delete;
    std::size_t current_page = 0;
    bool ok = true;

    for(std::size_t i = 0; i<locations.size(); ++i)
    {
        if(current_page != locations[i].first.first)
        {
            current_page = locations[i].first.first;
            page_rows = parse_data_page(current_page, table_def, fileio);
        }
        
        if(data->condition->eval(page_rows[locations[i].first.second], ok) == "" && ok)
        {
            to_delete.push_back(locations[i].second);
        }
    }

    for(auto&& it: to_delete)
    {
        btree.delete_position(it, fileio);
    }

    return "Deleted " + std::to_string(to_delete.size()) + " rows";
}

std::vector<std::map<std::string, std::string>> Pager::select(TableName& tablename, FileIO& fileio) // Currently fetches *all* records from a single named table, better solution is currently probably impossible due to the way conditions are handled
{
    auto pointer = btree.find(BASE_TABLE_TREE_ROOT, tablename.name, fileio);
    auto locations = btree.find_all_locations(pointer.first, fileio);
    auto table_def = get_table_definition(pointer.second, fileio);

    std::sort(locations.begin(), locations.end(), [] (auto & a, auto & b) { return a.first.first < b.first.first || (a.first.first == b.first.first && a.first.second < b.first.second); });

    std::vector<std::map<std::string, std::string>> page_rows, result;
    std::size_t current_page = 0;
    bool ok = true;

    for(std::size_t i = 0; i<locations.size(); ++i)
    {
        if(current_page != locations[i].first.first)
        {
            current_page = locations[i].first.first;
            page_rows = parse_data_page(current_page, table_def, fileio);

            result.insert(result.end(), page_rows.begin(), page_rows.end());
        }
    }

    return result;
}

std::vector<std::map<std::string, std::string>> Pager::select(TableName*& tablename, FileIO& fileio) // Currently fetches *all* records from a single named table, better solution is currently probably impossible due to the way conditions are handled
{
    return select(*tablename, fileio);
}

bool Pager::add_freelist_page(std::size_t page_nr, FileIO& fileio)
{
    HeaderData data = get_header_data(fileio);

    std::string page = create_freelist_page(data.first_free_page, fileio.get_page_size());
    fileio.rewrite_page(page_nr, page);

    data.first_free_page = page_nr;

    return write_header_page(data, fileio);
}

std::string Pager::create_freelist_page(std::size_t successor, std::size_t page_size)
{
    std::string header_page('\0', page_size);
    header_page[0] = FREE_PAGE_HEADER;
    header_page[SUCCESSOR_OFFSET] = successor % 256;
    header_page[SUCCESSOR_OFFSET+1] = (successor / 256) % 256;

    return header_page;
}

std::size_t Pager::get_freelist_page_sucessor(std::size_t page_nr, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);

    return page[SUCCESSOR_OFFSET] * 256 + page[SUCCESSOR_OFFSET+1];
}


bool Pager::write_header_page(HeaderData data, FileIO& fileio)
{
    return fileio.rewrite_page(0, create_header_page(data, fileio.get_page_size()));
}

bool Pager::write_header_page(FileIO& fileio)
{
    std::string header_page('\0', fileio.get_page_size());
    return fileio.rewrite_page(0, header_page);
}

std::string Pager::create_header_page(HeaderData data, std::size_t page_size)
{
    std::string header_page('\0', page_size);
    header_page[FREE_OFFSET] = data.first_free_page % 256;
    header_page[FREE_OFFSET+1] = (data.first_free_page / 256) % 256;

    return header_page;
}

HeaderData Pager::get_header_data(FileIO& fileio)
{
    std::string header_page = fileio.read_page(0);
    const char * c_str = header_page.c_str();

    HeaderData data;
    data.first_free_page = c_str[FREE_OFFSET+1] + c_str[FREE_OFFSET] * 256;

    return data;
}

/*
 * Parses the data page irregardles of the actual content - this means, that any empty row will still be present and must be filtered out.
 */ 
std::vector<std::map<std::string, std::string>> Pager::parse_data_page(std::size_t page_nr, TableDefinition table_def, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    std::vector<std::map<std::string, std::string>> rows;

    std::size_t current_char_index = DATAPAGE_START, row_size = table_def.get_row_size();
    constexpr std::size_t SIZES[] = {4, 1, 4, 0 /* N/A */, 1};

    for(; current_char_index + row_size < fileio.get_page_size(); current_char_index += row_size)
    {
        std::map<std::string, std::string> row;
        for(auto column: table_def.columns)
        {
            std::string result;
            if(std::get<0>(column) == VarType::VARCHAR)
            {
                result = page.substr(current_char_index, std::get<1>(column));
            }
            else
            {
                std::string internal_form = page.substr(current_char_index, SIZES[std::get<0>(column)]);
                switch(std::get<0>(column))
                {
                    case VarType::BOOLEAN:
                        if(internal_form[0] == 0x01)
                        {
                            result = TRUE_VALUE;
                        }
                        else
                        {
                            result = FALSE_VALUE;
                        }
                        break;
                    case VarType::INT:
                        result = std::to_string(
                            256*256*256*internal_form[0] +
                            256*256*internal_form[1] +
                            256*internal_form[2] +
                            internal_form[3]
                        );
                        break;
                    case VarType::TINYINT:
                        result = std::to_string(internal_form[0]);
                        break;
                    case VarType::DOUBLE:
                        // TOIMPLEMENT
                        result = "0";
                        break;
                }
            }
            row.insert(std::make_pair(std::get<2>(column), result));
        }
        rows.push_back(row);
    }

    return rows;    
}

std::string Pager::create_data_page(std::vector<std::map<std::string, std::string>> rows, TableDefinition table_def, std::size_t page_size)
{
    assert(rows.size() * table_def.get_row_size() < page_size - 1);
    std::size_t current_index = DATAPAGE_START;
    constexpr std::size_t SIZES[] = {4, 1, 4, 0 /* N/A */, 1};

    std::string page('\0', page_size);

    for(auto row: rows)
    {
        for(auto column: table_def.columns)
        {
            std::size_t len = std::get<0>(column) != VarType::VARCHAR ? SIZES[std::get<0>(column)] : std::get<1>(column);

            std::string external, result;
            try
            {
                external = row.at(std::get<2>(column));
            }
            catch (std::out_of_range& e)
            {
                external = std::string("\0", len);
            }

            int i;
            long long ll;
            switch(std::get<0>(column))
            {
                case VarType::VARCHAR:
                    result = external;
                    result.resize(len);
                    break;
                case VarType::BOOLEAN:
                    if(external == TRUE_VALUE)
                    {
                        result = 0x01;
                    }
                    else
                    {
                        result = '\0';
                    }
                    break;
                case VarType::TINYINT:
                    i = std::stoi(external);
                    result = i % 256;
                    break;
                case VarType::INT:
                    ll = std::stoll(external);
                    result.resize(4);
                    result[0] = ll / (256*256*256);
                    result[1] = ll / (256*256);
                    result[2] = ll / (256);
                    result[3] = ll % 256;
                    break;
                case VarType::DOUBLE:
                    result = "\0\0\0\0";
                    // TOIMPLEMENT
                    break;
            }
            page.replace(current_index, len, result);
        }
    }
    return page;
}

bool Pager::write_data_page(std::size_t page_nr, std::vector<std::map<std::string, std::string>> rows, TableDefinition table_def, FileIO& fileio)
{
    std::string page = create_data_page(rows, table_def, fileio.get_page_size());
    return fileio.rewrite_page(page_nr, page);
}

TableDefinition Pager::parse_table_page(std::string& page, FileIO& fileio)
{
    TableDefinition table_def;
    table_def.empty_data_page = page[EMPTY_PAGE] * 256 + page[EMPTY_PAGE+1];
    table_def.last_used_char = page[LAST_USED_CHAR] * 256 + page[LAST_USED_CHAR+1];
    table_def.next_id = page[NEXT_ID] * 256 + page[NEXT_ID+1];
    table_def.primary = page[PRIMARY_KEY_ORDER] * 256 + page[PRIMARY_KEY_ORDER+1];
    table_def.next_definition = page[NEXT_DEFINITION_PAGE]*256 + page[NEXT_DEFINITION_PAGE+1];
    
    std::size_t current_char = TABLE_DEFINITION_START;
    while(current_char < table_def.last_used_char && current_char < fileio.get_page_size())
    {
        VarType::Type type = static_cast<VarType::Type>(page[current_char]);
        std::size_t size = 0, title_length;
        std::string title;
        current_char++;
        if(type == VarType::VARCHAR)
        {
            size = page[current_char] * 256 + page[current_char+1];
            current_char += 2;
        }
            
        title_length = page[current_char] * 256 + page[current_char+1];
        current_char += 2;
        title = page.substr(current_char, title_length);
        current_char += title_length;

        table_def.columns.push_back(std::make_tuple(type, size, title));
    }

    if(table_def.next_definition != 0)
    {
        std::string next_page = fileio.read_page(table_def.next_definition);
        auto continuing_def = parse_table_page(next_page, fileio);

        table_def.columns.insert(table_def.columns.end(), continuing_def.columns.begin(), continuing_def.columns.end());
    }

    return table_def;
}

std::size_t Pager::get_next_definition_page(std::size_t page_nr, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    return page[NEXT_DEFINITION_PAGE] * 256 + page[NEXT_DEFINITION_PAGE + 1];
}

bool Pager::write_table_page(std::size_t page_nr, TableDefinition table_def, FileIO& fileio)
{

    std::vector<std::string> pages;
    std::vector<std::size_t> pagenumbers;

    std::string page('\0', fileio.get_page_size());

    page[0] = TABLE_DEFINITION_PAGE_HEADER;
    page[EMPTY_PAGE] = table_def.empty_data_page / 256;
    page[EMPTY_PAGE + 1] = table_def.empty_data_page % 256;
    page[NEXT_ID] = table_def.next_id / 256;
    page[NEXT_ID + 1] = table_def.next_id % 256;
    page[PRIMARY_KEY_ORDER] = table_def.primary / 256;
    page[PRIMARY_KEY_ORDER] = table_def.primary % 256;

    pages.push_back(page);
    pagenumbers.push_back(page_nr);

    std::size_t current_page_index = 0, current_char_index = TABLE_DEFINITION_START;
    for(auto column: table_def.columns)
    {
        std::size_t record_length = 4 + std::get<2>(column).size();
        if(std::get<0>(column) == VarType::VARCHAR)
            record_length += 2;

        if (current_char_index + record_length > fileio.get_page_size())
        {
            pages.push_back(std::string('\0', fileio.get_page_size()));
            std::size_t next_definition = get_next_definition_page(pagenumbers[current_page_index], fileio);

            if(next_definition == 0)
                next_definition = get_empty_page_address(fileio);

            pagenumbers.push_back(next_definition);
            pages[current_page_index][NEXT_DEFINITION_PAGE] = next_definition / 256;
            pages[current_page_index][NEXT_DEFINITION_PAGE + 1] = next_definition % 256;

            current_page_index++;
            current_char_index = TABLE_DEFINITION_START; // This should suffice - a check for maximum length should be somewhere, though.
        }

        pages[current_page_index][current_char_index] = static_cast<char>(std::get<0>(column));
        current_char_index++;

        if(std::get<0>(column) == VarType::VARCHAR)
        {
            pages[current_page_index][current_char_index] = std::get<1>(column) / 256;
            pages[current_page_index][current_char_index + 1] = std::get<1>(column) % 256;
            current_char_index += 2;
        }
        pages[current_page_index][current_char_index] = std::get<2>(column).length() / 256;
        pages[current_page_index][current_char_index + 1] = std::get<2>(column).length() % 256;
        current_char_index += 2;
        pages[current_page_index].replace(current_char_index, std::get<2>(column).length(), std::get<2>(column));
        current_char_index += std::get<2>(column).length();
    }

    pages[current_page_index][NEXT_DEFINITION_PAGE] = 0;
    pages[current_page_index][NEXT_DEFINITION_PAGE + 1] = 0;

    bool ok = true;

    for(std::size_t i = 0; i < pages.size(); ++i)
    {
        ok = ok && fileio.rewrite_page(pagenumbers[i], pages[i]); // TODO: Add rollback journal here
    }
    
    return ok;
}

TableDefinition Pager::get_table_definition(std::size_t page_nr, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    return parse_table_page(page, fileio);
}

std::size_t Pager::get_empty_page_address(FileIO& fileio)
{
    HeaderData data = get_header_data(fileio);
    std::size_t result;

    if(data.first_free_page != 0)
    {
        result = data.first_free_page;
        data.first_free_page = get_freelist_page_sucessor(result, fileio);
        write_header_page(data, fileio);
    }
    else
    {
        result = data.last_page_number + 1;
        fileio.append_page(std::string("\0", fileio.get_page_size()));
        data.last_page_number++;
        write_header_page(data, fileio);
    }

    return result;
}

void TableDefinition::fill(CreateTable* data)
{
    std::size_t counter = 0;
    empty_data_page = 0;
    next_id = 1;

    for(auto column: data->columns)
    {
        columns.push_back(std::make_tuple(column.type.type, column.type.size, column.name));
        if(column.primary_key)
        {
            primary = counter;
        }
        counter++;
    }
}
