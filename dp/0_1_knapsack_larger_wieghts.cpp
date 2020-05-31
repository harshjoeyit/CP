#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 100;                 
const int mxW = 1000000005;
const int mxV = 1000;          
int dp[mxN+5][mxN*mxV + 5];                 // dp[i][j] - minmum weights for including i objects for making up value = j  
int n, capc;

void solve() {
    cin >> n >> capc;
    int val[n];
    int wt[n];

    int total_val = 0, ans = 0;

    for(int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
        total_val += val[i];                // total_val is max possible value of the knapsack when capacity is enough to hold all elements 
    }

    dp[0][0] = 0;
    for (int i = 1; i <= total_val; i++) 
		dp[0][i] = 1e18;

    for(int i=0; i<n; i++) {
        for(int j=0; j<= total_val; j++) {                  // for each i (i.e number of objects up untill now) and j (value sum up untill now ) -  
                                    
            if(j >= val[i]) {   
                // ith item can be included now if required - so we have two choices
                // skip or include this value
                dp[i+1][j] = min(dp[i][j], dp[i][j-val[i]] + wt[i]);             
            } else { 
                // we cannot include the ith object up untill now since its value > curr val j                                    
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