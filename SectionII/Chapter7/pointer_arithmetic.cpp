#include <iostream>
using namespace std;

int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* p = &a[5];
    int* x = a;

    for(int i : a)
        cout << i << endl;

    cout << *p << endl; // 5
    cout << *x << endl; // 0

    return 1;
}
