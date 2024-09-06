#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string possibleWifiPassword;
    string MG = "MG";
    int wifiNum = 100000;
    
    for(int i = 100000; i < 1000000; i++){
        cout << MG << wifiNum << endl;
        wifiNum++;
    }
    
    return 0;
}