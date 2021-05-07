#include<bits/stdc++.h>
using namespace std;


long long int countPS(string s) {
    const int mod = 1e9+7;
    int n = s.length();
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0LL));

    for(int l=1; l<=n; l++) {
        for(int i=0; i<=n-l; i++) {
            int j=i+l-1;
            if(l == 1) {
                dp[i][j] = 1;
            } else if(s[i] == s[j]) {
                dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % mod;
            } else {
                dp[i][j] = ((dp[i+1][j] + dp[i][j-1]) % mod - dp[i+1][j-1] + mod) % mod;
            }
        }
    }

    return dp[0][n-1] % mod;
}

int main() {
    cout << countPS("aab") << endl;
}