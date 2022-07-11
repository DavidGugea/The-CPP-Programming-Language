#include <iostream>

using namespace std;

struct Address {
    const char* name;
    int number;
    const char* street;
    const char* town;
    char state[2];
    const char* zip;
};

void f(Address* p) {
    cout << p->name << endl;
};

int main() {
    Address address_1;
    address_1.name = "This is a test name";

    Address address_2 = {
        "This is a test name 2",
        2,
        "This is a test street name",
        "This is a test town name",
        {'N', 'J'},
        "12312",
    };

    f(&address_2);

    return 1;
}