#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+1;
int prime[mxN];

void isprime(int prime[],int n)  // array are passed default;y with reference
{
    for(int i=2; i*i<=n; i++)  // IMP //
     {
         if(prime[i]==1)
         {
             for(int j=2; i*j<=n; j++) // each time following no are removed from being prime
                prime[i*j]=0;           // n/2,n/3,n/4,n/5 numbers are out to 0
         }
     }
}

void printprime(int prime[],int n)
{
     for(int i=0; i<=n; i++)
     {
        if(prime[i]==1)
            cout<<i<<" ,";
     }
}


// prime[i] - smallest prime factor of i;

void sieve() {                              
    for(int i=2; i*i <= mxN; i++) {
        if(!prime[i]) {
            for(int j=2*i; j<= mxN; j=j+i)
                prime[j] = i;   
        }
    }
    for(int i=1; i<=mxN; i++) 
        if(!prime[i])
            prime[i] = i;
}

int main()
{
    int prime[2100],n;
    cout<<"n: ";
    cin>>n;
    for(int i=0; i<=n; i++)
    prime[i]=1;

    prime[0]=0;
    prime[1]=0;

    isprime(prime,n);
    printprime(prime,n);
}
