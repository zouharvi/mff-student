#include "storage/fileio.h"

bool FileIO::open_file(std::string filename)
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
        return false;
    }

    close_file();

    dbfilename = filename;
    dbfile.open(filename);
}

void FileIO::close_file()
{
    if(dbfile.is_open())
    {
        dbfile.close();
    }
}

std::string FileIO::create_table(CreateTable* query)
{
    if (query == nullptr)
        return "null ptr fail"; // TODO: strings to consts
    if (!dbfile.is_open())
        return "no file to write to";
    
    bool status = false;

    switch (file_version) {
        case PROVISIONAL:
            status = create_table_provisional(query);
            break;
        case V1:
            status = create_table_v1(query);
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
        return "";
    }
}


bool FileIO::create_table_provisional(CreateTable* query)
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


std::string FileIO::drop_table(DropTable* query)
{
    if (query == nullptr)
        return "null ptr fail"; // TODO: strings to consts
    if (!dbfile.is_open())
        return "no file to delete from";

    bool status = false;

    switch (file_version) {
        case PROVISIONAL:
            status = drop_table_provisional(query);
            break;
        case V1:
            status = drop_table_v1(query);
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
        return "";
    }
}

bool FileIO::drop_table_provisional(DropTable* query)
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
