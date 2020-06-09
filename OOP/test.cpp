#include<iostream> 
using namespace std;

string name, character; 
int birthYear, age;
string villian, hero, weapon;
string country, city;
string snack; 
int i = 0;

string getWelcomeName() {
    string arr[] = {"sweety", "smarty", "samsher", "party boy"};
    i = (i + 1) % 4;
    return arr[i];
}
void startline() {
    if(age < 10) {
        cout << "Once upon a time ";
    } else if(age < 13) {
        cout << "Before there were Avengers on Earth ";
    } else {
        cout << "Long time back ";
    }
    cout << "there lived a " << character << " in hills of " << city << ". ";
    cout << "He was just " << age << " years old. ";
    cout << "He was famous in the town by the name of " << name << ".";
}
void midpart1() {
    cout << "The town of was very healthy and prosperous.";
    cout << " But then came " << villian << ".";
    cout << " He took away the food and all the gold of the people.";
    cout << " The streets were on fire. People were crying. Some of the villagers died when " << villian << " attacked.";
}
void midpart2() {
    cout << "In these hard times people of the town called upon " << name << " \"The Mightiest Hero\". ";
    cout << name << " thought it was a good time to take help of " << hero << ".";
    cout << " Together the enter the Castle of " << villian << ", killed the bodyguards. ";
    cout << name << " took his " << weapon << " and was about kill " << villian << ". ";
}
void endpart() {
    cout << " But then, " << hero << " stopped him and said \"Lets Give him a warning\". ";
    cout << name << " warned him took away all everything he had looted!";
    cout << " The town was happy as before.";
    cout << " Later that day " << name << " and " << hero << " enjoyed " << snack << " near the lake talking about how they beat " << villian << ".";
}
void Story() {
    startline();
    cout << "\n";    
    midpart1();
    cout << "\n";
    midpart2();
    cout << "\n";
    endpart();
    cout << "\n";
    cout << "..................................................................\n";
    cout << "..................................................................\n";
    cout << ".............................The End..............................\n";
}

int main() {

    int t;
    cout << "\nHow many times do you want to play? ";
    cin >> t;
    while(t--) {
        cout << "\n\n";
        cout << ".................................................................\n";
        cout << "Hello " << getWelcomeName() << " ;-)" << endl; 
        cout << "..................................................................\n";
        cout << "$$$.............Welcome to " << " \"Legends of Delpur..............$$$\"!\n";
        cout << "..................................................................\n";
        cout << "..................................................................\n";
        
        cout << "We would like to know your name - ";
        cin.ignore();
        getline(cin, name);
        cout << "..................................................................\n";
        cout << "..................................................................\n";
        cout << "So, " << name << " get ready for some action!\n";
        cout << "We would like to a know a few things first\n";
        cout << "..................................................................\n";
        cout << "..................................................................\n";

        cout << "Are you a \"Prince\" or a \"Princess\"? ";
        getline(cin, character);
        cout << "..................................................................\n";
        

        cout << "Which year you we born in? ";
        cin >> birthYear;
        cout << "..................................................................\n";
        age = 2020 - birthYear;

        cout << "Which Hero is your favourite? ";
        cin.ignore();
        getline(cin, hero);
        cout << "..................................................................\n";

        cout << "Which Villian is your favourite? ";
        getline(cin, villian);
        cout << "..................................................................\n";

        cout << "Choose your weapon? ";
        getline(cin, weapon);
        cout << "..................................................................\n";

        cout << "Enter a city you want to visit - ";
        getline(cin, city);
        cout << "..................................................................\n";

        cout << "What do you like to eat? ";
        getline(cin, snack);
        cout << "..................................................................\n";
        cout << "..................................................................\n";
        cout << "..................................................................\n";
        cout << "..................................................................\n";
        cout << "...........Here is a story of a brave" << character << "..........\n";
        cout << "..................................................................\n";
        cout << "..................................................................\n";

        Story();
    }        
}
