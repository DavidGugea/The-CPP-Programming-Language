#include <iostream>
using namespace std;

int main(){
    int ma[3][5]; // 3 arrays with 5 ints each

    for (int i = 0; i < 3 ; i++)
        for ( int j = 0 ; j < 5 ; j++)
            ma[i][j] = 10*i+j;
            
    cout << ma << endl;

    for (int i = 0; i < 3 ; i++)
        for ( int j = 0 ; j < 5 ; j++)
            cout << ma[i][j] << endl;

    return 1;
}
