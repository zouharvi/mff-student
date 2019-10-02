#include <iostream>
#include <vector>
#include <algorithm>

struct Entry {
        public:
                std::string title, director;
                int year;

                bool operator < (const Entry& e) const {
                        return (year < e.year) || (year == e.year && title < e.title);
                }

                Entry(std::string title, std::string director, int year) {
                        this->title = title;
                        this->director = director;
                        this->year = year;
                }

                void dump() {
                        std::cout << title << " " << director << " " << year << std::endl;
                }
};

int main() {
        std::string title, director;
        int year;
        std::vector<Entry> datab;

        while(std::cin >> title >> director >> year)
                datab.push_back(Entry(title, director, year));
            
        std::sort(datab.begin(), datab.end());
        
        for(auto e : datab)
                e.dump();
}
