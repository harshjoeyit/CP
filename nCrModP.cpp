#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll modExp(ll x, ll n, ll P)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modExp((x*x) % P, n/2, P);
    else
        return (x*modExp( (x*x) % P, (n-1)/2, P)) % P;
}

ll nCr_modP(ll n, ll r, ll P)
{
    if(r == 0)
        return 1;

    ll temp = ((n % P) * modExp(r, P-2, P)) % P;                       // inverse factorial
    return ((temp % P) * nCr_modP(n-1, r-1, P) % P) % P; 
}


int main()
{
    int n;
    int r;
    cin >> n >> r;

    ll ncr = nCr_modP(n, r, 1000000007);
    cout << ncr << endl;
}