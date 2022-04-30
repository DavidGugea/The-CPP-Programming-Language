#include <iostream>
using namespace std;

void f(int* pi){
    void* pv = pi; // ok: implicit conversion of int* to void*
    int* pi2 = static_cast<int*>(pv); // explicit conversion back to int*

    // double* pd1 = pv; -> error
    // double* pd2 = pi; -> error
}

int main(){

    return 1;
}
