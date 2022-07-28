#include <iostream>

using namespace std;

/*
struct Enode {
    Token_value oper;
    Enode* left;
    Enode* right;
};

Enode* expr(bool get) {
    Enode* left = term(get);

    for (;;) {
        switch (ts.current().kind) {
			case Kind::plus:
            case Kind::minus:
                left = new Enode{ ts.current().kind, left, term(true) };
                break;
            default:
                return left;
        }
    }
}

void generate(Enode* n) {
    switch (n->oper) {
        case Kind::plus
            delete n;
    }
}
*/

int main1()
{
    std::cout << "Hello World!\n";

    return 1;
}
