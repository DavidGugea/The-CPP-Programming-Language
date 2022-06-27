#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int z = 10;
    int* y = &x;
    y = &z;

    cout << y << endl;
    cout << *y << endl;
    cout << &y << endl;

    return 1;
}