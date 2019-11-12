#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll modExp(ll x, ll y, ll p) 
{ 
    ll res = 1;     
    x = x % p;  
    while (y > 0) 
    { 
            if (y & 1) 
            res = (res*x) % p; 
  
      y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 


int main()
{
    ll j, p = 1000000007;

    vector<ll> factorial_mod(2000003);
    factorial_mod[0] = 1;

    for(int i = 1; i < 2000003; i++ )                                   // stores n! % p
    {
        j = (( factorial_mod[i-1] % p) * (i % p )) % p;
        factorial_mod[i] = j;
    }

        ll n, k, ans;
        cin >> n >> k;

        ans = ((factorial_mod[n] % p) * (modExp(factorial_mod[n-k], p-2, p))) % p;              // ( (n! % p) * ((n-k)^-1) % p) ) % p;
        ans = ((ans % p) * (modExp(factorial_mod[k], p-2, p))) % p;                             //     ((ans % p)*((k^-1) % p)) % p
    
        cout << ans << endl;
}



