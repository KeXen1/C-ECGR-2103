#include <iostream>
#include <vector> //vector

using namespace std;

int main(){
    
    vector<double> pumpkins = {10, 11, 9, 12};
    vector<string> names = {"1", "2", "3", "4"};
    
    /*
    string input;
    do{
        string tempName;
        double tempWeight;
        
        cout << "Enter the contestant's name:" << endl;
        cin >> tempName;
        cout << "Enter the contestant's pumpkin's weight:" << endl;
        cin >> tempWeight;
        
        pumpkins.push_back(tempWeight);
        names.push_back(tempName);
        
        cout << "Are there more contestant? Enter yes if so." << endl;
        cin >> input;
    } while(input == "yes");
    */
    
    for(int i = 0; i < pumpkins.size(); i++){
        cout << pumpkins.at(i) << " ";
    
    
    cout << endl; 
    
        for(int i = 0; i < pumpkins.size() - 1; i++){
            if(pumpkins.at(i) < pumpkins.at(i + 1)){
                double temp = pumpkins.at(i);
                pumpkins.at(i) = pumpkins.at(i + 1);
                pumpkins.at(i + 1) = temp;
            }
        }
    
        for(int i = 0; i < pumpkins.size(); i++){
            cout << pumpkins.at(i) << " ";
        }
    }
    
    cout << endl;
    
    cout << "First place: " << pumpkins.at(0) << endl;
    cout << "Second place: " << pumpkins.at(1) << endl;
    cout << "Third place: " << pumpkins.at(2) << endl;
    
    return 0;
}