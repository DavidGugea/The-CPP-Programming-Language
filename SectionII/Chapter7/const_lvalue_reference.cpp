#include <iostream>

using namespace std;

int main() {
    int x = 10;
    const int& y = x;

    cout << y << endl;
    x = 15;
    cout << y << endl;

    return 1;
}