#include <string>
#include <iostream>
 
// This Animal is an abstract base class
class Animal {
protected:
    std::string m_name;
public:
    Animal(const std::string& name): m_name(name) { }
 
    const std::string& getName() const { return m_name; }
    // note that speak is a pure virtual function
    virtual const char* speak() const = 0;  
    virtual ~Animal() = default;
};
 
// Not: definition cannot be inline (in the class itself)
// Has to be outside the class 
const char* Animal::speak() const {
    return "buzz"; // some default implementation
}
 

class Dragonfly: public Animal {
public:
    Dragonfly(const std::string& name) : Animal{name} { }
 
    // this class is no longer abstract because we defined this function
    const char* speak() const override {
        // use Animal's default implementation
        return Animal::speak(); 
    }
};
 
int main() {
    Dragonfly dfly{"Sally"};
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
 
    return 0;
}