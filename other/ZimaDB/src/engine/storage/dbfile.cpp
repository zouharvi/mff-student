#include "storage/dbfile.h"

std::string paging::get_empty_page(std::size_t page_size)
{
    std::string page("\0");
    page.resize(page_size);
    for (std::size_t i = 0; i < page_size; ++i)
        page[i] = '\0';

    return page;
}

std::string paging::get_empty_header_page()
{
    std::string page("\0");
    page.resize(4096);
    for (std::size_t i = 0; i < 4096; i++)
        page[i] = '\0';

    page.replace(0,MAGIC_HEADER.length(), MAGIC_HEADER);
    page[LAST_PAGE_OFFSET + 1] = 1;
    return page;
}

std::string paging::get_empty_header_page(std::size_t page_size)
{
    std::string page("\0");
    page.resize(page_size);
    for (std::size_t i = 0; i < page_size; i++)
        page[i] = '\0';

    page.replace(0,MAGIC_HEADER.length(), MAGIC_HEADER);
    page[LAST_PAGE_OFFSET + 1] = 1;
    return page;
}


std::string paging::get_empty_table_page()
{
    std::string page("\0");
    page.resize(4096);
    for (int i = 0; i < 4096; i++)
        page[i] = '\0';

    page[0] = LEAF_BTREE_PAGE_HEADER;
    page[1] = 0xFF;
    page[2] = 0xFF;
    page[3] = 3;
    page[4] = '\0';
    page[5] = '\0';

    return page;
}

HeaderData paging::get_header_data(FileIO &fileio)
{
    std::string header_page = fileio.read_page(0);
    const char *c_str = header_page.c_str();

    HeaderData data;
    data.first_free_page = c_str[FREE_OFFSET] * 256 + c_str[FREE_OFFSET + 1];
    data.last_page_number = c_str[LAST_PAGE_OFFSET] * 256 + c_str[LAST_PAGE_OFFSET + 1];

    return data;
}

std::size_t paging::get_freelist_page_successor(std::size_t page_nr, FileIO &fileio)
{
    std::string page = fileio.read_page(page_nr);

    return page[SUCCESSOR_OFFSET] * 256 + page[SUCCESSOR_OFFSET + 1];
}

std::string paging::create_header_page(HeaderData data, std::size_t page_size)
{
    std::string header_page = get_empty_header_page(page_size);
    header_page[LAST_PAGE_OFFSET] = (data.last_page_number / 256) % 256;
    header_page[LAST_PAGE_OFFSET + 1] = data.last_page_number % 256;
    header_page[FREE_OFFSET] = (data.first_free_page / 256) % 256;
    header_page[FREE_OFFSET + 1] = data.first_free_page % 256;

    return header_page;
}

bool paging::write_header_page(HeaderData data, FileIO &fileio)
{
    return fileio.rewrite_page(0, create_header_page(data, fileio.get_page_size()));
}

std::size_t paging::get_empty_page_address(FileIO &fileio)
{
    HeaderData data = get_header_data(fileio);
    std::size_t result;

    if (data.first_free_page != 0)
    {
        result = data.first_free_page;
        data.first_free_page = get_freelist_page_successor(result, fileio);
        write_header_page(data, fileio);
    }
    else
    {
        result = data.last_page_number + 1;
        fileio.append_page(std::move(get_empty_page(fileio.get_page_size())));
        data.last_page_number++;
        write_header_page(data, fileio);
    }

    return result;
}

bool paging::add_freelist_page(std::size_t page_nr, FileIO &fileio)
{
    HeaderData data = get_header_data(fileio);

    std::string page = create_freelist_page(data.first_free_page, fileio.get_page_size());
    fileio.rewrite_page(page_nr, page);

    data.first_free_page = page_nr;

    return write_header_page(data, fileio);
}

std::string paging::create_freelist_page(std::size_t successor, std::size_t page_size)
{
    std::string header_page = paging::get_empty_page(page_size);
    header_page[0] = FREE_PAGE_HEADER;
    header_page[SUCCESSOR_OFFSET] = successor % 256;
    header_page[SUCCESSOR_OFFSET + 1] = (successor / 256) % 256;

    return header_page;
}
