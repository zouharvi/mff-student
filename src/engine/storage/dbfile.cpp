#include "storage/dbfile.h"

std::string paging::get_empty_page(std::size_t page_size)
{
    std::string page("\0", page_size);
    for(std::size_t i = 0; i < page_size; ++i)
        page[i] = '\0';

    return page;
}

std::string paging::get_empty_header_page()
{
    std::string page("\0", 4096);
    for(int i = 0; i < 4096; i++)
        page[i] = '\0';

    page[0] = LEAF_BTREE_PAGE_HEADER;
    page[LAST_PAGE_OFFSET] = 1;
    return page;
}

std::string paging::get_empty_table_page()
{
    std::string page("\0", 4096);
    for(int i = 0; i < 4096; i++)
        page[i] = '\0';

    page[0] = DATA_PAGE_HEADER;

    return page;
}
