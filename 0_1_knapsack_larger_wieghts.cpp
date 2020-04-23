#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 100;                 
const int mxW = 1000000005;
const int mxV = 1000;          
int dp[mxN+5][mxN*mxV + 5];                      // dp[objects][value sum] - denotes min wt possible for a value sum of i objects
int n, capc;

void solve() {
    cin >> n >> capc;
    int val[n];
    int wt[n];

    int total_val = 0, ans = 0;

    for(int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
        total_val += val[i];                // total_val is max possible value - this is when all the objects are included in the knapsack
    }

    dp[0][0] = 0;
    for (int i = 1; i <= total_val; i++) 
		dp[0][i] = 1e18;

    for(int i=0; i<n; i++) {
        for(int j=0; j<= total_val; j++) {                  // for each i (i.e number of objects up untill now) and j (value sum up untill now ) -  
                                                            // we store MIN posssible wt - to maximize value sum    
            if(j >= val[i]) {   
                dp[i+1][j] = min(dp[i][j], dp[i][j-val[i]] + wt[i]);                // we have two options - skip or include this value
                                                                                    // choose min wt among two
            } else {                                        // j < val[i]
                dp[i+1][j] = dp[i][j];                  
            }

            if(dp[i+1][j] <= capc)
                ans = max(ans, j);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}