#include <algorithm>
#include <cassert>

#include "storage/btree.h"
#include "storage/dbfile.h"

std::pair<std::size_t, std::size_t> BTree::find_btree_location(std::size_t page_nr, std::string& key, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    BTreeNode node = parse_page(page);

    if(node.is_leaf)
    {
        auto it = std::find(node.keys.begin(), node.keys.end(), key);
        
        if(it == node.keys.end())
            return std::make_pair(0, 0);

        std::size_t index = it - node.keys.begin();

        return std::make_pair(page_nr, index);
    }
    else
    {
        auto up = std::upper_bound(node.keys.begin(), node.keys.end(), key); // TODO: add comparator based on the type
        std::size_t subtree_index = up - node.keys.begin();

        return find(node.pointers[subtree_index], key, fileio);
    }
}

std::pair<std::size_t, std::size_t> BTree::find(std::pair<std::size_t, std::size_t> location, FileIO& fileio)
{
    if(location.first == 0)
        return std::make_pair(0, 0);

    std::string page = fileio.read_page(location.first);
    BTreeNode node = parse_page(page);
    return node.data_pointers[location.second];
}

/*
 * Returns a primary key's location.
 */
std::pair<std::size_t, std::size_t> BTree::find(std::size_t page_nr, std::string& key, FileIO& fileio)
{
    auto loc = find_btree_location(page_nr, key, fileio);

    return find(loc, fileio);
}

/*
 * Returns a vector of pairs (page, row) for each found row in the subtree.
 */
std::vector<std::pair<std::size_t, std::size_t>> BTree::find_all(std::size_t page_nr, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    BTreeNode node = parse_page(page);

    if(node.is_leaf)
    {
        return node.data_pointers;
    }
    else
    {
        std::vector<std::pair<std::size_t, std::size_t>> result, partial;
        for(auto&& it: node.pointers)
        {
            partial = find_all(it, fileio);
            result.insert(result.end() - 1, partial.begin(), partial.end());
        }
        return result;
    }
}

std::vector<std::pair<std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>>> BTree::find_all_locations(std::size_t page_nr, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    BTreeNode node = parse_page(page);

    if(node.is_leaf)
    {
        std::vector<std::pair<std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>>> result;
        for(std::size_t i = 0; i< node.data_pointers.size(); ++i)
        {
            result.push_back(std::make_pair(std::make_pair(page_nr, i), node.data_pointers[i]));
        }
        return result;
    }
    else
    {
        std::vector<std::pair<std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>>> result, partial;
        for(auto&& it: node.pointers)
        {
            partial = find_all_locations(it, fileio);
            result.insert(result.end() - 1, partial.begin(), partial.end());
        }
        return result;
    }
}

std::size_t BTree::insert(std::size_t page_nr, std::string& key, std::pair<std::size_t, std::size_t>& data_ptr, FileIO& fileio)
{
    std::string x_page = fileio.read_page(page_nr), y_page;
    BTreeNode x_node = parse_page(x_page), y_node, z_node;

    // TODO: the x_node isn't checked against ORDER size and the tree may fail to grow

    std::size_t x_page_nr = page_nr, y_page_nr, z_page_nr;
    while(!x_node.is_leaf)
    {
        auto up = std::upper_bound(x_node.keys.begin(), x_node.keys.end(), key); // TODO: add comparator based on the type
        std::size_t subtree_index = up - x_node.keys.begin();

        y_page_nr = x_node.pointers[subtree_index];
        y_page = fileio.read_page(y_page_nr);
        y_node = parse_page(y_page);

        if(y_node.keys.size() == ORDER)
        {
            split_child(x_node, x_page_nr, y_node, y_page_nr, z_node, z_page_nr, fileio);
            if(key < z_node.keys[0]) // TODO: add comparator based on the type
            {
                x_node = y_node;
                x_page_nr = y_page_nr;
            }
            else
            {
                x_node = z_node;
                x_page_nr = z_page_nr;

            }
            x_page.clear();
            y_page.clear();
        }
        else
        {
            x_page = std::move(y_page);
            y_page.clear();
            x_page_nr = y_page_nr;
        }
    }

    auto up = std::upper_bound(x_node.keys.begin(), x_node.keys.end(), key); // TODO: add comparator based on the type
    std::size_t index = up - x_node.keys.begin();
    x_node.keys.insert(up, key);
    x_node.data_pointers.insert(x_node.data_pointers.begin() + index, data_ptr);

    x_page = create_page(x_node, fileio.get_page_size());
    fileio.rewrite_page(x_page_nr, x_page);

    return x_page_nr;
}

