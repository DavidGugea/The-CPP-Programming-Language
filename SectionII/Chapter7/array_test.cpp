#include <iostream>
using namespace std;

int main(){
    float v[3]; // an array of three floats: v[0], v[1], v[2]
    char* a[32]; // an array of 32 pointers to char: a[0] .. a[31]
    
    int aa[10];
    aa[6] = 9;
    cout << aa << endl;
    cout << aa[6] << endl;

    return 1;
}
