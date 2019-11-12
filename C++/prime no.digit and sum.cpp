#include<iostream>
using namespace std;

// for checking prime number

bool isprime(int n)
{
    if(n==0 || n==1)
        return false;
    else
    if(n==2 ||n==3)
        return true;

    else
    if(n>3)
    {
        for(int i=2; i<=n/2; i++)
        {
            if(n%i==0)
                return false;
            else
                return true;
        }
    }

}

// second function

bool check(int I, long long A[10])
{
        int x=0;
        for(long long J=0; J<=I; J++)
        {
            if(isprime(A[J])==0)
            {
                cout<<A[J]<<endl;
               // return false;
            }
            else
                return true;

        }
}

main()
{
    long long a[4],N;

// storing the digits the array
    long long i=0;

    while(cin>>N)
    {
        while((N/10) != 0)
        {
            a[i]=N%10;      //storing the values of the   DIGITS   in the array
            N=N/10;      // changing the value of the N
            ++i;
        }
        a[i]=N;  // storing the the last digit ; outside the loop.
    }
// calculation the sum of the digits:

        long long s=0;
        for(long long j=0; j<=i; j++)
            s+=a[j];

        if(isprime(N))
        {

        cout<<"worked: ";
        if(check(i,a))
            cout<<"satisfied"<<endl;
        else
            cout<<"not satisfied"<<endl;
        }

}
