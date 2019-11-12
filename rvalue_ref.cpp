#include<bits/stdc++.h>
using namespace std;

void printInt( int& i)
{
    cout<<"lvalue ref: "<<i <<endl;
}

void printInt( int&& i)
{
    cout<<"rvalue ref: "<< i <<endl;
}

int main()
{
    int a = 5;
    printInt(a);
    printInt(5);
    printInt(++a);
    printInt(a++);
    
}