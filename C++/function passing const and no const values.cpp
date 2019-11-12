#include<iostream>
using namespace std;

typedef int number;

void f1(const number &n) // can take constant as well as non constant values
{
    cout<<"const number &n called "<<endl;
}
void f1(number &n)   // can not take up constant values
{
    cout<<"nunber &n called "<<endl;
}
void f3(const number *n)//can take constant as well as non constant values
{
    cout<<"const number *n called "<<endl;
}
void f3(number *n)
{
    cout<<"number *n called "<<endl;
}
int main()
{
    const number x=12;
    number a=10;

    const number &b=a;
    number &c=a;

    number *p1=&a;
    const number *p2=&a;
    const number *p3=&x;

    f1(x);
    f1(a);
    f1(b);
    f1(c);
    cout<<endl;
//   f2(x); constant integer can not be bound to non constant parameter
    f1(a);
//    f2(b);  reference must be a constant integer
    f1(c);
    cout<<endl;
    f3(p1);
    f3(p2);
    f3(p3);
    cout<<endl;
    f3(p1);
//    f4(p2); constant pointer cannot be passed to a non constant parameter
//    f4(p3);  "     "        "             "        "
    return 0;
}
