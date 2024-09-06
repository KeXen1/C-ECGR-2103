#include <iostream>

using namespace std;

int main(){
    double age;
    cin >> age;
    
    if(age <= 2){
        cout << "You are " << age * 10.5 << " in dog years." << endl;
    } else {  
        int dogYears = (age - 2) * 4 + 21;
        cout << "You are " << dogYears << " in dog years." << endl;
    }
    
    return 0;
}