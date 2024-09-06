#include <iostream>
#include <vector>

using namespace std;

const char BLANK_SPACE = ' ';
const char P1 = 'X';
const char P2 = 'O';

char tttb[3][3] = {{BLANK_SPACE, BLANK_SPACE, BLANK_SPACE},
                       {BLANK_SPACE, BLANK_SPACE, BLANK_SPACE},
                       {BLANK_SPACE, BLANK_SPACE, BLANK_SPACE}};
                       
void drawBoard();
bool isWinner(cost char& c);
void getXYFromUser(unsigned int& x, unsigned int& y, char c)

int main(){
    
    // game conditions
    bool xWinner, oWinner, boardFull;
    // user input variables
    unsigned int x,y;
    
    drawBoard(tttb);
    
    while(!boardFull){
        
        // Get X input
        //======================================================================
        validInput = false;
        do{
            cout << "Where do you want to place an X?" << endl;
            cout << "Row: ";
            cin >> x;
            cout << "Col: ";
            cin >> y;
            
            if(x >= 3 || y >= 3){
                cout << "Invalid input" << endl;
                continue;
            }
            
            if(tttb[x][y] != BLANK_SPACE){
                cout << "Location already taken." << endl;
                continue;
            }
            
            validInput = true;
        }while(!validInput);
        
        tttb[x][y] = P1;
        // End get X input
        //======================================================================
        
        drawBoard(tttb);

        if(isWinner(P1, tttb)){
            cout << "X's wins!" << endl;
            break;
        }
        // End check x winner
        //======================================================================
        
        // Get O input
        //======================================================================
        validInput = false;
        do{
            cout << "Where do you want to place an O?" << endl;
            cout << "Row: ";
            cin >> x;
            cout << "Col: ";
            cin >> y;
            
            if(x >= 3 || y >= 3){
                cout << "Invalid input" << endl;
                continue;
            }
            
            if(tttb[x][y] != BLANK_SPACE){
                cout << "Location already taken." << endl;
                continue;
            }
            
            validInput = true;
        }while(!validInput);
        
        tttb[x][y] = P2;
        // End get O input
        //======================================================================
    
        drawBoard(tttb);

        if(isWinner(P2, tttb)){
            cout << "O's wins!" << endl;
            break;
        }
        // End check o winner
        //======================================================================
        
        // Check if board is full
        //======================================================================
        boardFull = true;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(tttb[i][j] == BLANK_SPACE)
                    boardFull = false;
            }
        }
        
        if(boardFull){
            cout << "Tie!" << endl;
            continue;
        }
        // End check if board is full
        //======================================================================
    }
    
    return 0;
}

void drawBoard(char gameBoard[][3]){
    for(int i = 0; i < 3; i++){
        cout << gameBoard[i][0] << "|"
             << gameBoard[i][1] << "|"
             << gameBoard[i][2] << endl;
        
        if(i != 2) cout << "-----" << endl;
    }
}

bool isWinner(char c, char tttb[][3]){
    bool xWinner = false;
    // Check rows
    xWinner = xWinner || (tttb[0][0] == c &&
                          tttb[0][1] == c &&
                          tttb[0][2] == c);
    xWinner = xWinner || (tttb[1][0] == c &&
                          tttb[1][1] == c &&
                          tttb[1][2] == c);
    xWinner = xWinner || (tttb[2][0] == c &&
                          tttb[2][1] == c &&
                          tttb[2][2] == c);
    // Check columns
    xWinner = xWinner || (tttb[0][0] == c &&
                          tttb[1][0] == c &&
                          tttb[2][0] == c);
    xWinner = xWinner || (tttb[0][1] == c &&
                          tttb[1][1] == c &&
                          tttb[2][1] == c);
    xWinner = xWinner || (tttb[0][2] == c &&
                          tttb[1][2] == c &&
                          tttb[2][2] == c);
    // Check diagonals
    xWinner = xWinner || (tttb[0][0] == c &&
                          tttb[1][1] == c &&
                          tttb[2][2] == c);
    xWinner = xWinner || (tttb[0][2] == c &&
                          tttb[1][1] == c &&
                          tttb[2][0] == c);
                          
    return xWinner;
}

