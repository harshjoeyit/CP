#include<bits/stdc++.h>
using namespace std;

// recursive

vector<vector<int>> dp;

int go(string &wild, int i, string &pat, int j) {
    int wl = wild.length(), pl = pat.length();
    
    if(i == wl && j == pl) {
        return 1;
    } else if(i == wl) {
        return 0;
    } else if(j == pl) {
        if(wild[i] == '*') {
            return go(wild, i+1, pat, j);
        }
        return 0;
    }

    int &ans = dp[i][j];
    if(ans != -1) {
        return ans;
    }

    if(wild[i] == pat[j] || wild[i] == '?') {
        return ans = go(wild, i+1, pat, j+1);
    }
    else if(wild[i] == '*') {
        return ans = (go(wild, i+1, pat, j) || go(wild, i, pat, j+1));
    }
    // if wild[i] != pat[j]
    return ans = 0;
}


// iterative 
bool wildcardPatternMatching(string wild, string pat) {
    int n = pat.length();
    int m = wild.length();

    if(m == 0) {
        return (n == 0);
    }

    bool dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    // empty string matches with empty pattern
    dp[0][0] = true;

    for(int j=1; j<=m; j++) {
        if(wild[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {

            if(wild[j-1] == '*') {   // either skip '*' or include '*'
                dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
            
            } else if(wild[j-1] == '?' || pat[i-1] == wild[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            
            } else {    // characters mismatch
                dp[i][j] = 0;
            }
        }
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            cout << dp[i][j] << " ";
        } cout << "\n";
    }

    return dp[n][m];
}

int main() {
    string pat, wild;
    cin >> pat >> wild;
    cout << wildcardPatternMatching(pat, wild) << "\n";
}