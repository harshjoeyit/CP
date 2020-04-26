
/*
Modified sieve - primes less than N in O(N)
*/

#include<bits/stdc++.h> 
using namespace std; 
#define int long long 

const int mxN = 1000001; 

vector<int>isprime(mxN , true);          // checks if i is prime 
vector<int>prime;                        // stores all the primes 
vector<int>SPF(mxN);                     // smallest prime factor of i


void modified_seive(int N)  { 
	isprime[0] = isprime[1] = false ; 
 
	for (int i=2; i<N ; i++)  { 
		if (isprime[i]) {  
			prime.push_back(i);  
			SPF[i] = i; 
		} 

        int sz = prime.size();
		
        for (int j=0; j<sz && i*prime[j]<N && prime[j]<=SPF[i]; j++) { 

			isprime[i*prime[j]]=false; 
			SPF[i*prime[j]] = prime[j] ;                // put smallest prime factor of i*prime[j]
		} 
	} 
} 


signed main() { 
	int N = 50;
	modified_seive(N); 

	for (int i=0; i<prime.size() && prime[i] <= N; i++) 
		cout << prime[i] << " "; 

	return 0; 
} 
