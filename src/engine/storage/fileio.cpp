#include "storage/fileio.h"

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
    
    bool status = false;
    switch (file_version) {
        case PROVISIONAL:
            status = create_table_provisional(create_table_query);
            break;
        case V1:
            status = create_table_v1(create_table_query);
            break;
        default:
            return "Unknown file format";
    }

    if (!status)
    {
        return "Failed to create the table";
    }
    else
    {
        return "Created the table " + create_table_query->table_name;
    }
}


bool FileIO::create_table_provisional(std::unique_ptr<CreateTable>& query)
{
    // Start at the beginning of the file
    dbfile.seekg(0);
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

    dbfile << ";TABLE:" << query->table_name << std::endl;
    dbfile << ";COLDEF:";
    
    for(const auto &column: query->columns)
    {
        // Provisional fileformat doesn't support anything else but column name and type
        dbfile << column.type.type << "-" << column.name << ",";
    }

    dbfile << std::endl;
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
        // return "Dropped the table " + static_cast<DropTable*>(query.data)->table_name;
    }
}

bool FileIO::drop_table_provisional(std::unique_ptr<DropTable>& query)
{
    // Start at the beginning of the file
    dbfile.seekg(0);
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
            tempfile << line;
    }
    
    tempfile.close();
    dbfile.close();

    return true;
}
