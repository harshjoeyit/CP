
/*
using DP to find longest palindromic substring 
answers range query of [L, R] - if palindrome or not in O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3+10;
int dp[mxN][mxN];
string s;
string ans_s;

void longestPalindromicSubstring() {
    int n = s.length();
    int ans_i = 0, ans_l = 0;
    
    memset(dp, 0, sizeof(dp));

    for(int l=1; l<=n; l++){                    // j = for length of the string
        for(int i=0; i<=n-l; i++) {             // i - iterate to every index where length j string is possible
            int j = i+l-1;
            if(l <= 2) {                        // for string of length = 1, 2
                if(s[i] == s[j])                // [i - i+length-1] indices of start and end of string 
                    dp[i][j] = 1;

            } else if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];        // for [l, r] to be palindrome [l+1, r-1] must be a palindrome    
            }
            if(dp[i][j] == 1) {
                if(l > ans_l) {
                    ans_l = j;
                    ans_i = i;
                }
            }
        }
    }   
    ans_s = s.substr(ans_i, ans_l);
}


// longest palindromic subsequence 
// bottom up -DP
int longestPalindromicSubsequnce (string &s) {
      int n = (int)s.length();
      vector<vector<int>> dp(n, vector<int>(n, 1));

      for(int l=2; l<=n; l++) {
            for(int i=0; i<=n-l; i++) {
                  int j = i+l-1;
                  if(l == 2) {
                        if(s[i] == s[j]) {
                              dp[i][j] = 2;
                        }
                        continue;
                  } 
                  if(s[i] == s[j]) {
                        // we max from what is remaining 
                        // i.e. (i+1, j-1)
                        dp[i][j] = dp[i+1][j-1] + 2;
                  } else {
                        // if terminal chars are not equal 
                        // we take max from (i+1, j) and (i, j-1)
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                  }
            }
      }

      for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                  cout << dp[i][j] << " ";
            }
            cout << endl;
      }

      return dp[0][n-1];
}

// to print the longest palindromic subsequence, use the dp matrix 
// just to the same comparison that is done and go to 
// (i-1, j-1) if s[i] == s[j], else 
// (i, j-1) or (i+1, j) whichever is greater 

void solve() {
    cin>> s;
    longestPalindromicSubstring();
    cout << ans_s << endl;
}


// longest palindromic subsequence 
// top-down DP

int go(int st, int en, string &s) {
    if(st > en) {
        return 0;
    }
    if(st == en) {
        return 1;
    }
    
    int &ans = dp[st][en];
    if(ans != -1) {
        return ans;
    }
    
    if(s[st] == s[en]) {
        return ans = 2 + go(st+1, en-1, s);
    }
    
    return ans = max(go(st, en - 1, s), go(st + 1, en, s));
}

int longestPalindromeSubseq(string s) {
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    return go(0, n - 1, s);
}


/*
count palindromic subsequences  (V.V. IMP)
*/
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) 
        solve();
}
