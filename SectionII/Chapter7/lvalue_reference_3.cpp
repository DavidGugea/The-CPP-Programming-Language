#include <iostream>

using namespace std;

void increment(int& value) {
    value += 1;
}

int main() {
    int x = 9;
    cout << x << endl;
    increment(x);
    cout << x << endl;

    return 1;
}