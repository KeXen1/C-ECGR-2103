#include <iostream>
#include "lib/my_math.h"

#ifndef MY_MATH_H
#define MY_MATH_H

#include <iostream>

#define PI 3.14

#define ERROR_MSG "This is an Error Message"

int abs(int value){
    if (value < 0) {
    value = value * -1;
    }
    
    return value;
}

int pow(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    
    int result = base;
    for(int i = 0; i < exponent; i++){
        result = result * base;
    }
    
    return result;
}

double circleArea(double radius){
    return pow(radius, 2) * PI;
}

int printError(){
    cout << "Error" << endl;
}

#endif