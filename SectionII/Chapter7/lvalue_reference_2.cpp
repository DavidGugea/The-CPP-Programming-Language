#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int& b = a;

    a += 5;

    cout << a << endl;
    cout << b << endl;

    return 1;
}