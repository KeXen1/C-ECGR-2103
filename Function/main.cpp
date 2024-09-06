#include <iostream>

using namespace std;

int pow(int base, int exponent){
    
    if(exponent == 0){
        return 1;
    }
    
    int result = base;
    for(int i = 0; i < exponent - 1; i++){
        result = result * base;
        
    }
    
    return result;
}

void printData(int a, int b){
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
 }


int main(){
    int a = 10;
    int b = 2;
    
    printData(a, b);
    int c = pow(a, b);
    
    cout << c << endl;
    
    return 0;
}