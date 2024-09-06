#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int startingNumBacteria = 200;
    int numDays;
    
    cout << "How many days have past?" << endl;
    cin >> numDays;
    
    int totalBacteria = startingNumBacteria * pow(2, numDays);
    
    cout << "You started with " << startingNumBacteria << " bacteria..." << endl;
    cout << "After " << numDays << " days you have " << totalBacteria << " bacteria!" << endl;
    
    return 0;
}