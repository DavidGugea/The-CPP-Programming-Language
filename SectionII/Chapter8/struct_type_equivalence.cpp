#include <iostream>

using namespace std;

struct S1 { int a; };
struct S2 { int b; };

int main() {
    S1 x;
    // S2 y = x; // error: type mismatch

    return 1;
}