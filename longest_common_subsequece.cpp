#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 3005;
int dp[mxN][mxN];

void print_LCS(string s, string t, int n, int m) {
    int i=n, j=m;
    string lcs = "";
    
    while((i>0) && (j>0)) {
        if(s[i-1] == t[j-1]) {
            lcs = s[i-1] + lcs;
            --i;
            --j;

        } else if(dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    cout << lcs << endl;
}

void LCS(string s, string t) {
    // lcs
    int n = s.length();
    int m = t.length();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // print lcs
    cout << dp[n][m] << endl;
    print_LCS(s, t, n, m);
}

void solve() {
    string s, t;
    cin >> s >> t;

    LCS(s, t);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}