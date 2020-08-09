#include<bits/stdc++.h>
using namespace std;

int x;
// returns referene to a global variable 
int &getRef() {
    return x;
}
string getName() {
    return "Di Caprio";
}
void printReference (const string& str) {
    cout << "immutable lvalue ref: " << str << endl;
}
void printReference (string&& str) {
    cout << "mutable rvalue ref: " << str << endl;
}

int main() {
    // An lvalue is an expression whose address can be taken,4
    // a locator value--essentially, an lvalue provides a (semi)permanent 
    // piece of memory. You can make assignments to lvalues. For example:
    int a;
    a = 10;
    // a is an lvalue
    
    cout << x << endl;
    // You can also have lvalues that aren't variables
    getRef() = 5;
    cout << x << endl;

    /*
    const string& name = getName(); // ok
    string& name = getName(); // NOT ok
    The intuition here is that you cannot use a "mutable" reference because, 
    if you did, you'd be able to modify some object that is about to disappear, 
    and that would be dangerous. Notice, by the way, that holding on to a const 
    reference to a temporary object ensures that the temporary object isn't immediately destructed. 
    This is a nice guarantee of C++, but it is still a temporary object, so you don't want to modify
    */



    // An expression is an rvalue if it results in a temporary object
    string name = getName();
    // getName is a rvalue
    // as it returns a temporary string constructed in getName
    // here we're assigning from a temporary object, not from some value that has a fixed location


    // In C++11, however, there's a new kind of reference, an "rvalue reference", 
    // that will let you bind a mutable reference to an rvalue, but not an lvalue. 
    // In other words, rvalue references are perfect for detecting if a value is 
    // temporary object or not. Rvalue references use the && syntax instead of 
    // just &, and can be const and non-const, just like lvalue references, 
    // although you'll rarely see a const rvalue reference (as we'll see, mutable 
    // references are kind of the point):

    // both ok
    const string&& name1 = getName(); 
    string&& name2 = getName();

    cout << name1 << " " << name2 << endl;
    name2 = "Da Vinci";
    cout << name2 << endl;


    /*
    Now the behavior gets interesting--the printReference function taking a 
    const lvalue reference will accept any argument that it's given, whether 
    it be an lvalue or an rvalue, and regardless of whether the lvalue or rvalue 
    is mutable or not. 
    However, in the presence of the second overload, printReference taking 
    an rvalue reference, it will be given all values except mutable rvalue-references. 
    In other words, if you write:
    */
    printReference("alex");
    printReference(getName());
    string s = "OMG";
    printReference(s);


    // using rvalue refrence and lvalue refrence we can determine if an object is temporary of permanent 

    // how can we use it?
    // >>> Move constructor and move assignment operator

    // https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

}