#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    
    cout << "Ask the magic 8-ball a question!" << endl;
    
    string question;
    getline(cin, question);
    
    //If user does not enter an input
    if(question.size() <= 0){ 
        cout << "Please enter in a question." << endl;
        return 0;
    }
    
    //Censor words
    string badword = "die";
    
    if(question.find(badword) != -1){ 
        cout << "Please try again with nicer words!" << endl;
        return 0;
    }
    
    //Allow repeated answers for repeated questions
    int index1 = question.size() / 2;
    int index2 = 0;
    
    cout << (int)question.at(index1) << endl;
    cout << (int)question.at(index2) << endl;
    
    int seed = (int)question.at(index1) + (int)question.at(index2);
    cout << seed << endl;
    
    srand(seed);
    int rnum = rand() % 6;
    
    //Using switch
    switch(rnum){
        case 0:
            cout << "Yes" << endl;
            break;
        case 1:
            cout << "No" << endl;
            break;
        case 2:
            cout << "Sign point to yes" << endl;
            break;
        case 3:
            cout << "I wouldn't do that" << endl;
            break;
        case 4:
            cout << "Sounds good to me" << endl;
            break;
        case 5:
            cout << "You're an adult, decide for yourself" << endl;
            break;
        
    }
    
    //Using If-else statements
    if(rnum == 0){
        cout << "Yes" << endl;
    } else if(rnum == 1){
        cout << "No" << endl;
    } else if(rnum == 2){
        cout << "Sign point to yes" << endl;
    } else if(rnum == 3){
        cout << "I wouldn't do that" << endl;
    } else if(rnum == 4){
        cout << "Sounds good to me" << endl;
    } else {
        cout << "You're an adult, decide for yourself" << endl;
    }
    
    return 0;
}