/*
#include <iostream>
#include <vector>
using namespace std;
void drawBoard(char gameBoard[][3]);
bool isWinner(char c, char tttb[][3]);
int main(){
    
    char tttb[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};
    
    // game conditions
    bool xWinner, oWinner, boardFull, validInput;
    // user input variables
    unsigned int x,y;
    
    drawBoard(tttb);
    
    while(!boardFull){
        
        // Get X input
        //======================================================================
        validInput = false;
        do{
            cout << "Where do you want to place an X?" << endl;
            cout << "Row: ";
            cin >> x;
            cout << "Col: ";
            cin >> y;
            
            if(x >= 3 || y >= 3){
                cout << "Invalid input" << endl;
                continue;
            }
            
            if(tttb[x][y] != ' '){
                cout << "Location already taken." << endl;
                continue;
            }
            
            validInput = true;
        }while(!validInput);
        
        tttb[x][y] = 'X';
        // End get X input
        //======================================================================
        
        drawBoard(tttb);
        if(isWinner('X', tttb)){
            cout << "X's wins!" << endl;
            break;
        }
        // End check x winner
        //======================================================================
        
        // Get O input
        //======================================================================
        validInput = false;
        do{
            cout << "Where do you want to place an O?" << endl;
            cout << "Row: ";
            cin >> x;
            cout << "Col: ";
            cin >> y;
            
            if(x >= 3 || y >= 3){
                cout << "Invalid input" << endl;
                continue;
            }
            
            if(tttb[x][y] != ' '){
                cout << "Location already taken." << endl;
                continue;
            }
            
            validInput = true;
        }while(!validInput);
        
        tttb[x][y] = 'O';
        // End get O input
        //======================================================================
    
        drawBoard(tttb);
        if(isWinner('O', tttb)){
            cout << "O's wins!" << endl;
            break;
        }
        // End check o winner
        //======================================================================
        
        // Check if board is full
        //======================================================================
        boardFull = true;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(tttb[i][j] == ' ')
                    boardFull = false;
            }
        }
        
        if(boardFull){
            cout << "Tie!" << endl;
            continue;
        }
        // End check if board is full
        //======================================================================
    }
    
    return 0;
}
void drawBoard(char gameBoard[][3]){
    for(int i = 0; i < 3; i++){
        cout << gameBoard[i][0] << "|"
             << gameBoard[i][1] << "|"
             << gameBoard[i][2] << endl;
        
        if(i != 2) cout << "-----" << endl;
    }
}
bool isWinner(char c, char tttb[][3]){
    bool xWinner = false;
    // Check rows
    xWinner = xWinner || (tttb[0][0] == c &&
                          tttb[0][1] == c &&
                          tttb[0][2] == c);
    xWinner = xWinner || (tttb[1][0] == c &&
                          tttb[1][1] == c &&
                          tttb[1][2] == c);
    xWinner = xWinner || (tttb[2][0] == c &&
                          tttb[2][1] == c &&
                          tttb[2][2] == c);
    // Check columns
    xWinner = xWinner || (tttb[0][0] == c &&
                          tttb[1][0] == c &&
                          tttb[2][0] == c);
    xWinner = xWinner || (tttb[0][1] == c &&
                          tttb[1][1] == c &&
                          tttb[2][1] == c);
    xWinner = xWinner || (tttb[0][2] == c &&
                          tttb[1][2] == c &&
                          tttb[2][2] == c);
    // Check diagonals
    xWinner = xWinner || (tttb[0][0] == c &&
                          tttb[1][1] == c &&
                          tttb[2][2] == c);
    xWinner = xWinner || (tttb[0][2] == c &&
                          tttb[1][1] == c &&
                          tttb[2][0] == c);
                          
    return xWinner;
}