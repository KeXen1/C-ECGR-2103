#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    //VECTOR CODE (SMARTER THAN ARRAYS)
    vector<int> quizzes;
    //OR
    // vector<int> quizzes = {10, 70, 80, 90, 80};
    
    quizzes.push_back(100);
    quizzes.push_back(90);
    quizzes.push_back(80);
    quizzes.push_back(100);
    
    quizzes.pop_back();
    
    cout << quizzes.at(1) << endl;
    cout << quizzes[1] << endl;
    
    int avg = 0;
    for(int i = 0; i < quizzes.size(); i++){
        avg = avg + quizzes[i];
        
    }
    
    avg = avg / quizzes.size();
    
    cout << avg << endl;
    
    /* //ARRAYS CODE
    const unsigned int NUM_QUIZZES = 11;
    int quizzes[NUM_QUIZZES];
    //OR
    // int quizzes[] = {10, 70, 80, 90, 80};
    
    quizzes[0] = 100;
    quizzes[1] = 80;
    quizzes[2] = 80;
    quizzes[3] = 70;
    quizzes[4] = 80;
    quizzes[5] = 40;
    quizzes[6] = 20;
    quizzes[7] = 80;
    quizzes[8] = 100;
    quizzes[9] = 100;
    quizzes[10] = 100;
    
    int avg = 0;
    int minval = 100;
    for(int i = 0; i < NUM_QUIZZES; i++){
        if(quizzes[i] < minval){
            minval = quizzes[i];
            cout << "New lowest values is: " << minval << endl;
        }
        avg = avg + quizzes[i];
        
    }
    avg = avg - minval;
    avg = avg / (NUM_QUIZZES - 1);
    
    cout << avg << endl;
    */
    
    return 0;
}