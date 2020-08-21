#include<bits/stdc++.h>
using namespace std;

// recursive

vector<vector<int>> dp;

int wildCard(string &s, string &pat, int i=0, int j=0) {
      int n = (int)s.length(), m = (int)pat.length();
      if(i >= n && j >= m) {
            return true;
      }
      if(i < n && j >= m) {
            return false;
      } else if(i >= n && j < m) {
            if(pat[j] != '*') {
                  return false;
            }
            // skip extra *
            return wildCard(s, pat, i, j+1);
      }

      int &ans = dp[i][j];
      if(ans != -1) {
            return ans;
      }     

      if(pat[j] == '*') {
            return ans = (wildCard(s, pat, i+1, j) | wildCard(s, pat, i, j+1));
            
      } else if((pat[j] == '?') || (s[i] == pat[j])) {
            return ans = (wildCard(s, pat, i+1, j+1));
      } 
      // remaining case is s[i] != pat[j]
      return ans = 0;
}

// iterative 
bool wildcardPatternMatching(string s, string pat) {
    int n= s.length();
    int m= pat.length();

    if(m == 0) {
        return (n == 0);
    }

    bool dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    // empty string matches with empty pattern
    dp[0][0] = true;

    for(int j=1; j<=m; j++) {
        if(pat[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {

            if(pat[j-1] == '*') {   // either skip '*' or include '*'
                dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
            
            } else if(pat[j-1] == '?' || s[i-1] == pat[j-1]) {
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
    string s, pat;
    cin >> s >> pat;

    cout << wildcardPatternMatching(s, pat) << "\n";
}