bool BTree::delete_position(std::pair<std::size_t, std::size_t> location, FileIO& fileio)
{
    std::string page = fileio.read_page(location.first);
    BTreeNode node = parse_page(page);

    node.keys.erase(node.keys.begin()+location.second);
    node.data_pointers.erase(node.data_pointers.begin()+location.second);

    if(node.keys.size() > ORDER/2)
    {
        return fileio.rewrite_page(location.first, create_page(node, fileio.get_page_size()));
    }
    else
    {
        return merge(node, location.first, fileio);
    }
}

bool BTree::split_child(BTreeNode& parent_node, std::size_t parent_nr, BTreeNode& child_node, std::size_t child_nr, BTreeNode& new_child_node, std::size_t& new_child_nr, FileIO& fileio)
{
    // TOIMPLEMENT: new_child_nr = get_valid_page_nr();
    new_child_nr = child_nr;
    auto pointer_it = std::find(parent_node.pointers.begin(), parent_node.pointers.end(), child_nr);
    std::size_t index = pointer_it - parent_node.pointers.begin();
    new_child_node.parent_nr = child_node.parent_nr;
    new_child_node.type = child_node.type;

    parent_node.pointers.insert(pointer_it, new_child_nr);
    parent_node.keys.insert(parent_node.keys.begin()+index, child_node.keys[ORDER/2]);
    new_child_node.keys.insert(new_child_node.keys.begin(), child_node.keys.begin()+(ORDER/2), child_node.keys.end());
    child_node.keys.erase(child_node.keys.begin()+(ORDER/2), child_node.keys.end());

    if(child_node.is_leaf)
    {
        new_child_node.data_pointers.insert(new_child_node.data_pointers.begin(), child_node.data_pointers.begin()+(ORDER/2), child_node.data_pointers.end());
        child_node.data_pointers.erase(child_node.data_pointers.begin()+(ORDER/2), child_node.data_pointers.end());
    }
    else
    {
        new_child_node.pointers.insert(new_child_node.pointers.begin(), child_node.pointers.begin()+(ORDER/2), child_node.pointers.end());
        child_node.pointers.erase(child_node.pointers.begin()+(ORDER/2), child_node.pointers.end());
    }

    bool ok = true;

    std::string page = create_page(parent_node, fileio.get_page_size());
    ok = ok && fileio.rewrite_page(parent_nr, page);

    page = create_page(child_node, fileio.get_page_size());
    ok = ok && fileio.rewrite_page(child_nr, page);

    page = create_page(new_child_node, fileio.get_page_size());
    ok = ok && fileio.rewrite_page(new_child_nr, page);

    return ok;
}

