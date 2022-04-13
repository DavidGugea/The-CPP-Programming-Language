#include <iostream>
using namespace std;

int main(){
    auto ac = alignof(char);
    auto ai = alignof(int);

    int a[20];
    auto aa = alignof(decltype(a));

    cout << ac << endl; // 1
    cout << ai << endl; // 4
    cout << aa << endl; // 4

    return 1;
}