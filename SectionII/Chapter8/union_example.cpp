#include <iostream>

using namespace std;

enum Type { str, num };

struct Entry {
    char* name;
    Type t;
    Value v;
    /*
    wasting memory:
    char* s;
    int i;
    */
};

union Value {
    char* s;
    int i;
};

int main() {


    return 1;
}