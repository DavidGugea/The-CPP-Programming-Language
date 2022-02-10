#include <iostream>
using namespace std;

int main(){
    int answer = 1;

    switch(answer){
        case 1:
            cout << "The answer was 1\n";
            break;
        case 2:
            cout << "The answer was 2\n";
            break;
        default:
            cout << "The answer was neither 1 nor 2. The answer was: " << answer << "\n";
            break;
    }
}
