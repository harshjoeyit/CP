#include<bits/stdc++.h>
using namespace std;

long long int lcm(int a,int b)
{
    int l;
    l= (a>b)? a:b;
    while(1)
    {
        if(l%a==0 && l%b==0)
        {
            return l;
            break;
        }
        ++l;
    }
}

bool isprime( long int div )
{
    if(div ==0 || div == 1)
        return false;
    for(int i=2; i<div/2; i++ )
        if( div % i  == 0)
            return false;
    return true;
}

int main()
{
    long int tt;
    cin>>tt;

    while(tt--)
    {
        long int n,ans,t=0;
        cin>>n;
        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        int d = lcm(a[0], a[1]);

        for(int i=2; i<n; i++)
            d = lcm(d, a[i]);

        for(int i=0; i<n; i++)
        {
            long int c = d/a[i];
            if( isprime(c) == 0)
            {
                t = 1;
                cout<<"-1"<<endl;
                break;
            }

        }
        if( t  == 0)
            cout<<d<<endl;
    }
    return 0;
}
