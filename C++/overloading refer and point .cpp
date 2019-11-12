#include<iostream>
using namespace std;

typedef int number;

void f0(number n)
{
    cout<<"f0 called";
}
/*void f0(const number n)
{
    cout<<"f6 called";
} */                       // error since const int and int in parameter are considered as same  REDECLARATION

void f1(const number &n) // prefers constant values
{
    cout<<"f1 called: ";
}
void f1(number &n)   // prefers non constant values
{
    cout<<"f2 called: ";
}
void f2(const number *n)//prefers const
{
    cout<<"f3 called: ";
}
void f2(number *n)
{
    cout<<"f4 called: ";
}
int main()
{
    const number x=12;
    number a=10;

    number *p1=&a;
    const number *p2=&a;
    const number *p3=&x;

    f1(x);  // goes to parameter having const
    f1(a);   // goes to a non-const parameter
cout<<endl;
    f2(p1);  // goes to non-const
    f2(p2);   // goes to const
    f2(p3); // goes to const
cout<<endl;

     f0(x);  //const goes to non constant
     f0(a);  // non const goes to non constant


    return 0;
}
