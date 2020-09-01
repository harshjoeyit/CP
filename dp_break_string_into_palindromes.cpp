

// https://practice.geeksforgeeks.org/problems/palindromic-patitioning/0
// find minimum breaks in the string, such that every partition is a palindrome 

#include<bits/stdc++.h>
using namespace std;

int dp[1001];
int pal[1001][1001];

void storePalindromes(string &s) {
    memset(pal, 0, sizeof(pal));
    int n = s.length();
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            if(l <= 2) {
                if(s[i] == s[j]) {
                    pal[i][j] = 1;
                }
            } else if(s[i] == s[j]) {
                pal[i][j] = pal[i + 1][j - 1];
            }
        }
    }
}

int solve(string &s, int i) {
      int n = s.length();
      if (i >= n) {
            return 0;
      }

      int &ans = dp[i];
      if(dp[i] != -1) {
            return dp[i];
      }
      ans = INT_MAX;
      
      for (int j = i; j < s.length(); j++) {
            if(pal[i][j]) {
                  ans = min(ans, 1 + solve(s, j + 1));
            }
      }
      return ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        storePalindromes(s);
        memset(dp, -1, sizeof(dp));
        cout << solve(s, 0) - 1 << endl;
    }
}
