#include <iostream>
using namespace std;

bool accept(){
    int tries = 1;
    while(tries < 4){
        cout << "Do you want to proceed ( y or n )?\n"; // ask question
        char answer = 0; // read answer
        cin >> answer;

        switch(answer){
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I don't understand that.\n";
                ++tries; // increment
        }
    }
    
    cout << "I'll take that for a no.\n";
    return false;
}

int main(){
    bool answer = accept();
    cout << "The answer from the function accept() was -- > " << answer << "\n";
}
