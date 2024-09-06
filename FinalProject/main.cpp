#include <iostream>
#include <cstring>
#include <string.h>
#include <time.h>
#include <cctype>
#include <limits>
#include <sstream>

using namespace std;

void drawBoard(char gameBoard[][6]);

int uppercaseIt(string s);

bool spellCheck(string s1, string s2);

bool sameString(string s1, string s2);

int main(){
    srand(time(0));
    const int END_SPACE = 39;
    const int WINNING_SPACE = 40;
    char gameBoard[WINNING_SPACE][6] = {"     ", "     ", "     ", "L    ", 
    "     ", "     ", "     ", "O    ", "     ", "C    ", "O    ", "L    ", 
    "I    ", "     ", "O    ", "L    ", "O    ", "I    ", "C    ", "I    ", 
    "     ", "O    ", "L    ", "     ", "I    ", "     ", "L    ", "C    ",
    "L    ", "     ", "     ", "     ", "     ", "C    ", "I    ", "     ", 
    "     ", "I    ", "C    ", "     "};
    int numberOfPlayers;
    int winner;
    int playerOldPos[4] = {1, 1, 1, 1};
    int playerNewPos[4] = {1, 1, 1, 1};
    bool isWinner = false;
    bool inputFail;
    string spin;
    string str2 = "SPIN";
    
    // Player Selection, Symbols, & Board Placements
    //=========================================================================
    
    cout << "Symbols:" << endl <<"==================================" << endl 
    << " Player 1 = 1" << endl << " Player 2 = 2" << endl <<  " Player 3 = 3" 
    << endl <<  " Player 4 = 4" << endl <<  " Ladder = L" << endl <<  
    " Ladder End = I" << endl <<  " Chute = C" 
    << endl <<  " Chute End = O" << endl << 
    "==================================" << endl;
    
    do{
        cout << "Enter number of players from 2 to 4" << endl;
        cin >> numberOfPlayers;
        cout << endl << endl;
        
        inputFail = cin.fail();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while((numberOfPlayers < 2 || numberOfPlayers > 4) || inputFail == true);
    
    switch(numberOfPlayers){
        case 2:
            strcpy(gameBoard[0]," 1");
            strcat(gameBoard[0],"2  ");
            break;
        case 3:
            strcpy(gameBoard[0]," 1");
            strcat(gameBoard[0],"2");
            strcat(gameBoard[0],"3 ");
            break;
        case 4:
            strcpy(gameBoard[0]," 1");
            strcat(gameBoard[0],"2");
            strcat(gameBoard[0],"3");
            strcat(gameBoard[0],"4");
            break;
        default:
            cout << "Error Message" << endl;
    }
    
    drawBoard(gameBoard);
    //=========================================================================
    
    // Turns
    //=========================================================================
    while(!isWinner){
        for(int i = 0; i < numberOfPlayers; i++){
            
            do{
                cout << endl << endl << "Player " << i + 1 << 
                ", type SPIN to spin the spinner!" << endl;
                cin >> spin;
                
            } while(sameString(spin, str2));
            
            int roll = (rand() % 6) + 1;
            cout << endl << endl << "Player " << i + 1 << " rolled " << roll << "." << endl;
            
            playerOldPos[i] = playerNewPos[i];
            playerNewPos[i] += roll;
            
            switch(i){
                case 0:
                    char temp1[10]; 
                    strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                    temp1[1] = ' ';
                    strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                    strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                    temp1[1] = '1';
                    strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                    break;
                case 1:
                    strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                    temp1[2] = ' ';
                    strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                    strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                    temp1[2] = '2';
                    strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                    break;
                case 2:
                    strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                    temp1[3] = ' ';
                    strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                    strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                    temp1[3] = '3';
                    strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                    break;
                case 3:
                    strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                    temp1[4] = ' ';
                    strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                    strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                    temp1[4] = '4';
                    strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                    break;
                default:
                    cout << "Error Message" << endl;
            }
            
            // Prevents advancing over 40th space
            //=================================================================
            if(playerNewPos[i] > WINNING_SPACE){
                switch(i){
                    case 0:
                        char temp1[10];
                        strcpy(temp1, gameBoard[END_SPACE]);
                        temp1[1] = '1';
                        strcpy(gameBoard[END_SPACE], temp1);
                        break;
                    case 1:
                        strcpy(temp1, gameBoard[END_SPACE]);
                        temp1[2] = '2';
                        strcpy(gameBoard[END_SPACE], temp1);
                        break;
                    case 2:
                        strcpy(temp1, gameBoard[END_SPACE]);
                        temp1[3] = '3';
                        strcpy(gameBoard[END_SPACE], temp1);
                        break;
                    case 3:
                        strcpy(temp1, gameBoard[END_SPACE]);
                        temp1[4] = '4';
                        strcpy(gameBoard[END_SPACE], temp1);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
                
            }
            
            drawBoard(gameBoard);
            //=================================================================
            
            // Chutes
            //=================================================================
            if(playerNewPos[i] == 10){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 8;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 8." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 8;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 8."
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 8;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 8." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 8;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 8." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            
            if(playerNewPos[i] == 19){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 15;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 15." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 15;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 15."
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 15;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 15." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 15;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 15." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            
            if(playerNewPos[i] == 28){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 8;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 11." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 11;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 11."
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 11;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 11." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 11;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 11." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            
            if(playerNewPos[i] == 34){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 17;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 17." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 17;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 17."
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 17;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 17." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 17;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 17." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            
            if(playerNewPos[i] == 39){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 22;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 22." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 22;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 22."
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 22;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 22." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 22;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "No! You landed on a chute. Move to space 22." 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            //=================================================================
            
            // Ladders
            //=================================================================
            if(playerNewPos[i] == 4){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 13;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 13!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 13;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 13!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 13;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 13!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 13;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 13!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
                
            if(playerNewPos[i] == 12){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 20;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 20!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 20;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 20!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 20;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 20!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 20;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 20!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
                
            if(playerNewPos[i] == 16){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 18;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 18!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 18;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 18!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 18;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 18!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 18;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 18!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
                
            if(playerNewPos[i] == 23){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 25;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 25!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 25;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 25!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 25;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 25!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 25;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 25!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            
            if(playerNewPos[i] == 29){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 35;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 35!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 35;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 35!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 35;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 35!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 35;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 35!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
                
            if(playerNewPos[i] == 27){
                switch(i){
                    case 0:
                        char temp1[10];
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 38;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[1] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[1] = '1';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 38!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 1:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 38;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[2] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[2] = '2';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 38!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 2:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 38;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[3] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[3] = '3';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 38!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    case 3:
                        playerOldPos[i] = playerNewPos[i];
                        playerNewPos[i] = 38;
                        strcpy(temp1, gameBoard[playerOldPos[i] - 1]);
                        temp1[4] = ' ';
                        strcpy(gameBoard[playerOldPos[i] - 1], temp1);
                        strcpy(temp1, gameBoard[playerNewPos[i] - 1]);
                        temp1[4] = '4';
                        strcpy(gameBoard[playerNewPos[i] - 1], temp1);
                        cout << "You landed on a ladder! Move to space 38!" 
                        << endl;
                        drawBoard(gameBoard);
                        break;
                    default:
                        cout << "Error Message" << endl;
                }
            }
            //=================================================================
            
            // Winner!!
            //=================================================================
            if(playerNewPos[i] >= WINNING_SPACE){
                isWinner = true;
                winner = i + 1;
                break;
            }
            
        }
        
    }
    
    cout << "Player " << winner << " wins!" << endl;
    
    return 0;
}

void drawBoard(char gameBoard[][6]){
    for(int i = 32; i <= 39; i++){
        if(i == 32){
            cout << 
            "-----------------------------------------------------------------"
            << endl << "| " << gameBoard[i] << " | ";
        } else if(i == 39){
            cout << gameBoard[i] << " | " << endl << 
            "-----------------------------------------------------------------"
            << endl;
        }    else{
            cout << gameBoard[i] << " | ";
        }
    }
    
    for(int i = 24; i <= 31; i++){
        if(i == 24){
            cout << "| " << gameBoard[i] << " | ";
        } else if(i == 31){
            cout << gameBoard[i] << " | " << endl << 
            "-----------------------------------------------------------------"
            << endl;
        }    else{
            cout << gameBoard[i] << " | ";
        }
    }
    
    for(int i = 16; i <= 23; i++){
        if(i == 16){
            cout << "| " << gameBoard[i] << " | ";
        } else if(i == 23){
            cout << gameBoard[i] << " | " << endl << 
            "-----------------------------------------------------------------"
            << endl;
        }    else{
            cout << gameBoard[i] << " | ";
        }
    }
    
    for(int i = 8; i <= 15; i++){
        if(i == 8){
            cout << "| " << gameBoard[i] << " | ";
        } else if(i == 15){
            cout << gameBoard[i] << " | " << endl << 
            "-----------------------------------------------------------------"
            << endl;
        }    else{
            cout << gameBoard[i] << " | ";
        }
    }
    
    for(int i = 0; i <= 7; i++){
        if(i == 0){
            cout << "| " << gameBoard[i] << " | ";
        } else if(i == 7){
            cout << gameBoard[i] << " | " << endl << 
            "-----------------------------------------------------------------"
            << endl;
        }    else{
            cout << gameBoard[i] << " | ";
        }
    }
}

int uppercaseIt(string s){
    int converted;
    for (int i = 0; i < s.length(); i++){
        converted += toupper(s[i]);
    }
    return converted;
}

bool spellCheck(string s1, string s2){
    for (int i = 0; i < s1.length(); i++){
        if(toupper(s1[i]) != toupper(s2[i])){
            return false;
        }
    }
    return true;
}

bool sameString(string s1, string s2){
    if((uppercaseIt(s1) == uppercaseIt(s2)) && (spellCheck(s1,s2) == true)){
        return false;
    }
return true;
}