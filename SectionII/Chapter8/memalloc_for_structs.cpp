#include <iostream>

using namespace std;

struct test_struct_1 { 
    int a;
    char b;
    char c;
};

struct test_struct_2 {
    char d;
    int e;
    char f;
};

int main() {
    cout << sizeof(test_struct_1) << endl; // 8
    cout << sizeof(test_struct_2) << endl; // 12

    return 1;
}