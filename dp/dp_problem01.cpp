// dp problem
// https://codeforces.com/problemset/problem/607/A

#include <bits/stdc++.h> 
using namespace std; 

#define int long long
const int mxN = 1e6+10;
int n, b[mxN], dp[mxN];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        b[x] = y;
    }

    if(b[0] > 0)
        dp[0] = 1;

    int mx = 0;
    for(int i=1; i<mxN; i++) {
        if(b[i]>0) {
            if(i-b[i]-1 >= 0) {
                dp[i] = dp[i-b[i]-1] + 1;
            } else {
                dp[i] = 1;
            }
        } else {
            dp[i] = dp[i-1];
        }

        mx = max(mx, dp[i]);
    }
    cout << n - mx << "\n";
}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
} 