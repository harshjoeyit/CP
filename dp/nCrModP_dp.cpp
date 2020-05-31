#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define P 998244353
#define N 1000000

int fact[N];
void factorial()
{
    fact[0] = 1;
	fact[1] = 1;
    for(int i = 2; i < N; i++)
        fact[i] = (i * fact[i-1]) % P;
}


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

    int a = fact[n];
    int b = (fact[n-r] * fact[r]) % P;
    return (a * modExp(b, P-2)) % P;
}

signed main()
{
	int n, r;
	cin >> n >> r;
	factorial();
	cout << nCr_modP(n, r) << endl;
}