#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    
    const int MAX_GUESSES = 3;
    string userInput = "y";
    int score = 0;
    
    while(userInput == "y"){
        int computerNumber = (rand() % 10) + 1;
        int userGuess;
        int numGuesses = 0;
        bool userWon = false;
        
        while(numGuesses < MAX_GUESSES){
            cout << "Guess the number between 1 and 10: " << endl;
            cin >> userGuess;
            
            if (userGuess == computerNumber){
                userWon = true;
                numGuesses = MAX_GUESSES;
                score ++;
            } else if (userGuess > computerNumber){
                cout << "Lower." << endl;
            } else{
                cout << "Higher." << endl;
        }
        
        numGuesses = numGuesses ++;
        
        }
        
        if(userWon){
            cout << "You guessed correctly" << endl;
        } else{
            cout << "You lose. How sad. It was " << computerNumber << "." << endl;
        }
        
        do{
        cout << "Try again? Enter 'y' for yes or 'n' for no" << endl;
        cin >> userInput;
        }while(userInput != "y" && userInput != "n");
    }
    
    cout << "Your score is: " << score << endl;
    
    return 0;
}