#include<bits/stdc++.h>
using namespace std;

class enemy 
{
    public:       
    // Pure Virtual Function
    // a pure virtual function has no bady and = 0 infront of it
    // if we define only void and no virtual before it then                        
    // since the other two classes inherit it they call the same function in the enemy class
    virtual void attack() = 0;
    // every class that inherits this 
    // class has to override every pure virtual function declared here
    
    // this is a virtua, not a pure virtual function 
    // classes may or may not override it
    virtual void kill() {
        cout << "parent kill\n";
    }       
};

class ninja : public enemy 
{
    public: 
    // overidding a pure virtual function is must
    void attack() 
    {
        // since the function defined is virtual these classes whwn inherit override it to use it  
        cout<<"ninja attack!"<<endl;  
    }

    void kill() {
        cout << "ninja kill\n";
    }
};

class monster : public enemy 
{
    public:
    void attack()
    {   
        // overrides the virtual attack function
        cout<<"monster attack!"<<endl;  
    }
};


int main()
{
    ninja n;
    monster m;

    enemy *enemy1 = &n;
    enemy *enemy2 = &m;

    enemy1-> attack();
    enemy2-> attack();

    enemy1->kill();
}