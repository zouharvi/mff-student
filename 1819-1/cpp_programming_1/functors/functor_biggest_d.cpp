#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class biggest_d {
    public:
        biggest_d() : n_(0) {};
        void operator() (int& x) {
            if(!started) {
                started = true;
                b = 0;
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

int main()
{
    vector<int> vec = {1, 2, 5, 10, 11, 7};
    
    auto fnd = for_each(vec.begin(), vec.end(), biggest_d());
    cout << fnd.b << endl;

    return 0;
}
