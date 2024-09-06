#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
   
    int reel1 = (rand() % 4) + 1;
    int reel2 = (rand() % 4) + 1;
    int reel3 = (rand() % 4) + 1;
    
    cout << reel1 << " " << reel2 << " " << reel3 << endl;
    
    if(reel1 != reel2){
        cout << "Fail!" << endl;
    } else if (reel1 == reel3){
        cout << "Jackpot! You win!" << endl;
    }
        else{
            cout << "You lose!" << endl;
        }
    
    return 0;
}
