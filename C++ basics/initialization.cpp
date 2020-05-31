#include<iostream>
using namespace std;

int func()
{
    int a;
    a=10;
    cout<<a<<endl;
    return a;
}

//uninitialized =00;
int d;
string str;
char a[15]="happy now";

void f1()
{
    //default initialization
    char e[20];
    cout<<e<<endl<<d;
    char h=a[2];
    cout<<h;
}

int main()
{
    // default initialized
    int local_int;
    //arbitrary value is assigned to it.
    char bl[20];
    //arbitrary value is assigned to it.
    cout<<local_int<<endl<<bl;

    int t,u,g;
    t=u=g=10;
    // both valid
    int i=3.14;
    int j={3.14};
    int b=func();
    // a initialized in the function so considered uninitialized. cannot be copied. int c=a;

    cout<<"start"<<b<<endl;
    cout<<i<<endl<<t<<endl<<u<<endl<<g<<endl;
    f1();
    // takes the value zero uninitialized
    cout<<endl<<str;
    char p;
    cout<<"current \n"<<p<<endl;
    //prints 00 since defined outside any function.
    cout<<d;
    return 0;

}
