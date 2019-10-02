#include <iostream>
#include <exception>
#include <string>

using namespace std;

struct frac_zero_denom : public std::exception  {
    int a, b;
    frac_zero_denom(int a, int b) : a(a), b(b) {
         snprintf(buf, 100, "Fraction %d/%d.", a, b);
    };
    const char* what() {
        return buf;
    };
    private:
        char buf[100];
};

struct zlomek {
    int a, b;
    zlomek(int a, int b) : a(a), b(b) {
        if (b == 0) throw frac_zero_denom(a, b);
    };
};

ostream& operator<<(ostream& o, const zlomek& z) {
    o << " (" << z.a << "/" << z.b << ")";
    return o;
}

int main()
{
    try {
        cout << "hello sailor" << zlomek(3,4) << "." << endl;
        cout << "hello jello" << zlomek(3,0) << "." << endl;
    } catch(frac_zero_denom& f) {
        cout << "\nError: encountered an error: " << f.what() << endl;
    }
}
