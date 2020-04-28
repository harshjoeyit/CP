#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000;


vector<int> primes;

void seive()
{   
    int limit = MAX;
    bool isPrime[limit+1];
    
    memset(isPrime,true,sizeof(isPrime));
   
    for(int i = 2; i*i <= limit; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = i*i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
   
    for(int i = 2; i <= limit; i++)
        if(isPrime[i]==true)
            primes.push_back(i);                        // all the primes in the range of 10^6 are stored in the vector primes
}


void getPrimes(int l,int r)
{
    if(l<2) l=2;                                                // imp 
    
    bool isPrime[r-l+1];                                
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 0; primes[i]*primes[i] <= r; i++ )              // imp
    {   
        int currentPrime = primes[i];
        int base = floor(l/currentPrime)*currentPrime;
            
        if(base < l)
            base += currentPrime;
            
        if(base == currentPrime)
            base += currentPrime;
                
        for(int j = base; j <= r; j += currentPrime)
            isPrime[j-l] = false;    
    }
   
    for(int i = 0; i< sizeof(isPrime); i++)
        if(isPrime[i])
            cout<<i+l<<endl;
    cout<<endl;

}

int main() 
{
    int t;
    cin>>t;
    seive();
   
    while(t--)
    {
        int l, r;
        cin>>l>>r;
        getPrimes(l,r);  
    }
    return 0;

}
 