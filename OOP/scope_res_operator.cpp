
#include<bits/stdc++.h>
using namespace std;

// 1) To access a global variable when there is a local variable with same name:
// 2) To define a function outside a class.
// 3) To access a class’s static variables. (to initialize them outside the class)


// 4) In case of multiple Inheritance:

class A  { 
protected: 
    int x; 
public: 
    A() { x = 10; } 
}; 
  
class B  { 
protected: 
    int x; 
public: 
    B() { x = 20; } 
}; 
  
class C: public A, public B { 
public: 
   void fun()  { 
      cout << "A's x is " << A::x; 
      cout << "\nB's x is " << B::x; 
   } 
}; 
  
// 6) Refer to a class inside another class:
class outside { 
public: 
      int x; 
      class inside { 
      public: 
            int x; 
            static int y;  
            int foo(); 
  
      }; 
}; 

int outside::inside::y = 5; 


int main() {
      // 5) For namespace
      std::cout << "Hello" << std::endl;
}