#include<iostream>
using namespace std;

int f1()
{
    const int x=5;
    return x;
}

int f2()
{
    const int y=10;
    return y;
}
int f3()
{
    const int z=4;
    return z;
}

int f4()
{
    const int k=7;
    return k;
}
int main()
{
    float a=10.2;
    int b=3;
    float ans1;
    int ans2;

    ans1=a*b;
    ans2=a*b;

    cout<<ans1<<" "<<ans2<<endl;;

int m1= 4+6*2-4/2;
    cout<<m1<<endl;
 int m2=(4+6)*2-(4/2); // we can choose to override the precedence  by using ( )
    cout<<m2;

cout<<endl;

cout<<(f1()*f2())<<endl; // although it is unknown which function will evaluate first

int i=0;
cout<<i<<" "<<++i<<endl; // IMPORTANAT: output = 1 1

int j=0;
cout<<j;
++j;
cout<<" "<<j<<endl;

cout<<(f1()+ f2()*f3()+f4())<<endl;

cout<<sizeof(f2())<<endl; // can apply it in the function

short short_value= 32767;
cout<<--short_value;
cout<<++short_value<<" "<<++short_value<<endl; // overflow size the limit of the type exceeds

int x= 2147483647;
cout<<x<<endl;  // overflow

long double y;
cout<<sizeof(y)<<endl;

double d=89.45678;
cout<<d%f2();
return 0;
}
