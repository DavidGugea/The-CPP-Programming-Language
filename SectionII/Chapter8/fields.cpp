#include <iostream>

using namespace std;

struct PPN {  // Physical Page Number
    unsigned int PFN: 22;  // Page Frame Number
    int: 3;
    unsigned int CCA: 3;
    bool nonreachable: 1;
    bool dirty: 1;
    bool valid: 1;
    bool global: 1;
};

int main() {

    return 1;
}