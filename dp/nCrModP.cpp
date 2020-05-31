#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define P 1000000007

int modExp(int x, int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modExp((x*x) % P, n/2);
    else
        return (x*modExp( (x*x) % P, (n-1)/2)) % P;
}

int nCr_modP(int n, int r)
{
    if(r == 0)
        return 1;

    int temp = ((n % P) * modExp(r, P-2)) % P;                       // inverse factorial
    return ((temp % P) * nCr_modP(n-1, r-1) % P) % P; 
}

signed main()
{
    int n;
    int r;
    cin >> n >> r;

    int ncr = nCr_modP(n, r);
    cout << ncr << endl;
}