#ifndef MY_MATH_H
#define MY_MATH_H

#include <iostream>

#define PI 3.14

#define ERROR_MSG "This is an Error Message"

using namespace std;

// computes power function
int pow(int base, int exponent);

// return absolute value
int abs(int value);

// prints "Error" to terminal
int printError();

#endif