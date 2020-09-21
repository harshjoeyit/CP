
IMP OUTPUTS 

using namespace std;    
  
class Test 
{ 
  static int i; 
  int j; 
}; 
  
int Test::i; 
  
int main() 
{ 
    cout << sizeof(Test); 
    return 0; 
} 

/*
Output: 4 (size of integer)
static data members do not contribute in size 
of an object. So ‘i’ is not considered in size 
of Test. Also, all functions (static 
and non-static both) do not contribute in size.
*/


#include<iostream> 
  
using namespace std; 
class Base1 { 
 public: 
     Base1() 
     { cout << " Base1's constructor called" << endl;  } 
}; 
  
class Base2 { 
 public: 
     Base2() 
     { cout << "Base2's constructor called" << endl;  } 
}; 
  
class Derived: public Base1, public Base2 { 
   public: 
     Derived() 
     {  cout << "Derived's constructor called" << endl;  } 
}; 
  
int main() 
{ 
   Derived d; 
   return 0; 
} 

/*
Base1’s constructor called
Base2’s constructor called
Derived’s constructor called

In case of Multiple Inheritance, constructors 
of base classes are always called in derivation 
order from left to right and Destructors are 
called in reverse order.
*/



class base { 
    int arr[10];      
}; 
  
class b1: public base { }; 
  
class b2: public base { }; 
  
class derived: public b1, public b2 {}; 
  
int main(void) 
{  
  cout<<sizeof(derived); 
  getchar(); 
  return 0; 
} 

/*
Output: If integer takes 4 bytes, then 80.

Since b1 and b2 both inherit from class base, 
two copies of class base are there in class derived. 
This kind of inheritance without virtual causes 
wastage of space and ambiguities.
*/

/*
Virtual inheritance is a C++ technique that ensures 
only one copy of a base class's member variables are 
inherited by grandchild derived classes.
*/


#include<iostream> 
using namespace std; 
  
class base { 
  int arr[10];      
}; 

// virtual inheritence, to reduce memory wastage 
class b1: virtual public base { }; 
  
class b2: virtual public base { }; 
  
class derived: public b1, public b2 {}; 
  
int main(void) 
{  
  cout<<sizeof(derived); 
  getchar(); 
  return 0; 
} 

/*
 virtual base classes 
are used to save space and avoid ambiguities in such 
cases. For example, following program prints 48. 
8 extra bytes are for bookkeeping information stored 
by the compiler (See this for details)
*/




class P { 
public: 
  void print() 
  { cout <<" Inside P::"; } 
}; 

class Q : public P { 
public: 
  void print() { cout <<" Inside Q"; 
  } 
}; 

class R: public Q { 
}; 

int main(void)  { 
  R r; 

  r.print(); 
  return 0; 
} 


/*
Output:
Inside Q

The print function is not defined in class R. 
So it is looked up in the inheritance hierarchy. 
print() is present in both classes P and Q, which 
of them should be called? The idea is, if there is 
multilevel inheritance, then function is linearly 
searched up in the inheritance heirarchy until a 
matching function is found.
*/



class Base 
{ 
public: 
  Base() 
  { 
    fun(); //note: fun() is virtual 
  } 
  virtual void fun() 
  { 
    cout<<"\nBase Function"; 
  } 
}; 
  
class Derived: public Base 
{ 
public: 
  Derived(){} 
  virtual void fun() 
  { 
    cout<<"\nDerived Function"; 
  } 
}; 
  
int main() 
{ 
  Base* pBase = new Derived(); 
  delete pBase; 
  return 0; 
} 

/*
When a virtual function is called directly or indirectly 
from a constructor (including from the mem-initializer 
for a data member) or from a destructor, and the object 
to which the call applies is the object under construction 
or destruction, the function called is the one defined in 
the constructor or destructor’s own class or in one of its 
bases, but not a function overriding it in a class derived 
from the constructor or destructor’s class, or overriding 
it in one of the other base classes of the most derived object.
*/



class Test 
{ 
public: 
  Test(); 
}; 
  
Test::Test()  { 
    cout<<"Constructor Called \n"; 
} 
  
int main() 
{ 
    cout<<"Start \n"; 
    Test t1(); 
    cout<<"End \n"; 
    return 0; 
}

/*
Output:
Start
End

Note that the line “Test t1();” is not a constructor 
call. Compiler considers this line as declaration of 
function t1 that doesn’t recieve any parameter and 
returns object of type Test.
*/


class Test { 
    int value; 
public: 
    Test (int v = 0) {value = v;} 
    int getValue() { return value; } 
}; 
  
int main() { 
    const Test t;   
    cout << t.getValue(); 
    return 0; 
}


/*
Compilation Error

Since t is contant object 
no function shoud be able to change the contents of t 
so we need to make changes such function does not modify the 
memeber variables 

chnaged to 
int getValue() const { return value; } 
*/



