#include <iostream>

using namespace std;

int main(){
    double winningWeight = 0.0;
    string winningName;
    
    string input;
    do{
        string tempName;
        double tempWeight;
        
        cout << "Enter the contestant's name:" << endl;
        cin >> tempName;
        cout << "Enter the contestant's pumpkin's weight:" << endl;
        cin >> tempWeight;
        
        if(tempWeight > winningWeight){
            winningWeight = tempWeight;
            winningName = tempName;
        }
        
        cout << "Are there more contestant? Enter yes if so." << endl;
        cin >> input;
    } while(input == "yes");
    
    cout << "The winner is " << winningName << "." << endl;
    
    return 0;
}

    
    