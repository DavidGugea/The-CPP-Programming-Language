#include <iostream>
using namespace std;

const char* error_message(int i){
    cout << i + 5 << endl;
    return "test string literal";
}

int main(){
    /*
    char p[] = "Zeno"; // p is an array of 5 char
    cout << p << endl;
    p[0] = 'R';
    cout << p << endl;
    */

    const char* x = error_message(10);
    char y = *x;

    cout << y << endl;

    return 1;
}
