#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mxN 1000
// To store the states of DP 
int dp[mxN][mxN]; 
int a[mxN], n, sum;          

int count_subsets_with_given_sum(int i, int s) {
    if(i == n) {
        if(s == sum) 
            return 1;
        else 
            return 0;
    }
    if(s > sum)
        return 0;

    if(dp[i+1][s] == -1) {
        dp[i+1][s] = count_subsets_with_given_sum(i+1, s);
    }
    if(dp[i+1][s+a[i]] == -1) {
        dp[i+1][s+a[i]] = count_subsets_with_given_sum(i+1, s+a[i]);
    }
    
    return (dp[i+1][s] + dp[i+1][s+a[i]]);
}

void solve() {
    cin >> n >> sum;
    for(int i=0; i<n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    int cnt = count_subsets_with_given_sum(0, 0);
    cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}