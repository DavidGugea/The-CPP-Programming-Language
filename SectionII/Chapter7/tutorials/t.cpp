#include <iostream>

using namespace std;

int main() {
    int a; // goes on stack

    /*
    malloc(size_t size) allocates >size< bytes on the heap and returns a **void** pointer to the allocated memory.

    free(void* ptr) frees the memory space pointed to by ptr.

    int *p;
    p = (int*) malloc(sizeof(int));
    *p = 10;

    free(p);

    p = (int*)malloc(20 * sizeof(int));
    cout << &p << endl;
    */

   int *p;
   p = new int;
   *p = 10;
   delete p;
   p = new int[20];
   delete[] p;

    return 0;
}