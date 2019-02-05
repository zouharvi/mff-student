#include "storage/manager.h"
#include "storage/errors.h"
#include <iostream>

std::string Manager::open_file(std::string filename)
{
    file_status = fileio.open_file(filename);

    return file_status == FILE_STATUS::FAILURE ? "Error opening file `" + filename + "`" : "File `" + filename + "` open";
}

void Manager::close_file()
{
    fileio.close_file();
    file_status = FILE_STATUS::FAILURE;
}

std::string Manager::perform_query(Query &query)
{
    if (!query.ok)
        return "";
    
    if (query.data == nullptr)
        return error_msg(ErrorId::received_nullptr);

    switch (query.data->type)
    {
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
    case QueryBase::INSERT:
        return insert(query);
        break;
    default:
        return "Unknown query";
    }
}

std::string Manager::create_table(Query &query)
{
    if (file_status == FILE_STATUS::PROVISIONAL)
        return fileio.create_table(query);
    else if (file_status != FILE_STATUS::FAILURE)
        return create_table_v1(query);
    else
        return error_msg(ErrorId::no_file_open);
}

std::string Manager::drop_table(Query &query)
{
    if (file_status == FILE_STATUS::PROVISIONAL)
        return fileio.drop_table(query);
    else if (file_status != FILE_STATUS::FAILURE)
        return drop_table_v1(query);
    else
        return error_msg(ErrorId::no_file_open);
}

std::string Manager::insert(Query &query)
{
    if (file_status == FILE_STATUS::PROVISIONAL)
        return fileio.insert(query);
    else if (file_status != FILE_STATUS::FAILURE)
        return insert_v1(query);
    else
        return error_msg(ErrorId::no_file_open);
}

std::string Manager::select(Query &query)
{
    if (file_status == FILE_STATUS::PROVISIONAL)
        return fileio.select(query);
    else if (file_status != FILE_STATUS::FAILURE)
        return select_v1(query);
    else
        return error_msg(ErrorId::no_file_open);
}

std::string Manager::select_v1(Query &query)
{
    Select *data = (Select *)(query.data.get());
    std::vector<std::vector<std::map<std::string, std::string>>> table_data;
    for (auto &&table_name : data->table_names)
    {
        table_data.push_back(pager.select(table_name, fileio));
    }
    std::vector<std::map<std::string, std::string>> products = table_data[0], working_products;

    for (std::size_t index = 1; index < table_data.size(); ++index) // TODO: This is EXTREMELY inefficient, some cutting should be possible with better condition handling
    {
        for (auto &&record : table_data[index])
        {
            for (auto &&product : products)
            {
                std::map<std::string, std::string> working = record;
                for (auto it = product.begin(); it != product.end(); ++it)
                {
                    working.insert(*it);
                }
                working_products.push_back(std::move(working));
            }
        }
        products = std::move(working_products);
    }

    std::vector<std::vector<std::string>> result_rows;

    for (auto &&record : products)
    {
        bool ok = true;
        if (data->condition == nullptr || (data->condition->eval(record, ok) == "" && ok)) // TODO: is this correct?
        {
            std::vector<std::string> row;
            for (auto &&expression : data->expressions)
            {
                std::string col = expression.eval(record, ok);
                if (ok)
                {
                    row.push_back(col);
                }
                else
                {
                    break;
                }
            }

            if (ok)
            {
                result_rows.push_back(row);
            }
        }
    }

    std::string result;

    if(products.size() > 0 && result_rows.size() > 0)
    {
        auto p = products[0];
        for(auto it = p.begin(); it != p.end(); ++it)
        {
            it->second = it->first;
        }
        bool ok = true;
        std::vector<std::string> row_titles;

        for (auto &&expression : data->expressions)
        {
            std::string col = expression.eval(p, ok);
            if (ok)
            {
                row_titles.push_back(col);
            }
        }

        std::vector<std::size_t> col_length;

        for(std::size_t col = 0; col<row_titles.size(); ++col)
        {
            std::size_t maxlen = row_titles[col].length();
            for (auto &&row : result_rows)
            {
                maxlen = std::max(maxlen, row[col].length());
            }

            col_length.push_back(maxlen);
        }

        for(std::size_t i = 0; i<row_titles.size(); ++i)
        {
            if(i>0)
                result.append("|");
            row_titles[i].resize(col_length[i], ' ');
            result.append(row_titles[i]);
        }
        result.append("\n");
        std::string delim;
        for(std::size_t i = 0; i<row_titles.size(); ++i)
        {
            if(i>0)
                result.append("|");
            delim.resize(col_length[i], '-');
            result.append(delim);
        }
        result.append("\n");

        for (auto &&row : result_rows)
        {
            for (std::size_t i = 0; i<row.size(); i++)
            {
                if(i>0)
                    result.append("|");
                row[i].resize(col_length[i], ' ');
                result.append(row[i]);
            }
            result.append("\n");
        }

        result.append("Rows: ");
        result.append(std::to_string(result_rows.size()));
    }
    else
    {
        result = "No results found";
    }

    return result;
}