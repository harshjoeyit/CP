
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string &a, string &b) {
      int n = a.length(), m = b.length();
      int dp[n+1][m+1] = {};
      int maxL = 0;

      for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                  if(a[i-1] == b[j-1]) {
                        // go back 1 position in both the string and check 
                        // common length for i-1, j-1 state
                        dp[i][j] = dp[i-1][j-1] + 1;
                        // find max
                        maxL = max(maxL, dp[i][j]);
                  } else {
                        dp[i][j] = 0;
                  }
            }
      }

      return maxL;
}

// Recursive Version, we need to use one extra variable for count
int go(string &a, string &b, int i=0, int j=0, int cnt=0) {
      int n = a.length(), m = b.length();
      if(i >= n || j >= m) {
            return cnt;
      }

      if(a[i] == b[j]) {
            cnt = go(a, b, i+1, j+1, cnt + 1);
      }     

      // start count from 0 for next recursion
      cnt = max({cnt, go(a, b, i+1, j, 0), go(a, b, i, j+1, 0)});
      return cnt;
}


int main() {
      string a, b;
      cin >> a >> b;
      // cout << longestCommonSubstring(a, b);
      cout << go(a, b);
}