#include<bits/stdc++.h>
using namespace std;

class Base1
{
public:
    Base1(){
        cout << "Base Constructor Called\n";
    }
    ~Base1(){
        cout << "Base Destructor called\n";
    }
};

class Derived1: public Base1
{
public:
    Derived1(){
        cout << "Derived constructor called\n";
    }
    ~Derived1(){
        cout << "Derived destructor called\n";
    }
};





class Base2
{ 
public:
    Base2(){
        cout << "Base Constructor Called\n";
    }
    virtual ~Base2(){
        cout << "Base Destructor called\n";
    }
};

class Derived2: public Base2
{
public:
    Derived2(){
        cout << "Derived constructor called\n";
    }
    ~Derived2(){
        cout << "Derived destructor called\n";
    }
};



int main()
{
    Base1 *b1 = new Derived1();
    delete b1;

    cout << endl;

    Derived1 *d1 = new Derived1();
    delete d1;

    cout << endl;
    
    Base2 *b2 = new Derived2();
    delete b2;
}