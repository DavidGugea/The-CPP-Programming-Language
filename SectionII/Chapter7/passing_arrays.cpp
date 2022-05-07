#include <iostream>
using namespace std;

void comp(double arg[10]){
    for(int i = 0 ; i < 10 ; i++){
        arg[i] += 99;
    }
}

void print_m35(int m[3][5]){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout << m[i][j] << '\t';
        }
        cout << "\n";
    }
}

void print_mi5(int m[][5], int dim1){
    for(int i = 0 ; i != dim1 ; i++){
        for(int j = 0 ; j != 5 ; j++){
            cout << m[i][j] << '\t';
        }
        cout << '\n';
    }
}

void f(){
    double a1[10];
    double a2[5];
    double a3[100];
    
    comp(a1);
    comp(a2); // bad
    comp(a3); // uses only the first 10 elements
}

int main(){
    return 1;

}
