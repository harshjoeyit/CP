#include<bits/stdc++.h>
using namespace std;


/*
Virtual Destructors

Deleting a derived class object using a pointer to a base class 
that has a non-virtual destructor results in undefined behavior. 
To correct this situation, the base class should be defined with 
a virtual destructor.

Making base class destructor virtual guarantees 
that the object of derived class is destructed 
properly, i.e., both base class and derived class 
destructors are called.

*/

#include <iostream>
class Base
{
public:
    virtual ~Base()
    // ~Base() 
    {
        std::cout << "Calling ~Base()\n";
    }
};
 
class Derived: public Base
{
private:
    int* m_array;
 
public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }
 
    virtual ~Derived() 
    // ~Derived() 
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};
 
int main()
{
    Derived *derived { new Derived(5) };
    Base *base { derived };
 
    delete base;
    // when delete is called on base, it checks if destructor is virtual
    // then it calls the child destructor, then base destructor 

    // else
    // it calls only base destructor 
 
    return 0;
}

// However, we really want the delete function to call Derived’s destructor 
// (which will call Base’s destructor in turn), otherwise m_array will not be deleted. We do this by making Base’s destructor virtual:


// uncomment virtual