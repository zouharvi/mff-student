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
                if(abs(x - prev) > n_) {
                    cout << "true, becase (x, y) = (" << x << ", " << prev << ")" << endl;
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

int main()
{
    vector<int> vec = {1, 2, 5, 10, 11};
    
    int n = 2;
    
    auto fnd = vec.begin();
    while(true) {
        fnd = find_if(fnd, vec.end(), diff(n));
        if(fnd == vec.end())
            break;
        else
            cout << *fnd << endl;
    }

    return 0;
}
