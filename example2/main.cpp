#include <iostream>

using namespace std;

int main(){
        double houseValue = 20000.0;
        double percentDown;
        
        cout << "What percent down payment? Enter a value less than 1.9:" << endl;
        cin >> percentDown;
        
        double downPayment = houseValue * percentDown;
        
        cout << "You need to pay: $" << downPayment << endl;
        
        return 0;
}