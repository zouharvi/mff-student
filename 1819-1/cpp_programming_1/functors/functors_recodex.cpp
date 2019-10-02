#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class diff {
    public:
        diff(int n) : n_(n) {};
        bool operator() (int& x) {
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
        int n_, prev;
        bool started = false;
};

class biggest_d {
    public:
        biggest_d() : n_(-1) {};
        void operator() (int& x) {
            if(!started) {
                started = true;
                b = x;
                prev = x;
            } else {
                if(abs(x - prev) > n_) {
                    b = x;
                    n_ = abs(x-prev);
                }
                prev = x;
            }
        };
        int b;
    private:
        int n_, prev;
        bool started = false;
};

class inc {
    public:
        inc() {};
        bool operator() (int& x) {
            x += i++;
        };
        
    private:
        int i = 1;
};


int main()
{
    vector<int> vec;
    int n; 
    while(cin >> n) {
        vec.push_back(n);
    }
    
    auto fnd = find_if(vec.begin(), vec.end(), diff(4));
    if(fnd != vec.end())
        cout << *fnd << endl; 
    else
        cout << endl;
        
    auto fndd = for_each(vec.begin(), vec.end(), biggest_d());
    cout << fndd.b << endl;
    
    
    for_each(vec.begin(), vec.end(), inc());
    for(auto x : vec)
        cout << x << " ";
    cout << endl;
    
    return 0;
}
