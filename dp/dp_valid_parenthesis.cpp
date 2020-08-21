
/*
https://www.hackerrank.com/contests/pir5/challenges/count-expressions/problem

brackets at position x, 2x, 3x are '('
count total number of valid parenthesis strings possible
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 2003, MOD = 1e9+7;
int n, x;
int dp[mxN][mxN];

int count_valid(int i, int op, int cl) {
    if(cl > op || op > n || cl > n)             // invalid states
        return dp[op][cl] = 0;

    if(i == 2*n+1) {                            // base condition
        if(op == n && cl == n)
            return 1;
        return 0;
    }
    if(i % x == 0) {                            // open bracket found, increase count of open and call 
        if(dp[op+1][cl] == -1)
            dp[op+1][cl] = (count_valid(i+1, op+1, cl))%MOD;
        return dp[op+1][cl];
    }
    
    // we have two choices for next charachter '(', '(', 
    // we try them both

    if(dp[op+1][cl] == -1)    
        dp[op+1][cl] = (count_valid(i+1, op+1, cl))%MOD;
    if(dp[op][cl+1] == -1)
        dp[op][cl+1] = (count_valid(i+1, op, cl+1))%MOD;

    return  (dp[op+1][cl] + dp[op][cl+1]) %MOD;
}

void solve() {
    cin >> n >> x;
    int ans;
    if((2*n) % x == 0)
        ans = 0;
    else {
        memset(dp, -1, sizeof(dp));
        ans = count_valid(1, 0, 0);
    }
    cout << ans << endl; 
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}