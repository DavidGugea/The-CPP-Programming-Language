void f1(char* p){
    char s[] = "Grom";

    const char* pc = s; // pointer to constant
    pc[3] = 'g'; // error: pc points to constant
    pc = p; // OK

    char *const cp = s // constant pointer
    cp[3] = 'a'; // OK
    cp = p; // error: cp is constant

    const char *const cpc = s; // const pointer to const
    cpc[3] = 'a'; // error: cpc points to constant
    cpc = p; // error: cpc is constant
}
