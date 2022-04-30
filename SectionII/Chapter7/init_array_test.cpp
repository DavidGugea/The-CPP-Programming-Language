#include <iostream>
using namespace std;

int main(){
    int v1[] = {1, 2, 3, 4}; 
    char v2[] = {'a', 'b', 'c', 0 };

    // char v3[2] = {'a', 'b', 0}; //  error : too many initializers
    char v4[3] = { 'a', 'b', 0}; // OK

    int v5[8] = { 1, 2, 3, 4 };

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v4 << endl;
    cout << v5 << endl;

    return 1;
}
