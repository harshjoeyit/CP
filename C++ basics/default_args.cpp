#include<bits/stdc++.h>
using namespace std;


void function_1(int a=10)  // way 1 of passing default arguments
{                           // in the body itself
    cout<<a<<endl;
}

void function_2(int a=10,int b=12);  // way 2 int the prototype

int main()
{
    function_1();
    function_2('\0');
}

void function_2(int a,int b)
{
    cout<<a<<" "<<b<<endl;
}


