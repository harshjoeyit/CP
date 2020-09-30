

#include<bits/stdc++.h>
using namespace std;

class Entity {
public:
    int x, y;
    
    Entity() : x(0), y(0) { }
    Entity(int x, int y) : x(x), y(y) { }
};

int main() {
    Entity ent1;                // Uses the default constructor, so x=0 and y=0
    Entity ent2();              // Note: Declares a function prototype =, doesnot call the constructor 
    Entity ent3(1, 2);          // Made constructor, so x=1 and y=2
    Entity ent4 = Entity();     // Value initialization, Correct way for ent2
    Entity ent5 = Entity(2, 3); // Value initialization, Made constructor, so x=2 and y=3
}