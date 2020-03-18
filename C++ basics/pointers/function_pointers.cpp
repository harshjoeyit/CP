// function pointers store the address of the first instruction of that function

#include<bits/stdc++.h>
using namespace std;

int func(int a,int b)
{
    return (a+b);
}

int func1(int a,int b)
{
    return (a*b);
}

void func2()
{
    cout<<"func 2 called "<<endl;
}

void print(char name)
{
    cout<<"hello "<<name<<endl;
}

int main()
{

    int (*p)(int ,int );   // pointer points to all functions that have return type int and argument int , int
    
    p = &func; // or p = func;

    
    void (*ptr)(char);
    ptr = print;
    ptr('t');

    int sum = (*p)(2,3); // or sum = p(2,3);
    cout<<"sum = "<<sum<<endl;

    p = &func1;         // now pointer points to another similar function 

    int product = (*p)(4,5);
    cout<<"product = "<<product<<endl; 

    auto poi = &func2;  // can also define using auto keyword
    (*poi)();

    return 0;
}