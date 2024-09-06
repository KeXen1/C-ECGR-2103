#include <iostream>

using namespace std;

int main(){

    double totalSquareft = 5000.0;
    double sqftPersonalSpace = 5.0;
    double sqftAttractionsBooths;
    
    cout << "Enter square footage required by the attractions and booths:" << endl;
    cin >> sqftAttractionsBooths;
    
    int tickets = (totalSquareft - sqftAttractionsBooths) / sqftPersonalSpace;
    
    cout << "Maximum number of tickets that can be sold: " << tickets << " tickets" << endl;
    
    return 0;
}mkd