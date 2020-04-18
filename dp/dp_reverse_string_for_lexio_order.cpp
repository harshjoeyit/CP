/*
Vasiliy is given n strings consisting of lowercase English letters. He wants them to be sorted in lexicographical order (as in the dictionary), but he is not allowed to swap any of them. 
The only operation he is allowed to do is to reverse any of them

Vasiliy is given n strings consisting of lowercase English letters. He wants them to be sorted in lexicographical order (as in the dictionary), but he is not allowed to swap any of them. 
The only operation he is allowed to do is to reverse any of them
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5+10;
int n, cost[mxN];
string s[mxN][2];
int INF = 1e18;
int dp[mxN][2];

int calc(int i, int j) {
    if(i == n-1) {
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INF;
    if(s[i][j] <= s[i+1][0])
        ans = min(ans, calc(i+1, 0));
    if(s[i][j] <= s[i+1][1])
        ans = min(ans, cost[i+1]+calc(i+1, 1));

    return dp[i][j] = ans;
}

void solve() {
    string str;
    cin >> n ;
    for(int i = 0; i < n; i++) 
        cin >> cost[i];
    for(int i = 0; i < n; i++) {
        cin >> str;
        s[i][0] = str;
        reverse(str.begin(), str.end());
        s[i][1] = str;
    }
    memset(dp, -1, sizeof(dp));
    int ans = INF;
    ans = min(ans, calc(0, 0));
    ans = min(ans, calc(0, 1)+cost[0]);

    if(ans != INF) {
        cout << ans << "\n";
    } else {
        cout << "-1\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}