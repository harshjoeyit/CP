
/*
regex matching 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1005;
bool dp[mxN][mxN];

bool regex_matching(string s, string regex) {
      dp[0][0] = 1;
      // for the regex like a*, a*b*, a*b*c*, since the string "" also satify the regex 
      for(int i=1; i<=regex.length(); i++) {
            if(regex[i-1] == '*') {
                  dp[0][i] = dp[i-2];
            }
      }
      for(int i=1; i<=s.length(); i++) {
            for(int j=1; j<=regex.length(); j++) {
                  if(regex[j-1] == '.' || regex[j-1] == s[i-1]) {
                        dp[i][j] = dp[i-1][j-1];
                  
                  } else if(regex[j-1] == '*') {
                        dp[i][j] = dp[i][j-2];
                        if(regex[j-2] == '.' || regex[j-2] == s[i-1]) {                   // Notes '.*' - every possible character
                              dp[i][j] = dp[i][j] | dp[i-1][j];
                        }
 
                  } else {
                        dp[i][j] = 0;
                  }
            } 
      }

//      for(int i=0; i<=s.length(); i++) {
//            for(int j=0; j<=regex.length(); j++) {
//                  cout << dp[i][j] << " ";
//            }cout << "\n";
//      }  
            return dp[s.length()][regex.length()];
}

void solve() {
      string s, regex;
      cin >> s >> regex;
      cout << regex_matching(s, regex) << "\n";
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}