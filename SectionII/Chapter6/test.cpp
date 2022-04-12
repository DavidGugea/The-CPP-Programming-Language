#include <iostream>
using namespace std;

void equals(int a, int b){
    bool x {a == b};

    cout << a << " -- " << b << " -- > " << x << endl;
    cout << x << endl;
}

int main(){
    char x = 'b';
    char y = 'B';
    char a = 98;
    char b = 66;
    char c = 255;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    cout << int{x} << endl;
    cout << int{y} << endl;

    return 1;
}