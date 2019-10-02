#include "general.h"
#include <vector>

int main()
{
    std::vector<GeneralUnique> v;
    v.push_back(std::make_unique<GInt>(5));
    v.push_back(std::make_unique<GString>("hello"));
    v.push_back(std::make_unique<GInt>(105));
    v[0]->print();
    v[0]->add(std::move(v[2]))->print();

    // v[1]->add();

    // try to create GeneralUnique
}