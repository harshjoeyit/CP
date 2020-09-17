
#include<iostream> 
using namespace std; 
  

class B 
{ 
public:	 
	B(const char* str = "\0") //default constructor 
	{ 
		cout << "Constructor called" << endl; 
	}	 
	
	B(const B &b) //copy constructor 
	{ 
		cout << "Copy constructor called" << endl; 
	} 
}; 


class Test  
{ 
private: 
    int x; 
    static int count; 
public:
    Test(int i = 0) : x(i) { cout << "const\n"; }
    Test(const Test& rhs) : x(rhs.x) { ++count; cout << "copy const\n"; } 
    static int getCount() { return count; } 
}; 
  
int Test::count = 0; 
  
Test fun()  {
    return Test();
} 
  
int main()  { 

    B ob = "copy me"; 
	return 0; 

    /*
    Constructor called
    
    Why copy constructor is not called?
    According to theory, when the object “ob” is being constructed, 
    one argument constructor is used to convert “copy me” to a temporary 
    object & that temporary object is copied to the object “ob”. So the statement

    B ob = "copy me"; 
    should be broken down by the compiler as

    B ob = B("copy me");
    However, most of the C++ compilers avoid such overheads of creating 
    a temporary object & then copying it.
    */

    Test a = fun(); 
    /* copy elision happens here too*/
    cout<< Test::getCount(); 
    return 0; 

} 