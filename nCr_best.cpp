#include<bits/stdc++.h>
using namespace std;

#define int long long int 
const int nmax = 1e5 + 5;
const int mod = 1e9+7;

int modexpo(int x, int n, int m = mod) {
    int ret = 1%m;
    while(n){
        if(n&1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}
 
int fac[nmax];
int facinv[nmax];
void precal()
{
    fac[0] = 1;
    for(int i = 1; i < nmax; i++)
        fac[i] = (fac[i-1]*i) % mod;
    facinv[nmax-1] = modexpo(fac[nmax-1], mod-2);
    for(int i = nmax-1; i > 0; i--)
        facinv[i-1] = (facinv[i] * i) % mod;
    return;
}
 
int NCR(int n, int r){
    if(n < r) return 0;
    return fac[n] * facinv[r] % mod * facinv[n-r] % mod;
}

signed main() {
    int q;
    cin >> q;
    precal();
    while(q--) {
        int n, r;
        cin >> n >> r;
        cout << NCR(n, r) << endl;
    }
}