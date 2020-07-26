
/*
Partition array in two subsets such that their absolute difference is minimum
DP
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int mxN = 55;
const int mxAi = 200;
int a[mxN];
int dp[mxN][mxAi * mxN];                  
int n, s;

int go(int i, int sum) {

    if(i == n) {
        return abs((s-sum) - sum);
    }

    if(dp[i][sum] != -1) {
        return dp[i][sum];
    }

    dp[i][sum] = min(go(i+1, sum), go(i+1, sum+a[i]));
    return dp[i][sum];
}

void solve() {
    cin >> n;
    s = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        s+=a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}