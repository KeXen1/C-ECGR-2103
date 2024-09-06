#include <iostream>
#include <vector> //vector
#include <stdlib.h> //rand
#include <time.h> //time

using namespace std;

int main(){
    
    const int NUM_CARS = 4;
    const int NUM_PASSENGERS_PER_CAR = 4;
    
    const int SIZE = NUM_CARS * NUM_PASSENGERS_PER_CAR;
    
    srand(time(0));
    
    //==================================================
    double heights[SIZE];
    for(int i = 0; i < SIZE; i++){
        //4 - 7
        heights[i] = (double)(rand() % 30 + 40) / 10.0;
        cout << heights[i] << endl;
    }
    //==================================================
    
    bool safeToRide = true;
    for(int i = 0; i < SIZE; i++){
        if(heights[i] >= 6.5){
            cout << "The person at index " << i << " is too tall to ride." << endl;
            safeToRide = false;
        } 
    }
    
    if(safeToRide){
        cout << "Roller coaster is safe to run." << endl;
    }
    
    return 0;
}