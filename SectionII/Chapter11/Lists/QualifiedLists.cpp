#include <iostream>

using namespace std;

struct S { int a, b; };

int main3() {
	S v{ 7, 8 }; // direct initialization of a variable
	v = S{ 7, 8 }; // assign using qualified list
	S* p = new S{ 7, 8 }; // construct on free store using qualified list

	return 1;
}