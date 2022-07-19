void f(int x, int y){
    int j = x = y; // the vlaue of x=y is the value of x after the assignment with y
    int*p = &++x; // p points to x
    int* q = &(x++) // error: x++ is not an lvalue (it is not the value stored in x)
    int* p2 = &(x>y?x:y); // address of the int with the larger value
    int& r = (x<y)?x:1; // error: 1 is not an lvalue
}