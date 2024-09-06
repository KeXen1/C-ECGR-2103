#include <iostream>

using namespace std;

int main(){
    
    /*
    int i = 2;
    int sum = 0;

    while(i <= 100){
        cout << i/2 + 1 << " iteration" << endl;
        sum = sum + 1;
        i = i * 2;
    }
    */
    
    int sum = 0;
    for(int i = 2; i <= 100; i = i + 2){
        cout << i/2 + 1 << " iteration" << endl;
        sum = sum + 1;
    }
    cout << "The sum of all even values between 1-100 are: " << sum << endl;
    
    return 0;
}