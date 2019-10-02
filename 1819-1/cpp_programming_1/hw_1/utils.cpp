#include "utils.h"

std::string Utils::to_lower(std::string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

bool Utils::is_letter(char c)
{
    return isalpha(c);
}

template <typename T>
std::set<T> Utils::intersect(std::vector<std::set<T>> &sets)
{
    std::set<T> intersection;
    if (sets.size() == 0)
        return intersection;

    // array of set iterators
    typename std::set<T>::iterator *levels = new typename std::set<T>::iterator[sets.size()];
    for (size_t i = 0; i < sets.size(); i++)
        levels[i] = sets[i].begin();

    // while(true) is not pretty, but there is no prettier logical condition
    // this loop is guaranteed to finish due to finite sets
    while (true)
    {
        T min = *levels[0];
        size_t i, min_i = 0;
        for (i = 1; i < sets.size(); i++)
        {
            if (*levels[i] < min)
            {
                min = *levels[i];
                min_i = i;
                break;
            } else if(*levels[i] != min) {
                break;
            }
        }
        // min value equal on every level
        if (i == sets.size())
        {
            intersection.insert(min);
        }
        levels[min_i]++;
        // finish on first set ove
        if (levels[min_i] == sets[min_i].end())
            break;
    }

    return intersection;
}

// create specific instance for ArticleLoc
// this is hardcoded and not pretty, but still better than to include the whole function
// in the header file
template std::set<ArticleLoc> Utils::intersect<ArticleLoc>(std::vector<std::set<ArticleLoc>> &);