#include <iostream>

using namespace std;

int main() { 
    int a = 1;
    int& b { a };
    int& c = a;
    int* d = &a;
    // int& e; -> references must always be initialized with a value.
    int* f;
    
    cout << a << endl;
    cout << b << endl;
    cout << c + 5 << endl;
    cout << *d + 14 << endl;

    return 1;
}