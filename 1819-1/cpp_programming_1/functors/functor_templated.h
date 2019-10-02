#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>

template <typename V>
class diff_t {
    public:
        diff_t(V n) : n_(n) {};
        bool operator() (V& x) {
            if(!started) {
                started = true;
                prev = x;
                return false;
            } else {
                if(abs(x - prev) >= n_) {
                    prev = x;
                    return true;
                } else {
                    prev = x;
                    return false;
                }
            }
        };
        
    private:
        V n_, prev;
        bool started = false;
};

template <typename V>
class biggest_d {
    public:
        biggest_d() {};
        void operator() (V& x) {
            if(!started) {
                started = true;
                b = x;
                prev = x;
                n_ = x - x;
            } else {
                if(abs(x - prev) > n_) {
                    b = x;
                    n_ = abs(x-prev);
                }
                prev = x;
            }
        };
        V b;
    private:
        V n_, prev;
        bool started = false;
};

template <typename V>
class inc_t {
    public:
        void operator() (V& x) {
            x += i++;
        };
        
    private:
        V i = 1.0;
};


template <class RIT>
RIT process_diff(RIT beg, RIT end, typename std::iterator_traits<RIT>::value_type num) {
    return find_if(beg, end, diff_t<typename std::iterator_traits<RIT>::value_type>(num));
}

template <class RIT>
typename std::iterator_traits<RIT>::value_type process_gap(RIT beg, RIT end) {
    return for_each(beg, end, biggest_d<typename std::iterator_traits<RIT>::value_type>()).b;
}

template <class RIT>
void process_inc(RIT beg, RIT end) {
    for_each(beg, end, inc_t<typename std::iterator_traits<RIT>::value_type>());
}
