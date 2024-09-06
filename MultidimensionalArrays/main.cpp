#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    /*  VECTOR, ARRAYS, AND C STRING NOTES
    
    VECTORS
    - vector.resize()
    - vector.push_back()
    - vector.pop_back()
    - vector.back()
    - Written as;
        vector<int> vec1;
    
    ARRAYS:
    - Written as:
        array[];
    
    SWAPPING VARIABLES
    - Use tempVar to swap
    
    VECTORS VS. ARRAYS
    - Vectors.at() checks for errors
    - Arrays do not check for errors
    - Vectors[] do not check for errors
    - Neither will compile error b/c none of them has anything to do with 
    compiler, only error message
    - Arrays DO NOT have access to properties(.reize, .size,.pop_back), ONLY
    VECTORS DO
    
    MULTIDIMENSIONAL ARRAYS
    - Written as:
        int array[1][2];
    - Has rows and columns 
    
    MULTIPLE VECOTRS
    - Do not combine into one larger one
    - Can have different data types
    - Should have same amount of elements
    - Written as:
        vector<int> vec1;
        vector<int> vec2;
    
    C STRING
    - Written as:
        char firstName[10] = "Henry";
    - [10] is the element size
    - Only stops when reaches a null character(\0)
    - EX:
        char catBreed[20] = "Persian";
        THIS WILL ONLY PRINT 7 CHARACTERS, NOT 19 CHARACTERS
        BC IT STOPS AT NULL(It's hidden not written)
    - However, if we do this at the end... WE MUST HAVE NULL!!  
        = {'H', 'e', 'n', 'r', 'y', '\0'}
    
    C STRING FUNCTIONS
    - MUST HAVE "DOUBLE QUOTES"
    - strcpy(destStr, sourceStr) - destStr is where the sourceStr will be placed AND REPLACES
    - strncpy(destStr, sourceStr, numChars) - same as before but only replaces the first 'numChars' numbers MUST HAVE NULL
    - strcat(destStr, sourceStr) - copies but puts it at the END WHERE NULL STARTS
    - strncat(destStr, sourceStr, numChars) - copies from amount of 'numChars', puts at end, and appends a null automatically
    */
    
    
    
    //#1
    /*int array[3][2] = {1, 2, 3, 4, 5, 6};
    */
    
    //#2
    /*int array[3][2] = {{1, 2},
                        {3, 4},
                        {5, 6}};
                        
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    
    //Tic-Tac-Toe Example
    char tictactoeBoard[3][3] = {{' ', ' ', ' '},
                                 {' ', ' ', ' '},
                                 {' ', ' ', ' '}};
                                 
    
    bool isWinner;
    while(isWinner){
    
    int x,y;
    cout << "Where do you want to place an X?" << endl;
    cin >> x;
    cin >> y;
    
    for(int i = 0; i < 3; i++){
        cout << tictactoeBoard[i][0] << "|"
             << tictactoeBoard[i][1] << "|"
             << tictactoeBoard[i][2] << endl;
         
        if (i != 2){
            cout << endl << "-----" << endl;
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tictactoeBoard[i][j] != tictactoeBoard[i][j-1])
            break;
        }
    }
    
    tictactoeBoard[x][y] = 'X';
    
    cout << "Where do you want to place an O?" << endl;
    cin >> x;
    cin >> y;
    
    tictactoeBoard[x][y] = 'O';
    
    for(int i = 0; i < 3; i++){
        cout << tictactoeBoard[i][0] << "|"
             << tictactoeBoard[i][1] << "|"
             << tictactoeBoard[i][2] << endl;
         
        if (i != 2){
            cout << endl << "-----" << endl;
        }
    }
    
    }
    
    return 0;
}