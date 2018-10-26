#include "storage/fileio.h"

#include <algorithm>
#include <map>

std::string FileIO::open_file(std::string filename)
{
    // Get the file's extension (without the full stop)
    // This is later going to be swapped to reading the file's header
    std::string ext = filename.substr(filename.find_last_of('.') + 1);

    if (ext == PROVISIONAL_FILE_EXTENSION)
    {
        file_version = PROVISIONAL;
    }
    else if (ext == V1_FILE_EXTENSION)
    {
        file_version = V1;
    }
    else
    {
        // Unknown file extension
        return "Error: unknown extension `" + ext + "`";
    }

    close_file();

    dbfilename = filename;
    dbfile.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    return dbfile.fail() ?
        "Error opening file `" + filename + "`" :
        "File `" + filename + "` open";
}

void FileIO::close_file()
{
    if(dbfile.is_open())
    {
        dbfile.close();
    }
}

std::string FileIO::create_table(Query& query)
{
    if (query.data == nullptr)
        return "null ptr fail"; // TODO: strings to consts
    if (!dbfile.is_open())
        return "no file to write to";

    std::unique_ptr<CreateTable> create_table_query ((CreateTable*) query.data.get());
    
    bool status;
    switch (file_version) {
        case PROVISIONAL:
            status = create_table_provisional(create_table_query);
            break;
        case V1:
            status = create_table_v1(create_table_query);
            break;
        default:
            status = false;
            return "Unknown file format";
    }

    if (!status)
    {
        return "Failed to create table";
    }
    else
    {
        return "Created table `" + create_table_query->table_name + "`";
    }
}


bool FileIO::create_table_provisional(std::unique_ptr<CreateTable>& query)
{
    // Start at the beginning of the file
    dbfile.clear();
    dbfile.seekg(0, std::ios::beg);

    std::string line;
    while(!dbfile.eof())
    {
        std::getline(dbfile, line);

        // Check for table name collision
        if(!query->if_not_exists && line.substr(0,6) == ";TABLE" && line.substr(7) == query->table_name)
        {
            return false;
        }
    }

    // Restart seek
    dbfile.clear();
    dbfile.seekg(0, std::ios::beg);

    dbfile << ";TABLE:" << query->table_name << std::endl;
    dbfile << ";COLDEF:";
    
    for(const auto &column: query->columns)
    {
        // Provisional fileformat doesn't support anything else but column name and type
        dbfile << column.type.type << "-" << column.name << ",";
    }

    dbfile << std::endl;
    dbfile.flush();
    return true;
}


std::string FileIO::drop_table(Query& query)
{
    if (query.data == nullptr)
        return "null ptr fail"; // TODO: strings to consts
    if (!dbfile.is_open())
        return "no file to delete from";

    bool status = false;

    std::unique_ptr<DropTable> drop_table_query ((DropTable*) query.data.get());

    switch (file_version) {
        case PROVISIONAL:
            status = drop_table_provisional(drop_table_query);
            break;
        case V1:
            status = drop_table_v1(drop_table_query);
            break;
        default:
            return "Unknown file format";
    }
    if (!status)
    {
        return "Failed to drop the table";
    }
    else
    {
        return "Dropped the table " + drop_table_query->table_name;
    }
}

bool FileIO::drop_table_provisional(std::unique_ptr<DropTable>& query)
{
    // Start at the beginning of the file
    dbfile.clear();
    dbfile.seekg(0, std::ios::beg);
    std::string line;

    std::ofstream tempfile("temp.pzima");

    bool write = true;

    while(!dbfile.eof())
    {
        std::getline(dbfile, line);
        
        // Check for table name collision
        if(line.substr(0,6) == ";TABLE" && (line.substr(7) == query->table_name || (!write && line.substr(7) != query->table_name)))
        {
            write = !write;
        }

        if (write)
            tempfile << line << std::endl;
    }
    
    tempfile.close();
    dbfile.close();

    std::rename("temp.pzima", dbfilename.c_str());

    dbfile.open(dbfilename.c_str());

    return true;
}

std::string FileIO::insert(Query& query)
{
    if (query.data == nullptr)
        return "null ptr fail"; // TODO: strings to consts
    if (!dbfile.is_open())
        return "no file to delete from";

    bool status = false;

    std::unique_ptr<Insert> insert_query ((Insert*) query.data.get());

    switch (file_version) {
        case PROVISIONAL:
            status = insert_provisional(insert_query);
            break;
        case V1:
            status = insert_v1(insert_query);
            break;
        default:
            return "Unknown file format";
    }
    if (!status)
    {
        return "Failed to insert the data";
    }
    else
    {
        return "Inserted data to table " + insert_query->table_name->name;
    }
}


