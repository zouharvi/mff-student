#ifndef DBFILE_H
#define DBFILE_H

#include <string>
#include "storage/fileio.h"

// HEADER OFFSETS
const std::string MAGIC_HEADER = "ZimaDB File version 1";
const std::size_t LAST_PAGE_OFFSET = 28; // offset showing the last allocated page's address
const std::size_t FREE_OFFSET = 30;      // offset showing the first freelist page's address

struct HeaderData
{
    std::size_t first_free_page;
    std::size_t last_page_number;
};

// FREELIST PAGE OFFSETS
const std::size_t SUCCESSOR_OFFSET = 1; // offset showing the page's sucessor's address

// DATAPAGE OFFSETS
const std::size_t DATAPAGE_START = 1;

// TABLE DEFINITION HEADER OFFSETS
const std::size_t EMPTY_PAGE = 1;
const std::size_t NEXT_DEFINITION_PAGE = 3;
const std::size_t LAST_USED_CHAR = 5;
const std::size_t NEXT_ID = 7;
const std::size_t PRIMARY_KEY_ORDER = 9;
const std::size_t TABLE_DEFINITION_START = 11;

// PAGE HEADER CONSTANTS
const char LEAF_BTREE_PAGE_HEADER = 0x0a;
const char INTERIOR_BTREE_PAGE_HEADER = 0x02;
const char TABLE_DEFINITION_PAGE_HEADER = 0x05;
const char DATA_PAGE_HEADER = 0x50;
const char FREE_PAGE_HEADER = 0x20;

// DEFAULT STRINGS
namespace paging
{
std::string get_empty_page(std::size_t);

std::string get_empty_header_page();
std::string get_empty_header_page(std::size_t);

std::string get_empty_table_page();

std::size_t get_empty_page_address(FileIO &);
HeaderData get_header_data(FileIO &);
std::size_t get_freelist_page_successor(std::size_t page_nr, FileIO &);
bool write_header_page(HeaderData, FileIO &);
std::string create_header_page(HeaderData data, std::size_t page_size);
std::string create_freelist_page(std::size_t successor, std::size_t page_size);
bool add_freelist_page(std::size_t page_nr, FileIO &fileio);
} // namespace paging

// SOME OTHER CONSTANTS (@Vilda)

const std::string TRUE_VALUE = "true";
const std::string FALSE_VALUE = "false";

#endif