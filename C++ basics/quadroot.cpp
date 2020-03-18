#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    long double a,b,c,D;
    cin>>a>>b>>c;
    D=b*b - 4*a*c;

    if(D>=0)
    {
        D=pow(D,0.5);
        long double r1,r2;

        r1=(-b + D)/2.0*a;
        r2=(-b - D)/2.0*a;

//IMP: set precision asked accordingly to make answer correct to requires decimal places
        cout<<fixed<<setprecision(20)<<r1<<endl<<r2;
    }
    return 0;
}
