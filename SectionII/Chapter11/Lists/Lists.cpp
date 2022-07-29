#include <iostream>

struct S { int a, b; };
struct SS { double a, b; };

void f(S); // f() takes an S

void g(S);
void g(SS); // g() is overloaded

int main4()
{
    f({ 1, 2 }); // OK: call f(S{1, 2})

    // g({ 1, 2 }); // error: ambiguous
    g(S{ 1, 2 }); // OK: call g(s)
    g(SS{ 1, 2 });  // OK: call g(SS)

    return 1;
}
