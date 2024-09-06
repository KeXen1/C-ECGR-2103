#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x1 = 0.0;
    double y1 = 1.0;
    
    double x2 = 2.0;
    double y2 = 3.0;
    
    /*
    double xdiff = x2 - x1;
    double ydiff = y2 - y1;
    
    double xpow = pow(xdiff, 2.0);
    double ypow = pow(ydiff, 2.0);
    
    double powSum = xpow + ypow;
    
    double dist = sqrt(powSum);
    */
    
    double dist = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
    
    cout << "Distance is " << dist << endl;
    
    return 0;
}