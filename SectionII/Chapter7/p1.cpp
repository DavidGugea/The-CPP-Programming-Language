#include <iostream>

using namespace std;

int get_sum(int* array, int size) {
    int sum = 0;

    for(int i = 0 ; i < size ; i++) {
        sum += array[i];
    }

    return sum;
}

void f1(char* p) {
    char s[] = "Hello World";

    const char* pc  = s; // pointer to constant
    char *const cp = s; // constant pointer
    const char *const cpc = s; // const pointer to const
}

int main() {
    int v1[] = {1, 2, 3, 4};
    char s[] = "Hello World";

    const char* pc = s;

    cout << s << endl;
    char *const constant_pointer = s;
    constant_pointer[3] = 's';
    cout << s << endl;

    return 1;
}