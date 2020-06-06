#include<iostream>
#include<vector>
#include<string>
using namespace std;

int add(int x,int y)    // this whole function is nothing but a value
{                       // of integer type. as defined
    int sum=x+y;        // int add(.........)
    return (sum);
}

int main()
{
    int a=5,b=2;
    cout<<" sum is : "<<add(a,b);       // we can simply print an integer value
    return 0;                           // i.e. add(......)
}
