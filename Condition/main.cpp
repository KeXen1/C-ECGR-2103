#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    int x = 6;
    int y = 10;
    
    int z;
    
    if(x > y){
        z = 200;
    } else {
        z = 0;
    }
    
    //Shortcut for the if statement above
    
    z = (x > y)? 200 : 0; //Read as "Is x greater than y? If yes z = 200, if no z = 0"
    
    return 0;
}