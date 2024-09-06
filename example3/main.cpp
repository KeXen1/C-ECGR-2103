#include <iostream>

using namespace std;

int main(){
    
    double wages;
    
    double hoursWorked;
    
    cout << "Enter the number of hours worked:" << endl;
    cin >> hoursWorked;
    
    cout << "Enter your hourly wage:" << endl;
    cin >> wages;
    
    double moneyEarned = wages * hoursWorked;
    
    cout << "Wages earned: $" << moneyEarned << endl;
    
    return 0;
}