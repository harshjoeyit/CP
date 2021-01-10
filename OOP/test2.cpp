#include<bits/stdc++.h>
using namespace std;

class P {
public: 
    void print() {
        cout << "P class method";
    }
};

class A: virtual public P {
public: 
    void print()  {
        cout << "A class method";
    }
};

class B: virtual public P {
public: 
    void print() {
        cout << "B class method";
    }
};

class C:virtual public A, virtual public B {
public: 
};

int main() {
    C *p = new C();
    p->print();
}