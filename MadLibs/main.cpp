#include <iostream>

using namespace std;

int main(){
    
    string adjective1, adjective2, birdType, houseRoom, verbPast, verb, relativeName, noun1, liquid, ingVerb1, bodyPartPlural, pluralNoun, ingVerb2, noun2;
    
    cout << "Please type in an adjective:" << endl;
    cin >> adjective1; 
    cout << "Please type in another adjective:" << endl;
    cin >> adjective2; 
    cout << "Please type in a type of bird:" << endl;
    cin >> birdType; 
    cout << "Please type in a room in a house:" << endl;
    cin >> houseRoom; 
    cout << "Please type in a verb in past tense:" << endl;
    cin >> verbPast; 
    cout << "Please type in a verb:" << endl;
    cin >> verb; 
    cout << "Please type in a relative's name:" << endl;
    cin >> relativeName; 
    cout << "Please type in a noun:" << endl;
    cin >> noun1; 
    cout << "Please type in a liquid:" << endl;
    cin >> liquid; 
    cout << "Please type in a verb ending in -ing:" << endl;
    cin >> ingVerb1; 
    cout << "Please type in a part of body (plural):" << endl;
    cin >> bodyPartPlural; 
    cout << "Please type in a plural noun:" << endl;
    cin >> pluralNoun; 
    cout << "Please type in another verb ending in -ing" << endl;
    cin >> ingVerb2; 
    cout << "Please type in another noun:" << endl;
    cin >> noun2;
    
    cout << "It was a " << adjective1 << ", cold November day." << endl;
    cout << "I woke up to the " << adjective2 << " smell of " << birdType << " roasting in the " << houseRoom << " downstairs." << endl;
    cout << "I " << verbPast << " down the stairs to see if I could help " << verb << " the dinner." << endl;
    cout << "My mom said, \"See if " << relativeName << " needs a fresh " << noun1 << ".\"" << endl;
    cout << "So I carried a tray of glasses full of " << liquid << " into the " << ingVerb1 << " room." << endl;
    cout << "When I got there, I couldn't believe my " << bodyPartPlural << "!" << endl;
    cout << "There were " << pluralNoun << " " << ingVerb2 << " on the " << noun2 << "!" << endl;
    
    return 0;
}