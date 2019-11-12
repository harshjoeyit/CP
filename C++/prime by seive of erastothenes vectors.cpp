#include<bits/stdc++.h>
using namespace std;

void isprime(vector<bool> &prime,int n)  // vectors must be passed with reference since they are called by reference
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

void printprime(vector<bool> prime,int n)
{
     for(int i=0; i<=n; i++)
     {
        if(prime[i]==1)
            cout<<i<<" ,";
     }

}

 int main()
 {
     int n=2100; // prime limit
     vector<bool> prime;
     cout<<"print prime till: ";
     //cin>>n;

     for(int i=0; i<=n; i++)
        prime.push_back(true);

     prime[0]=0;
     prime[1]=0;

     isprime(prime,n);
     printprime(prime,n);

 }
