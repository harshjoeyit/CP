#include<iostream>
using namespace std;

void f3(int a=4,int b=5)
{
    cout<<"sum: "<<a+b<<endl;;
}

string read(const string &);

void f4()
{
    cout<<"f4 called: "<<endl;
}


void f1(int a)
{
    cout<<"calling f1"<<endl;
    void f2(int);
    f2(a);  // call for f2() can only be made from f1() since it is only visible inside f1()
    bool read = false;
    //string s = read();  // read cannot be used as a function
}

int main()
{
    f1(2);
    // f2();  cannot call it from here since ti is not visible in this scope
    f4();
    f3();  // IMP: can be called without arguments
    f3(2);  // this value goes to the first parameters the second one remains unchanged (remains default initialized)
    return 0;
}

void f2(int b)
{
    cout<<"f2 called: "<<b<<endl;
}