bool BTree::merge(BTreeNode& node, std::size_t page_nr, FileIO& fileio)
{
    if(node.parent_nr == 0)
    {
        return true; // Merging root cannot be done
    }

    std::string parent_page = fileio.read_page(node.parent_nr);
    BTreeNode parent = parse_page(parent_page), left_sibling, right_sibling;
    auto node_it = std::lower_bound(parent.keys.begin(), parent.keys.end(), node.keys[0]);
    std::size_t index = node_it - parent.keys.begin();

    if (index != 0) // Check the left sibling
    {
        std::string left_sibling_page = fileio.read_page(parent.pointers[index-1]);
        left_sibling = parse_page(left_sibling_page);
        if(left_sibling.keys.size() > ORDER/2) // ORDER is even
        {
            node.keys.insert(node.keys.begin(), left_sibling.keys.end()-1, left_sibling.keys.end());
            left_sibling.keys.erase(left_sibling.keys.end()-1);

            if (node.is_leaf)
            {
                node.data_pointers.insert(node.data_pointers.begin(), left_sibling.data_pointers.end()-1, left_sibling.data_pointers.end());
                left_sibling.data_pointers.erase(left_sibling.data_pointers.end()-1);
            }
            else
            {
                node.pointers.insert(node.pointers.begin(), left_sibling.pointers.end()-1, left_sibling.pointers.end());
                left_sibling.pointers.erase(left_sibling.pointers.end()-1);
            }
            parent.keys[index-1] = node.keys[0];

            fileio.rewrite_page(parent.pointers[index-1], create_page(left_sibling, fileio.get_page_size()));
            fileio.rewrite_page(page_nr, create_page(node, fileio.get_page_size()));
            fileio.rewrite_page(node.parent_nr, create_page(parent, fileio.get_page_size()));
        }
        else // keys.size == ORDER/2
        {
            left_sibling.keys.insert(left_sibling.keys.end(), node.keys.begin(), node.keys.end());
            if (node.is_leaf)
            {
                left_sibling.data_pointers.insert(left_sibling.data_pointers.end(), node.data_pointers.begin(), node.data_pointers.end());
            }
            else
            {
                left_sibling.pointers.insert(left_sibling.pointers.end(), node.pointers.begin(), node.pointers.end());
            }

            parent.keys.erase(parent.keys.begin()+(index-1));
            parent.pointers.erase(parent.pointers.begin()+(index-1));
            fileio.rewrite_page(node.parent_nr, create_page(parent, fileio.get_page_size()));
            fileio.rewrite_page(parent.pointers[index-1], create_page(left_sibling, fileio.get_page_size()));
            // TOIMPLEMENT: free the node page

            if(parent.keys.size() <= ORDER/2)
            {
                merge(parent, node.parent_nr, fileio);
            }
        }
    }
    else // Check the right sibling - guaranteed to exist if the left sibling does not.
    {
        std::string right_sibling_page = fileio.read_page(parent.pointers[index+1]);
        right_sibling = parse_page(right_sibling_page);
        if(right_sibling.keys.size() > ORDER/2) // ORDER is even
        {
            node.keys.push_back(right_sibling.keys[0]);
            right_sibling.keys.erase(right_sibling.keys.begin());

            if (node.is_leaf)
            {
                node.data_pointers.push_back(right_sibling.data_pointers[0]);
                right_sibling.data_pointers.erase(right_sibling.data_pointers.begin());
            }
            else
            {
                node.pointers.push_back(right_sibling.pointers[0]);
                right_sibling.pointers.erase(right_sibling.pointers.begin());
            }
            parent.keys[index-1] = node.keys[0];

            fileio.rewrite_page(parent.pointers[index+1], create_page(right_sibling, fileio.get_page_size()));
            fileio.rewrite_page(page_nr, create_page(node, fileio.get_page_size()));
            fileio.rewrite_page(node.parent_nr, create_page(parent, fileio.get_page_size()));
        }
        else // keys.size == ORDER/2
        {
            right_sibling.keys.insert(node.keys.end(), right_sibling.keys.begin(), right_sibling.keys.end());

            if (node.is_leaf)
            {
                node.data_pointers.insert(node.data_pointers.end(), right_sibling.data_pointers.begin(), right_sibling.data_pointers.end());
            }
            else
            {
                node.pointers.insert(node.pointers.end(), right_sibling.pointers.begin(), right_sibling.pointers.end());
            }

            parent.keys.erase(parent.keys.begin()+(index));
            parent.pointers.erase(parent.pointers.begin()+(index));
            fileio.rewrite_page(node.parent_nr, create_page(parent, fileio.get_page_size()));
            fileio.rewrite_page(page_nr, create_page(node, fileio.get_page_size()));
            // TOIMPLEMENT: free the right sibling page

            if(parent.keys.size() <= ORDER/2)
            {
                merge(parent, node.parent_nr, fileio);
            }
        }
    }
    return true; // TODO: proper checks
}

bool BTree::delete_key(std::size_t page_nr, std::string& key, FileIO& fileio)
{
    auto position = find_btree_location(page_nr, key, fileio);

    if(position.first == 0)
    {
        return false;
    }

    return delete_position(position, fileio);
}

std::vector<std::size_t> BTree::get_all_tree_pages(std::size_t page_nr, FileIO& fileio)
{
    std::string page = fileio.read_page(page_nr);
    BTreeNode node = parse_page(page);

    if(node.is_leaf)
    {
        return std::vector<std::size_t>();
    }
    else
    {
        std::vector<std::size_t> result = node.pointers, partial;
        for(auto&& it: node.pointers)
        {
            partial = get_all_tree_pages(it, fileio);
            result.insert(result.end() - 1, partial.begin(), partial.end());
        }
        return result;
    }
}

