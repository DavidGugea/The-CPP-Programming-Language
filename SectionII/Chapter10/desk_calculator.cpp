#include <iostream> // I/O
#include<string> // strings
#include<map> // map
#include<cctype> // isalpha(), etc.

using namespace std;

enum class Kind: char {
    name, number, end,
    plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp ='(', rp=')'
};

struct Token {
    Kind kind;
    string string_value;
    double number_value;
};

class Token_stream {
    public:
        Token_stream(istream& s): ip{&s}, owns{false}{}
        Token_stream(istream* p): ip{p}, owns{true}{}

        ~Token_stream(){ close(); }

        Token get(); // read and return next token
        const Token& current(); // most recently read token

        void set_input(istream& s){ close(); ip=&s; owns=false; }
        void set_input(istream* p){ close(); ip=p; owns=true; }
    private:
        void close() { if(owns) delete ip; }

        istream* ip; 
        bool owns;
        Token ct {Kind::end};
};

double prim(bool get) {  // handle primaries
    if(get) ts.get();  // read next token

    switch (ts.current().kind) {
        case Kind::number: {  // floating-point constant
            double v = ts.current().number_value;
            ts.get()

            return v;
        }
        case Kind::name: {
            double& v = table[ts.current().string_value];  // find the corresponding
            if (ts.get().kind == Kind::assign) v= expr(true);  // '=' seen: assignment
            return v;
        }
        case Kind::minus:  // unary minus
            return -prim(true);
        case Kind::lp:
        {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) return error("')' expected");
            ts.get();  // eat ')'
            return e;
        }
        default:
        return error("primary expected");
    }
};

double term(bool get) {  // multiply and divide
    double left = prim(get);

    for(;;) {
        switch(ts.current().kind) {
            case Kind::mul:
                left *= term(true);
                break;
            case Kind::div:
                if(auto d = prim(true)) {
                    left /= term(true);
                    break;
                }

                return error("divide by 0");
            default:
                return left;
        }
    }
};

double expr(bool get) {  // add and subtract
    double left = term(get);

    for (;;) {  // forever
        switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
};