class Test { 
    int &t; 
public: 
    Test (int &x) { t = x; } 
    int getT() { return t; } 
}; 
  
int main() 
{ 
    int x = 20; 
    Test t1(x); 
    cout << t1.getT() << " "; 
    x = 30; 
    cout << t1.getT() << endl; 
    return 0; 
} 


/*
Since t is a reference 
it must be initialized int the initializer list of the 
constructor like,

Test (int &x):t(x) {  } 
*/



class Test1 { 
    int y; 
}; 
  
class Test2 { 
    int x; 
    Test1 t1; 
public: 
    operator Test1() { return t1; } 
    operator int() { return x; } 
}; 
  
void fun ( int x)  { }; 
void fun ( Test1 t ) { }; 
  
int main() { 
    Test2 t; 
    fun(t); 
    return 0; 
} 


/*
Ambiguous overloading, compiler cannot dicide 

There are two conversion operators defined in the Test2 
class. So Test2 objects can automatically be converted 
to both int and Test1. Therefore, the function call 
fun(t) is ambiguous as there are two functions void 
fun(int ) and void fun(Test1 ), compiler has no way 
to decide which function to call. In general, conversion 
operators must be overloaded carefully as they may lead to ambiguity.
*/


class Test1 
{ 
    int x; 
public: 
    void show() {  } 
}; 
  
class Test2 
{ 
    int x; 
public: 
    virtual void show() {  } 
}; 
  
int main(void) 
{ 
    cout<<sizeof(Test1)<<endl; 
    cout<<sizeof(Test2)<<endl; 
    return 0; 
} 


/*
There is only one difference between Test1 and Test2. 
show() is non-virtual in Test1, but virtual in Test2. 
When we make a function virtual, compiler adds an extra 
pointer vptr to objects of the class. Compiler does this 
to achieve run time polymorphism
*/


template <class S, class T> class Pair 
{ 
private: 
	S x; 
	T y; 
/* ... */
}; 

template <class S> class Element 
{ 
private: 
	S x; 
/* ... */
}; 

int main () 
{ 
	Pair <Element<int>, Element<char>> p; 
	return 0; 
} 

/*
Output:

Compiler Error: '>>' should be '> >' within a nested template argument list
When we use nested templates in our program, we must put a space between two 
closing angular brackets, otherwise it conflicts with 
operator >>. For example, following program compiles fine.
*/


class Test 
{ 
private: 
public: 
	int x; 
    // no issues 
	void setX (int x) { Test::x = x; } 
	void print() { cout << "x = " << x << endl; } 
}; 

int main() 
{ 
	Test obj; 
	int x = 40; 
	obj.setX(x); 
	obj.print();
    // wrong
    // cout << Test::x << endl;
    return 0;
} 

/*
Output = 40
Works just fine
Scope resolution operator can always be used to access a class member when
it is made hidden by local variables. So the line “Test::x = x” is same as “this->x = x”
*/



class A 
{ 
    // data members of A 
public: 
    A ()           { cout << "\n A's constructor"; /* Initialize data members */ } 
    A (const A &a) { cout << "\n A's Copy constructor";  /* copy data members */} 
    A& operator= (const A &a) {   
      // Assignemt Operator
        // Handle self-assignment: 
        if(this == &a) return *this; 
  
        cout << "\n A's Assignment Operator";  return *this; 
    } 
}; 
  
class B  { 
    A a; 
public: 
    B(A &a) { this->a = a; cout << "\n B's constructor"; } 
}; 
  
int main() { 
    A a1; 
    B b(a1); 
    return 0; 
} 


/*
 A's constructor
 A's constructor
 A's Assignment Operator
 B's constructor
The first line of output is printed by the statement “A a1;” in main().
The second line is printed when B’s member ‘a’ is initialized. This is important.
The third line is printed by the statement “this->a = a;” in B’s constructor.
The fourth line is printed by cout statement in B’s constructor.

If we take a closer look at the above code, the constructor of class B is not 
efficient as member ‘a’ is first constructed with default constructor, and then 
the values from the parameter are copied using assignment operator. It may be a 
concern when class A is big, which generally is the case with many practical classes. 
See the following optimized code.

W change B class 
*/

class B { 
    A a; 
public: 
    // we use initializer list 
    B(A &a):a(a) {  cout << "\n B's constructor"; } 
}; 


/*
Output 

 A's constructor
 A's Copy constructor
 B's constructor
*/