BTreeNode BTree::parse_page(std::string& page)
{
    const char * c_str = page.c_str();
    const std::size_t SIZES[] = {4, 1, 4, 64, 1};

    BTreeNode node;

    if(c_str[0] == 0x02) // Interior page
    {
        node.is_leaf = false;
    }
    else if(c_str[0] == 0x0a) // Leaf page
    {
        node.is_leaf = true;
    }

    std::size_t key_nr = c_str[1] * 256 + c_str[2];
    int type = c_str[3];
    node.parent_nr = c_str[4] * 256 + c_str[5];
    node.type = type;

    if(key_nr == 255*256 + 255)
        return node; // This node has no keys or pointers, this is a reserved value
    

    // If there are n keys, there are n+1 pointers
    for(std::size_t i = 0; i <= key_nr; i++)
    {
        node.pointers.push_back(c_str[6+i*2] * 256 + c_str[7+i*2]);
    }

    for(std::size_t i = 0; i < key_nr; i++)
    {
        node.keys.push_back(page.substr(6 + (key_nr+1)*2 + SIZES[type]*i, SIZES[type]));
    }
    
    if(node.is_leaf)
    {
        for(std::size_t i = 0; i < key_nr; i++)
        {
            node.data_pointers.push_back(std::make_pair(c_str[4 + (key_nr+1)*2 + SIZES[type]*key_nr + i*4] * 256 + c_str[5 + (key_nr+1)*2 + SIZES[type]*key_nr + i*4], c_str[6 + (key_nr+1)*2 + SIZES[type]*key_nr + i*4] * 256 + c_str[7 + (key_nr+1)*2 + SIZES[type]*key_nr + i*4])); // TODO: clean up, this is EXTREMELY unreadable
        }
    }

    return node;
}

std::string BTree::create_page(BTreeNode node, std::size_t page_size)
{
    assert(node.keys.size() + 1 == node.pointers.size() || node.is_leaf);
    assert(!node.is_leaf || node.data_pointers.size() == node.keys.size());
    const std::size_t SIZES[] = {4, 1, 4, 64, 1};

    std::string page('\0', page_size);

    if (node.is_leaf)
    {
        page[0] = LEAF_BTREE_PAGE_HEADER;
    }
    else
    {
        page[0] = INTERIOR_BTREE_PAGE_HEADER;   
    }

    std::size_t key_nr = node.keys.size();
    
    page[1] = key_nr / 256;
    page[2] = key_nr % 256;
    page[3] = node.type;
    page[4] = node.parent_nr / 256;
    page[5] = node.parent_nr % 256;

    for(std::size_t i = 0; i < key_nr+1; ++i)
    {
        page[6 + 2*i] = node.pointers[i] / 256;
        page[7 + 2*i] = node.pointers[i] % 256;
    }
    for(std::size_t i = 0; i < key_nr; ++i)
    {
        page.replace(6 + 2*(key_nr + 1) + SIZES[node.type]*i, SIZES[node.type], node.keys[i]);
    }
    if(node.is_leaf)
    {
        for(std::size_t i = 0; i < key_nr; ++i)
        {
            page[4 + 2*(key_nr + 1) + SIZES[node.type] * key_nr + 4*i] = node.data_pointers[i].first / 256;
            page[5 + 2*(key_nr + 1) + SIZES[node.type] * key_nr + 4*i] = node.data_pointers[i].first % 256;
            page[6 + 2*(key_nr + 1) + SIZES[node.type] * key_nr + 4*i] = node.data_pointers[i].second / 256;
            page[7 + 2*(key_nr + 1) + SIZES[node.type] * key_nr + 4*i] = node.data_pointers[i].second % 256;
        }
    }

    return page;
}

bool BTree::build_root(std::size_t page_nr, int primary_type, FileIO& fileio)
{
    std::string page('\0', fileio.get_page_size());

    page[0] = LEAF_BTREE_PAGE_HEADER;
    page[1] = 0xFF;
    page[2] = 0xFF;
    page[3] = primary_type;
    page[4] = '\0';
    page[5] = '\0';

    return fileio.rewrite_page(page_nr, page);
}
