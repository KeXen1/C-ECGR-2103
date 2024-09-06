#include <iostream>

using namespace std;

int main(){
    int pricePerSqft = 244;
    int houseSqft;
    
    cin >> houseSqft;
    
    int houseValue = pricePerSqft * houseSqft;
    
    cout << "The price of your house is: " << endl;
    cout << houseValue << endl;
    
    return 0;
}