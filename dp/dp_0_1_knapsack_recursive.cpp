#include<bits/stdc++.h>
using namespace std;

#define int long long int
int n, capc;
int dp[102][100005];

int go(int i, int w, int val[], int wt[]){
    if(i < 0)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    
    if(wt[i] > w) {                 // skip the current object, can't include
        dp[i][w] = go(i-1, w, val, wt);
    } else {                        // two ways of calling - include, skip
        dp[i][w] = max(val[i]+go(i-1, w-wt[i], val, wt),
                        go(i-1, w, val, wt));
    }
    return dp[i][w];
}

void solve() {
    cin >> n >> capc;
    int val[n];
    int wt[n];

    for(int i=0; i<n; i++)
        cin >> wt[i] >> val[i];

    memset(dp, -1, sizeof(dp));
    cout << go(n-1, capc, val, wt) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}