#include<bits/stdc++.h>
using namespace std;

class Base1;

class Base1 {
    int x; 
public:
    static int si;
    Base1() = default;
    Base1(int i): x(i) {
        cout<<"Base1 constructor called"<<endl;
    }
    void foo1() {
        cout<<"base foo1 called"<<endl;
    }
    // virtual function
    virtual void foo2() {
        cout<<"base foo2(virtual) called"<<endl;
    }
    int getVal() {
        return x;
    }
    virtual ~Base1() {
        cout<<"Base1 destructor called"<<endl;
    }
};
//static member of base1 class 
int Base1::si = 111;



class Derived1: public Base1 {
    int y = si;     // derived class can access the static member of the base class 
public: 
    Derived1() = default;
    Derived1(int _x, int _y): Base1(_x), y(_y) {
        cout<<"Derived1 constructor called"<<endl;
    }
    void foo1() {
        cout<<"derived foo1 called"<<endl;
    }
    // may or may not override , virtual functions are implicitly overridden when inherited 
    void foo2() override {
        cout<<"derived foo2 called"<<endl;
    }
    int getder() {
        return y;
    }
    ~Derived1() {
        cout<<"Derived1 destructor called"<<endl;
    }
};


void CallFoo( Base1& B ) {
    B.foo1();
    B.foo2();
}


class Noderive final {
// can't be base class to any derived class 
};

class Last final : Base1 {
// class is inherited but cannot be a base class 
};


int main() {
    Base1 b1(10);
    CallFoo(b1);
    cout<<endl;

    Derived1 d1(20,99);
    CallFoo(d1);
    cout<<endl;

    cout<<"x: " <<b1.getVal()<<" y: " <<d1.getder()<<endl;
    b1 = d1;        
    // base portion of the derived object is copy assigned and rest is ignored 
    // vice-versa not possible 
    // d1 = b1 not possible as their is no derived portion in b1 to copy 
    cout<<"x: " <<b1.getVal()<<" y: " <<d1.getder()<<endl;
    cout<<endl;

    // changes the value in base class static object
    // Derived1::si = 999; 

    cout<<"base si: "<< b1.si <<" "<< Base1::si<<endl;
    cout<<"der si: "<< d1.si <<" "<< Derived1::si<<endl;
    cout<<endl;
}