#include <iostream>

using namespace std;

int main(){
    int userInput;
    cin >> userInput;
    
    int result = userInput % 2;
    
    if(result == 0){
        cout << "Your integer is even." << endl; 
    } else {
        cout << "Your integer is odd." << endl;
    }
    
    return 0;
}