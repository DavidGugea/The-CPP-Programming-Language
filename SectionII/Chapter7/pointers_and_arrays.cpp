#include <iostream>
using namespace std;

int main(){
    int v[] = {1, 2, 3, 4};
    cout << v << endl;

    int* p1 = v; // pointer to initial element ( implicit conversion )
    cout << p1 << endl;

    int* p2 = &v[0]; // pointer to initial element
    cout << p2 << endl;

    int* p3 = v + 4; // pointer to one-beyond-last element
    cout << p3 << endl;

    
    return 1;
}
