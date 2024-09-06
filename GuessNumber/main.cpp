#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
    
    int computerNumber = (rand() % 10) + 1;
    int userGuess;
    
    cout << "Guess the number between 1 and 10: " << endl;
    cin >> userGuess;
    
    if (userGuess == computerNumber){
        cout << "You guessed correctly!" << endl;
        
        return 0;
    } else if (userGuess > computerNumber){
        cout << "Lower." << endl;
        cin >> userGuess;
    } else{
        cout << "Higher." << endl;
        cin >> userGuess;
    }
    
    if (userGuess == computerNumber){
        cout << "You guessed correctly!" << endl;
        
        return 0;
    } else if (userGuess > computerNumber){
        cout << "Lower." << endl;
        cin >> userGuess;
    } else{
        cout << "Higher." << endl;
        cin >> userGuess;
    }
    
    cout << "You lose. How sad. It was " << computerNumber << "." << endl;
    
    return 0;
}
    