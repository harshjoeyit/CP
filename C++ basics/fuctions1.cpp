#include<iostream>
using namespace std;

void f1();
void f2();
int i=5;

int main()
{
  int d=7;
   f1();
   f2();
   return 0;
}

void f1()
{
    int a=10;
    //  d not defined in this scope cout<<a+d<<endl;
    cout<<i+a<<endl;

}

void f2()
{
    int a=5;
    cout<<a<<endl<<i<<endl;
    // main function can be called like any other function;  this leads to and infinite loop
}
