#include<iostream>
using namespace std;

int factorial(int n)
{
    long fac=1;
    for(int i=1; i<=n; i++)
        fac=fac*i;

    return fac;
}

int main()
{
    int N;
    long int x;
    cin>>N;

    x=factorial(N);
    cout<<x;
}