bool FileIO::insert_provisional(std::unique_ptr<Insert>& query)
{
    // Start at the beginning of the file
    dbfile.clear();
    dbfile.seekg(0, std::ios::beg);
    std::string line;

    std::ofstream tempfile("temp.pzima");

    bool found = false;

    std::vector<std::pair<VarType::Type, std::string>> columns;
    std::map<std::string, std::string> dummy = std::map<std::string, std::string>();

    while(!dbfile.eof())
    {
        std::getline(dbfile, line);

        if(line.substr(0,6) == ";TABLE" && line.substr(7) == query->table_name->name)
        {
            tempfile << line << std::endl;

            std::string written_line = std::string();
            columns = get_column_names_provisional(line);

            found = true;
	    
	    tempfile << columns.at(0).second << std::endl;

            for(auto& column: columns)
            {
                auto data = std::find(query->columns.begin(), query->columns.end(), column.second);

                if(data != query->columns.end())
                {
                    std::ptrdiff_t index = data - query->columns.begin();

                    //TODO: add type checks
                    written_line.append(query->expressions.at(index).eval(dummy, found));
                    written_line.append(",");
                }
                else
                {
                    found = false;
                    break;
                }

                if(found)
                    tempfile << written_line << std::endl;
            }

        }
        else
        {
            tempfile << line << std::endl;
        }

    }

    tempfile.close();
    dbfile.close();

    std::rename("temp.pzima", dbfilename.c_str());

    dbfile.open(dbfilename.c_str());

    return found;
}

std::string FileIO::select(Query& query)
{
    if (query.data == nullptr)
        return "null ptr fail"; // TODO: strings to consts
    if (!dbfile.is_open())
        return "no file to delete from";

    std::vector<std::vector<std::string>> result;

    std::unique_ptr<Select> select_query ((Select*) query.data.get());

    switch (file_version) {
        case PROVISIONAL:
            result = select_provisional(select_query);
            break;
        case V1:
            result = select_v1(select_query);
            break;
        default:
            return "Unknown file format";
    }

    //TODO: this currently returns no infomration, the query result should be created in Manager.
    return "Something has been selected";
}


std::vector<std::vector<std::string>> FileIO::select_provisional(std::unique_ptr<Select>& query)
{
    if(query->table_names.size() != 1)
    {
        // TODO: Add either an exception or some kind of warning/logging
        return std::vector<std::vector<std::string>>();
    }

    // Start at the beginning of the file
    dbfile.clear();
    dbfile.seekg(0, std::ios::beg);
    std::string line;

    std::ofstream tempfile("temp.pzima");

    bool in_table = false;

    std::vector<std::pair<VarType::Type, std::string>> columns;
    std::vector<std::vector<std::string>> result_rows = std::vector<std::vector<std::string>>();
    std::size_t row_nr = 0;

    while(!dbfile.eof())
    {
        std::getline(dbfile, line);

        // Check for table name
        if(line.substr(0,6) == ";TABLE" && (line.substr(7) == query->table_names.at(0).name || (!in_table && line.substr(7) != query->table_names.at(0).name)))
        {
            in_table = !in_table;
            columns = get_column_names_provisional(line);
        }
        else if(in_table)
        {
            std::vector<std::string> row_data = get_row_data_provisional(line);

            // TODO: better handling
            if(columns.size() != row_data.size())
                return std::vector<std::vector<std::string>>();

            std::map<std::string, std::string> data = std::map<std::string, std::string>();

            for(std::size_t i = 0; i<columns.size(); ++i)
            {
                data.emplace(columns[i].second, row_data[i]);
            }

            bool eval_ok = true;

            result_rows.push_back(std::vector<std::string>());

            // TODO: is this really correct? Probably not...
            if(query->condition->eval(data, eval_ok) == "true" && eval_ok)
            {
                std::string expr_result;

                for(auto expr: query->expressions)
                {
                    expr_result = expr.eval(data, eval_ok);

                    if(eval_ok)
                    {
                        result_rows[row_nr].push_back(expr_result);
                    }
                    else
                    {
                        result_rows.pop_back();
                        --row_nr;
                        break;
                    }
                }

                ++row_nr;
            }
        }
    }

    tempfile.close();
    dbfile.close();

    std::rename("temp.pzima", dbfilename.c_str());

    dbfile.open(dbfilename.c_str());

    return result_rows;
}


std::vector<std::pair<VarType::Type, std::string>> FileIO::get_column_names_provisional(std::string tabledef)
{
    std::vector<std::pair<VarType::Type, std::string>> result = std::vector<std::pair<VarType::Type, std::string>>();
    auto left_substr = std::find(tabledef.begin(), tabledef.end(), '-');
    while(left_substr != tabledef.end())
    {
       auto right_substr = std::find(left_substr, tabledef.end(), ',');

       VarType::Type column_type = VarType::Type((std::string(left_substr-1, left_substr).at(0)) - '0');

       result.push_back(std::make_pair(column_type, std::string(left_substr+1, right_substr)));

       left_substr = std::find(left_substr, tabledef.end(), '-');
    }
    return result;
}

std::vector<std::string> FileIO::get_row_data_provisional(std::string row)
{
    std::vector<std::string> result = std::vector<std::string>();
    auto left_substr = row.begin();
    while(left_substr != row.end())
    {
       auto right_substr = std::find(left_substr, row.end(), ',');

       result.push_back(std::string(left_substr, right_substr-1));

       left_substr = right_substr+1;
    }
    return result;
}
