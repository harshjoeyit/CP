
/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then cannot move through that element.

there is another approach using bfs, dp is simpler
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1e6+10;
int a[mxN];
int dp[mxN];
int n;

int min_jumps(int i) {
    if(i >= n-1) 
        return 0;
    
    int mn = INT_MAX;
    for(int j=1; j<=a[i]; j++) {
        if(dp[i+j] == -1)
            dp[i+j] = 1+min_jumps(i+j);
    
        mn = min(mn, dp[i+j]);
    }
    return mn;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) 
        cin >> a[i];
    
    memset(dp, -1, sizeof(dp));
    int ans = min_jumps(0);
    if(ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}