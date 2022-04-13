#include <iostream>
using namespace std;

int x; // global x
int* p = &x; // take address of global x

void f(){
    int x; // local x hides global x
    x = 1; // assign to local x
    cout << x << endl; // 1

    {
        int x; // hides first local x
        x = 2; // asigns to seconds local x
        cout << x << endl; // 2
    }

    x = 3;
    cout << x << endl; // 3
}

int y;

void f2(){
    int y = 5;
    cout << y << endl; // 5
    ::y = 9;
    cout << y << endl; // 5
    cout << ::y << endl; // 9
}

int main(){
    f();

    for(int i = 0 ; i < 3 ; i++){
        cout << "---" << endl;
    }

    f2();

    return 1;
}