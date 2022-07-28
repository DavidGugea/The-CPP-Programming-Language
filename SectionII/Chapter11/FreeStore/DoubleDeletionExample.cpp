#include <iostream>

using namespace std;

void sloppy() {
	int* p = new int[1000]; // acquite memory
	delete[] p; // delete memory
	delete[] p; // but sloppy() does not own *p
}

int main3() {

	return 1;
}