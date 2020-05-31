#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9+7;

int add(int a, int b) {
    a = a+b;
    if(a >= mod)
        a = a-mod;
    return a;
}

int mul(int a, int b) {
    return (a*b)%mod;
}

void solve() {
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    int ans = 0;
    int f = 1;
    int n = s.length();

    /*Pattern observed 
    
                Frequency in substrings at positions
    Digit   Unit    Ten     Hundred     Thousand        Sum
    6       1       1       1           1           = 6*1*1111
    7       2       2       2                       = 7*2*111
    8       3       3                               = 8*3*11
    9       4                                       = 9*4*1
    */

    for(int i=0; i<n; i++) {
        int dig = (int)(rev[i] - '0');                  
        ans = add(ans, mul(mul(dig, n-i), f));
        f = add(mul(f, 10), 1);
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}