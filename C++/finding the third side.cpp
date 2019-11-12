#include<iostream>
#include<cmath>
using namespace std;

int main()
{

    cout<<"choose to enter any two sides of RIGHT ANGLED TRIANGLE:"<<endl;
    float h=0,p=0,b=0;

    cout<<"enter the known values and 0 in unknown values "<<endl;
    cout<<"enter h: ";
    cin>>h;
    cout<<"enter b: ";
    cin>>b;
    cout<<"enter p: ";
    cin>>p;

    double sin,cos,tan;
    if(h && p)
    {
        b=sqrt(h*h - p*p);
        cout<<"b: "<<b<<endl;
    }
    else if(h && b)
    {
        p=sqrt(h*h - b*b);
        cout<<"p: "<<p<<endl;
    }
    else
    {
        h=sqrt(p*p + b*b);
        cout<<"h: "<<h<<endl;
    }
}
