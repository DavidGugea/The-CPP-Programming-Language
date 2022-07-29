#include <iostream>

using namespace std;

int main() {
    int c = 5;

    auto test_function = [&](int a, int b) -> int {
        cout << c << endl;
        return a + b;
    };

    int return_value = test_function(5, 7);

    cout << return_value << endl;

    return 1;
}