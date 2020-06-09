#include<bits/stdc++.h>
using namespace std;


/*
Making base class destructor virtual guarantees 
that the object of derived class is destructed 
properly, i.e., both base class and derived class 
destructors are called.

check the output removing virtual 
*/

#include<bits/stdc++.h>
using namespace std;

class one {
      int a;
public: 
      one() {
            cout << "one constructor\n";
      }
      virtual ~one() {
            cout << "one destructor\n";
      }
};

class two: public one {
      int b;
public:
      two() {
            cout << "two constructor\n";
      }
      ~two() {
            cout << "two destructor\n";
      }
};

class three: public two {
      int c;
public: 
      three() {
            cout << "three constructor \n";
      }
      ~three() {
            cout << "three destructor\n";
      }
};


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


    three *ptr3 = new three();
      two *ptr2 = ptr3;
      one *ptr1 = ptr3;
     
      /*
      delete ptr1; 
      or 
      delete ptr2;
      or 
      delete ptr2;

      output: 
      one constructor
      two constructor
      three constructor 
      three destructor
      two destructor
      one destructor
    */
}