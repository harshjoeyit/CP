#include<iostream>
#include<cstring>
using namespace std;

class student {
    string name;
    int SRNo;
public: 
    student(string _name = "no name", int _SRNo = 0): name(_name), SRNo(_SRNo) {
    }
    // Default constructor does only shallow copy (object point to same memory)
    // Deep copy is possible only with user defined copy constructor (different memory locations)

    // if copy constructor is not explicitly defined in a class then compiler generates 
    // implicitly like the one below 
    // student(const student &obj) = default;       
    
    // we can also construct our owns copy constructor  
    // We need to define our own copy constructor only if an object has pointers or any 
    // runtime allocation of the resource like file handle, a network connection..etc.
    student(const student &obj) {
        this->name = obj.name;
        this->SRNo = obj.SRNo;
        cout << "copy constructor called\n";
    }
    // arg must be a const reference since (complier creates a temporary object 
    // that cannot be bound to a non-const reference, just like (int &r = 10) doesnt work )
    // returns a reference to the copy created 
    student &operator = (const student &obj) {
        cout << "assignment operator overlaod\n";
        this->name = obj.name;
        this->SRNo = obj.SRNo;
        return *this;
    }
    void print() {
        cout << name << " " << SRNo << endl; 
    }
};


class String {
    char *s;
    int size;
public: 
    String(const char *str = NULL);  
    // object must be passed by a const reference    
    String(const String&);
    void print();
    void change(const char *);
    ~String() {
        delete []s;
    }

};
String::String(const char *str) {
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
String::String(const String& old_str) {
    size = old_str.size;
    s = new char[size+1];
    strcpy(s, old_str.s);
}
void String::change(const char *str) {
    delete []s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
void String::print() {
    cout << s << endl;
}


class Complex { 
private: 
    int real, imag; 
public: 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
    Complex operator + (const Complex &); 
    Complex& operator = ( const Complex & );
    void print(); 
}; 
Complex Complex::operator + ( const Complex &obj ) {  
    Complex res; 
    res.real = real + obj.real; 
    res.imag = imag + obj.imag; 
    return res; 
} 
// assignment operator must return reference to the left hand operand (current or this)
// the synthesized copy assignment operator just looks like this one 
Complex& Complex:: operator = (const Complex &rhs) {
    real = rhs.real;
    imag = rhs.imag;
    return *this;           // return reference to the left hand operator which is impicitly the *this object 
};


class Test { 
    int *ptr; 
public: 
    Test (int i = 0) { 
        ptr = new int(i); 
    } 
    // Test & operator = (const Test &t) {
    //     // check for self assignment
    //     if(this != &t) {
    //         *ptr = (*t.ptr);
    //     }
    //     return *this;
    // }
    void setValue (int i) { 
        *ptr = i; 
    } 
    void print() { 
        cout << *ptr << endl; 
    } 
}; 


int main() {
    student *s1 = new student("rajeev", 13);
    // copy constructor is called when a new object is created as a copy of another object
    student s2 = *s1;
    s2.print();
    student s4(*s1);
    s4.print();
    // assignment operator is called when a previously declared object is assigned
    student s3;
    s3 = *s1;
    s3.print();

    String str1("Justin Timberlake");
    String str2 = str1;
    
    str1.print();
    str2.print();

    str2.change("JT");

    // comment the copy constructor to use the defalut one
    // defalut copy const - copies the pointers to 
    // str1 and str2 have different memory locations so 
    // one changes other does not 
    str1.print();
    str2.print();

    /*
    Can we make copy constructor private?
    
    Yes, a copy constructor can be made private. When we make a 
    copy constructor private in a class, objects of that class
    become non-copyable. This is particularly useful when our 
    lass has pointers or dynamically allocated resources. 
    In such situations, we can either write our own copy constructor 
    like above String example or make a private copy constructor so that 
    users get compiler errors rather than surprises at runtime. 
    

    Why argument to a copy constructor must be passed as a reference?
    
    A copy constructor is called when an object is passed by value. 
    Copy constructor itself is a function. So if we pass an argument by 
    value in a copy constructor, a call to copy constructor would be made 
    to call copy constructor which becomes a non-terminating chain of calls. 
    Therefore compiler doesn’t allow parameters to be passed by value.
    
    */


    // operator overloading 
    Complex c1(10, 5), c2(2, 4) , c3( 1 , 1);
    // An example call to "operator+" 
    Complex c4 = c1 + c2 + c3;  
    c4.print(); 
    Complex c5 = c4;
    c5.print();

    Test t1(5); 
    Test t2; 
    // assignment operator implicitly created and used 
    t2 = t1; 
    // t1 and t2 use the same memory location (pointers are copied )
    t2.setValue(10);
    // both change 
    t1.print();
    t2.print();

    // uncomment the own assignment operator 
    /*
    1)  Do not allow assignment of one object to other object. We can create our 
        own dummy assignment operator and make it private.
    2)  Write your own assignment operator that does deep copy.
    */
}