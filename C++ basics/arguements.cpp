#include<iostream>
#include<string>
using namespace std;

void print(int x,int a,int b,char ch='*');  // first the rightmost parameter is initialized then rest
void print(int x,int a,int b=3,char ch);  // default arguments are given first to parameter on the right then to the left sequentially
void print(int x,int a=3,int b,char ch);  // ch then b then a

int main()
{
    print(2);  // calling without any parameters , 2 is argument to parameter x
}

void print(int a, int b, char ch)
{
    cout<<a+b<<ch;
}



