#include <iostream>
using namespace std;

int main(){
    char v1 = 123;
    int v2 = 'c';

    cout << v1 << "\n";
    cout << v2 << endl;

    char v3 {59};
    int v4 {'c'};

    cout << v3 << endl;
    cout << v4 << endl;

    auto v5 = 12345;

    cout << v5 << endl;

    return 1;
}