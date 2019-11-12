#include<bits/stdc++.h> 
using namespace std; 

typedef long long int ll;

ll nCrModpDP(ll n, ll r, ll p) 
{ 
	ll C[r+1]; 
	memset(C, 0, sizeof(C)); 

	C[0] = 1; 

    for (ll i = 1; i <= n; i++) 
	{ 
		for (ll j = min(i, r); j > 0; j--) 
    	C[j] = (C[j] + C[j-1])%p; 
	} 
	return C[r]; 
} 

ll nCrModpLucas(ll n, ll r, ll p) 
{ 
    if (r==0) 
	    return 1; 

    ll ni = n%p, ri = r%p; 
    
    return (nCrModpLucas(n/p, r/p, p) *  nCrModpDP(ni, ri, p)) % p; 
} 

// Driver program 
int main() 
{ 
	ll n = 4, r = 1, p = 1000000007; 
	cout << "Value of nCr % p is " << nCrModpLucas(n, r, p); 
	return 0; 
} 
