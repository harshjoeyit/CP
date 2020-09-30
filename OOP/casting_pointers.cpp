
#include<iostream>
#include<vector>

class Base {
protected:
    int m_value{};
 
public:
    Base(int value): m_value{ value } { }
 
    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};
 
class Derived: public Base {
public:
    Derived(int value): Base{ value } {}
 
    virtual const char* getName() const { return "Derived"; }
};
 


int main() {
    Derived *d1 = new Derived(6);
    std::cout << d1->getName() << "\n";

    // This process is sometimes called upcasting
    Base *b = d1;
    std::cout << b->getName() << "\n";

    // Derived *d1 = b;     Invalid conversion 
    // downcasting not allowed, since it is not always certain that b points to derived object 

    // we can make it possibel if b points to a derived object 

    // most common use for dynamic casting is for converting base-class pointers 
    // into derived-class pointers. This process is called downcasting.

    Derived *d2 = dynamic_cast<Derived *>(b);

    std::cout << d2->getName() << "\n";


    Base *b2 = new Base(4);
    Derived *d3 = dynamic_cast<Derived *>(b2);

    // Gives unexpected result
    std::cout << d3->getName() << "\n";
}