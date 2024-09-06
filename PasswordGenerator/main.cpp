#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main(){
    srand(time(0));
    
    string randAdj;
    string randNoun;
    
    string pw = "";
    
    int rnum = rand() % 5; //0 - 4, 5 unique digits
    int rnum2 = rand() % 5;
    
    switch(rnum){
        case 0:
            randAdj = "Large";
            pw = pw + "Large";
            break;
        case 1:
            randAdj = "Small";
            pw = pw + "Small";
            break;
        case 2:
            randAdj = "Hairy";
            pw = pw + "Hairy";
            break;
        case 3:
            randAdj = "Sleepy";
            pw = pw + "Sleepy";
            break;
        case 4:
            randAdj = "Alcholic";
            pw = pw + "Alcholic";
            break;
        default:
            cout << "Warning: Should not be here!" << endl;
    }
    
    switch(rnum2){
        case 0:
            randNoun = "Dog";
            pw = pw + "Dog";
            break;
        case 1:
            randNoun = "Cat";
            pw = pw + "Cat";
            break;
        case 2:
            randNoun = "Politician";
            pw = pw + "Politician";
            break;
        case 3:
            randNoun = "Student";
            pw = pw + "Student";
            break;
        case 4:
            randNoun = "Bus";
            pw = pw + "Bus";
            break;
    }
    
    int randNum1 = rand() % 10; //0 - 9, 10 unique digits
    int randNum2 = rand() % 10;
    int randNum3 = rand() % 10;
    
    pw = pw + to_string(randNum1) + to_string(randNum2) + to_string(randNum3);
    
    cout << "Your password is: " << randAdj << randNoun << randNum1 << randNum2 << randNum3 << endl;
    
    cout << "Your password is: " << pw << endl;
    
 return 0;    
}