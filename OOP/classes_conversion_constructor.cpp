


#include<bits/stdc++.h>
using namespace std;

/*
In C++, if a class has a constructor which can 
be called with a single argument, then this 
constructor becomes conversion constructor 
because such a constructor allows automatic 
conversion to the class being constructed.

The compiler uses these constructors to perform 
implicit class-type conversions
*/

class MyClass {
    int a, b;
public:
    MyClass(int i): a(i), b(i) {
    }
    MyClass(int x, int y): a(x) , b(y) { 
    }
    void display() {
        cout << "a: " << a << " b: " << b << "\n";
    }
};


class AnotherClass  {
    int j;
public: 
    AnotherClass(int x = 0) : j(x) {
    } 
    // Overloading conversion operator
    operator MyClass() const {
        return MyClass(j);
    }
};

void display_MyClass(MyClass obj) {
    obj.display();
}

int main() {
    MyClass obj(10);
    obj.display();

    // single parameter 
    obj = 20;
    obj.display();

    // more than 1 prameter, braced list 
    obj = {30, 40};
    obj.display();

    // works because of conversion constructor 
    display_MyClass(50);

    AnotherClass obj2(75);
    // possible because conversion operator overloaded in B
    display_MyClass(obj2);
}
