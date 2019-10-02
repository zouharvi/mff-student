#include "complex_counter.h"

using namespace std;
void ComplexCounter::process(const string& s) {
    no_char = s.length();
    bool is_word = true;
    bool is_num = true;
    for(auto& c : s) {
        
    }
}

void ComplexCounter::dump() {
    cout << "znaku: " << no_char << "\n";
    cout << "slov: " << no_word << "\n";
    cout << "vet: " << no_sen << "\n";
    cout << "radku: " << no_lin << "\n";
    cout << "cisel: " << no_num << "\n";
    cout << "soucet: " << sum << endl;
}