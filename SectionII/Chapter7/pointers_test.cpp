#include <iostream>
using namespace std;

int main(){
    char c = 'a'; 
    char* p = &c; // p holds the addresss of c; & is the address-of operator
    char c2 = *p; // c2 == 'a'; * is the dereference operator

    bool c_equals_c2 = ( c == c2 );
    bool c2_equals_a = ( c2 == 'a');

    cout << c << endl;
    cout << p << endl;
    cout << c2 << endl;
    cout << c_equals_c2 << endl;
    cout << c2_equals_a << endl;

    return 1;
}
