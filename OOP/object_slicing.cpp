
#include<iostream>
#include<vector>

class Base
{
protected:
    int m_value{};
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};
 
class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    virtual const char* getName() const { return "Derived"; }
};
 

// sliced
void printName(const Base base) // note: base passed by value, not reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

// not sliced 
void displayName(const Base& base) // note: base passed by value, not reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

int main()
{
    Derived derived{ 5 };
    // std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
 
    Base &ref{ derived };
    // std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';
 
    Base *ptr{ &derived };
    // std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    printName(derived);
    displayName(derived);

    // object slicing with vectors
    // Note: If we make vector<Base> v and store Derived object, then they will be sliced
    // Note: Vector of reference cannote be made, since references have to be  initialized, not reassigned
    // Only option is vector of pointers 
    std::vector<Base *> v{};

    // b and d can't be anonymous objects
    Base b{ 5 }; 
	Derived d{ 6 };
 
	v.push_back(&b); // add a Base object to our vector
	v.push_back(&d); // add a Derived object to our vector
 
	// Print out all of the elements in our vector
	for (const auto* element : v)
		std::cout << "I am a " << element->getName() 
        << " with value " << element->getValue() << '\n';
 


    // FrankenObjects 

    Derived d1{ 5 };
    Derived d2{ 6 };
    Base &b{ d2 };
 
    b = d1; // this line is problematic
    
    // Since b points at d2, and we’re assigning d1 to b, you might think that the result
    //  would be that d1 would get copied into d2 -- and it would, if b were a Derived. 
    // But b is a Base, and the operator= that C++ provides for classes isn’t virtual 
    // by default. Consequently, only the Base portion of d1 is copied into d2. 

}