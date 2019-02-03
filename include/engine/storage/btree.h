#include <utility>
#include <string>
#include <vector>

#include "storage/fileio.h"

#ifndef BTREE_H
#define BTREE_H

struct BTreeNode;

class BTree
{
  public:
    std::pair<std::size_t, std::size_t> find(std::size_t page_nr, std::string &key, FileIO &);
    std::pair<std::size_t, std::size_t> find(std::pair<std::size_t, std::size_t> location, FileIO &);
    std::pair<std::size_t, std::size_t> find_btree_location(std::size_t page_nr, std::string &key, FileIO &);
    std::vector<std::pair<std::size_t, std::size_t>> find_all(std::size_t page_nr, FileIO &);
    std::vector<std::pair<std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>>> find_all_locations(std::size_t page_nr, FileIO &);

    bool build_root(std::size_t page_nr, int primary_type, FileIO &);

    std::size_t insert(std::size_t page_nr, std::string &key, std::pair<std::size_t, std::size_t> &ptr, FileIO &);
    bool delete_key(std::size_t page_nr, std::string &key, FileIO &);
    bool delete_position(std::pair<std::size_t, std::size_t> location, FileIO &);
    std::vector<std::size_t> get_all_tree_pages(std::size_t page_nr, FileIO &fileio);

  private:
    BTreeNode parse_page(std::string &);

    std::string create_page(BTreeNode&, std::size_t);
    bool split_child(BTreeNode &, std::size_t, BTreeNode &, std::size_t, BTreeNode &, std::size_t &, FileIO &);
    bool merge(BTreeNode &, std::size_t, FileIO &);

    static constexpr std::size_t ORDER = 10; // TODO: experiment with different numbers, it is expected that ORDER is an even number for easier splitting.
};

struct BTreeNode
{
    std::vector<std::size_t> pointers;
    std::vector<std::pair<std::size_t, std::size_t>> data_pointers;
    std::vector<std::string> keys;
    int type;
    bool is_leaf;
    std::size_t parent_nr;
};

#endif