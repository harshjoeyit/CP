#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mxN 1000
// maxsum 0f array <= 1000
int dp[mxN][mxN]; 
int a[mxN], n, sum;          

int go(int i, int s) {
    if(i == n) {
        if(s == sum) 
            return 1;
        else 
            return 0;
    }
    if(s > sum)
        return 0;

    if(dp[i][s] != -1) {
        return dp[i][s];
    }
    dp[i][s] = go(i+1, s) + go(i+1, s+a[i]);
    return dp[i][s];
}

void solve() {
    cin >> n >> sum;
    for(int i=0; i<n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    int cnt = go(0, 0);
    cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}