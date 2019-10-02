#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
// this could turn into dangerous circular dependency
#include "article.h"

class Utils
{
  public:
    static std::string to_lower(std::string&);
    static bool is_letter(char);
    
    // O(tn), (t - number of sets, n - sum of all elements)
    // could be reduced to O(log(t)n), if we used minheap instead of a regular array
    // since t will be ~ 1..10, the overhead cost would be too large and hence
    // O(tn) is actually better
    template<typename T>
    static std::set<T> intersect(std::vector<std::set<T>>& v);
};

#endif