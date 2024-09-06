#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<double> bassWeight;
    vector<double> catfishWeight;
    vector<double> carpWeight;
    
    string input;
    
    do{
        string fishType;
        double fishWeight;
        
        cout << "Enter the type of fish (Bass, Catfish, or Carp):" << endl;
        cin >> fishType;
        
        cout << "Enter the fish's weight:" << endl;
        cin >> fishWeight;
        
        if(fishType == "Bass" || fishType == "bass"){
            bassWeight.push_back(fishWeight);
        } else if(fishType == "Catfish" || fishType == "catfish"){
            catfishWeight.push_back(fishWeight);
        } else if(fishType == "Carp" || fishType == "carp"){
            carpWeight.push_back(fishWeight);
        } else{
            cout << "Please enter a bass, catfish, or carp." << endl;
            return 0;
        }
        
        cout << "Are there more fish? Enter yes if so." << endl;
        cin >> input;
    } while(input == "yes");
    
    for(int i = 0; i < bassWeight.size(); i++){
        for(int i = 0; i < bassWeight.size() - 1; i++){
            if(bassWeight.at(i) < bassWeight.at(i + 1)){
                double temp = bassWeight.at(i);
                bassWeight.at(i) = bassWeight.at(i + 1);
                bassWeight.at(i + 1) = temp;
            }
        }
    }
    
    for(int i = 0; i < catfishWeight.size(); i++){
        for(int i = 0; i < catfishWeight.size() - 1; i++){
            if(catfishWeight.at(i) < catfishWeight.at(i + 1)){
                double temp = catfishWeight.at(i);
                catfishWeight.at(i) = catfishWeight.at(i + 1);
                catfishWeight.at(i + 1) = temp;
            }
        }
    }
    
    for(int i = 0; i < carpWeight.size(); i++){
        for(int i = 0; i < carpWeight.size() - 1; i++){
            if(carpWeight.at(i) < carpWeight.at(i + 1)){
                double temp = carpWeight.at(i);
                carpWeight.at(i) = carpWeight.at(i + 1);
                carpWeight.at(i + 1) = temp;
            }
        }
    }
    
    double bassAvg = 0;
    for(int i = 0; i < bassWeight.size(); i++){
        bassAvg = bassAvg + bassWeight[i];
        
    }
    
    bassAvg = bassAvg / bassWeight.size();
    
    double catfishAvg = 0;
    for(int i = 0; i < catfishWeight.size(); i++){
        catfishAvg = catfishAvg + catfishWeight[i];
        
    }
    
    catfishAvg = catfishAvg / catfishWeight.size();
    
    double carpAvg = 0;
    for(int i = 0; i < carpWeight.size(); i++){
        carpAvg = carpAvg + carpWeight[i];
        
    }
    
    carpAvg = carpAvg / carpWeight.size();
    
    cout << "The largest bass weighs " << bassWeight.at(0) << " pounds." << endl;
    cout << "The smallest bass weighs " << bassWeight.at(bassWeight.size() - 1) << " pounds." << endl;
    cout << "The average weight of bass is: " << bassAvg << " pounds." << endl;
    cout << "The largest catfish weighs " << catfishWeight.at(0) << " pounds." << endl;
    cout << "The smallest catfish weighs " << catfishWeight.at(catfishWeight.size() - 1) << " pounds." << endl;
    cout << "The average weight of catfish is: " << catfishAvg << " pounds." << endl;
    cout << "The largest carp weighs " << carpWeight.at(0) << " pounds." << endl;
    cout << "The smallest carp weighs " << carpWeight.at(carpWeight.size() - 1) << " pounds." << endl;
    cout << "The average weight of carp is: " << carpAvg << " pounds." << endl;
    
    return 0;
}