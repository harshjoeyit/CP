#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1005;
int n, capc;
int val[mxN];
int wt[mxN];

void fill_knapsack(){
    int dp[n+1][capc+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=capc; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=; j<=capc; j++) {
            if(j < wt[i-1])          // array index 0 for item 1 // item cannot contribute in knapsack
                    dp[i][j] = dp[i-1][j];      // best can do without including the item

            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                
        }
    }

    cout << dp[n][capc] << "\n";
}

void solve() {
    cin >> n >> capc;

    for(int i=0; i<n; i++)
        cin >> val[i];
    for(int i=0; i<n; i++)
        cin >> wt[i];

    fill_knapsack();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}