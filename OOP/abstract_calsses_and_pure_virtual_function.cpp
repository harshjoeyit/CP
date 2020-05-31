#include<bits/stdc++.h>
using namespace std;

class enemy 
{
    public:   // apure virtual function has no bady and =0 infront of it
    virtual void attack()=0;   // if we define only void and no virtual before it then                        
     // since the other twp classes inherit it they call the same function in the enemy class
    
};

class ninja : public enemy 
{
    public: 
    void attack() // ovewrriting a pure virtual function is must
    {       
        cout<<"ninja attack!"<<endl;  // since the function defined is virtual these classes whwn inherit overrite it 
    }
};

class monster : public enemy 
{
    public:
    void attack()
    {
        cout<<"monster attack!"<<endl;  // overriter the virtual attack function
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
}