/*
Q. What is the differnce b/w to object instantiation 

A a[2];           
Output: 
constructor called 1
constructor called 2
destructor called 2
destructor called 1

A *ptr = new A[2];
constructor called 1
constructor called 2

We never see the detructor being called in second case because delete is never used 


Why destructors are called in reverese order ?

Example - 
    A a;
    B b(a);

In the above code, the object ‘b’ (which is created after ‘a’), 
may use some members of ‘a’ internally. So destruction of ‘a’ before ‘b’ may create problems. 
Therefore, object ‘b’ must be destroyed before ‘a’.
*/



/*
A non - static member function 

can be called using using :: like 
A :: print(), inside the class or its child class 

but outside the class only static functions can be called this way
and we we have to make object to ccall non static function 
*/

/*
Run time polymorphism, with virtual functions works 
with pointers only like

base *bp = new derived();
bp->print()

or 

derived d;
base *bp = &d;
bp->print()

*/



// SUPER IMPORTANT

class Base  
{ 
public: 
    void fun()      { cout << "Base::fun() called"; } 
    void fun(int i) { cout << "Base::fun(int i) called"; } 
}; 
  
class Derived: public Base  
{ 
public: 
    void fun(char x)   { cout << "Derived::fun(char ) called"; } 
}; 
  
int main()  
{ 
    Derived d;
    // calls the char version 
    // all other methods hidden 
    // since method with same name created 
    // also all the overloads are hidden 
    d.fun(65);
    // d.fun() - gives compile error 
    return 0; 
} 


/*
Output: Compiler Error.
In the above program, fun() of base class is not accessible in the derived class. 
If a derived class creates a member method with name same as one of the methods in base class, 
then all the base class methods with this name become hidden in derived class 
*/



#include<iostream> 
using namespace std; 
class Base  
{ 
   protected: 
      int x; 
   public: 
      Base (int i=10){ x = i;} 
}; 
  
class Derived : public Base  
{ 
   public: 
      Derived (int i):x(i) { } 
      void print() { cout << x ; } 
}; 
  
int main() 
{ 
    Derived d(10); 
    d.print(); 
} 

/*
The members of base class can only be initialized through a constructor call of base class. 
We can assign x = i in the constructor body but 
not initialize using initializer list 

instead we should have called Base(i) in the initializer list 
*/



#include<stdlib.h> 
#include<iostream> 

using namespace std; 

class Test { 
public: 
	void* operator new(size_t size); 
	void operator delete(void*); 
	Test() { cout<<"\n Constructor called"; } 
	~Test() { cout<<"\n Destructor called"; } 
}; 

void* Test::operator new(size_t size) 
{ 
	cout<<"\n new called"; 
	void *storage = malloc(size); 
	return storage; 
} 

void Test::operator delete(void *p ) 
{ 
	cout<<"\n delete called"; 
	free(p); 
} 

int main() 
{ 
	Test *m = new Test(); 
	delete m; 
	return 0; 
} 

/*
 new called
 Constructor called
 Destructor called
 delete called
*/


#include <iostream> 
using namespace std; 

template <int N> 
class A { 
int arr[N]; 
public: 
virtual void fun() { cout << "A::fun()"; } 
}; 

class B : public A<2> { 
public: 
void fun() { cout << "B::fun()"; } 
}; 

class C : public B { }; 

int main() { 
A<2> *a = new C; 
a->fun(); 
return 0; 
} 


/*
B::fun()
In general, the purpose of using templates in C++ is to avoid code redundancy.  
We create generic classes (or functions) that can be used for any datatype as long 
\as logic is identical. Datatype becomes a parameter and an instance of class/function 
is created at compile time when a data type is passed. C++ Templates also allow nontype 
(a parameter that represents a value, not a datatype) things as parameters.

In the above program, there is a generic class A which takes a nontype parameter N. 
The class B inherits from an instance of generic class A. The value of N for this 
instance of A is 2. The class B overrides fun() of class A<2>. The class C inherits 
from B. In main(), there is a pointer ‘a’ of type A<2> that points to an instance of 
C. When ‘a->fun()’ is called, the function of class B is executed because fun() is virtual 
and virtual functions are called according to the actual object, not according to pointer. 
In class C, there is no function ‘fun()’, so it is looked up in the hierarchy and found in class B.

*/




// This program works just fine 
#include <iostream> 
using std::cout; 
class main 
{ 
public: 
main() { cout << "ctor is called\n";} 
~main() { cout << "dtor is called\n";} 
};

// Global object
// main m;      - works fine

int main() 
{ 
class main m;
// instead if we write
// main m;
// the compile error 
}


/*Note: `main` is not a reserved keyowrd in C++ */




#include<iostream> 
using namespace std; 
int main() 
{ 
	int x = 1 , y = 1, z = 1; 
	cout << ( ++x || ++y && ++z ) << endl; //outputs 1; 
	cout << x << " " << y << " " << z ;	 //x = 2 , y = 1 , z = 1; 
	return 0; 
} 


// || operator stops execution if condition is true 

...............................Continue From SET - 22  ......................................


