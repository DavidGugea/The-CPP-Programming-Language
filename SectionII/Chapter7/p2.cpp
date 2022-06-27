#include <iostream>

using namespace std;

void confused(int* p) {

}

int global {7};

void f() {
    // X* pn = new int{7};
    int i {7};
    int* q = &i;

    // confused(pn);
    confused(q);
    confused(&global);
}