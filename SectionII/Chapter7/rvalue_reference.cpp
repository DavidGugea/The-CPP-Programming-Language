#include <iostream>

using namespace std;

/*
In C++ an lvalue is something that points to a specific memory location. On the other hand, a rvalue is something that doesn't point anywhere.
*/

int main() {
    string var {"Cambridge"};
    string f();

    string& r1 {var}; // bind r1 to var (an lvalue)
    /* 

    string& r2 {f()}; // error: f() is an rvalue
    string& r3 {"Princeton"}; // error: cannot bind to temporary

    */

    string&& rr1 {f()}; // fine: bind rr1 to rvalue (a temporary)
    // string&& rr2 {var}; // error: var is an lvalue
    string&& rr3 {"Oxford"}; // rr3 refers to a temporary holding "Oxford"

    const string& cr1 {"Harvard"}; // OK: make temporary and bind to cr1

    return 1;
}