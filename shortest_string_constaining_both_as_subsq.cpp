

/* Find smallest string such that 
      a and b are subsequences of it 
      example 
      a = "abcd"
      b = "bde"
      ans = "abcde"
*/


#include<bits/stdc++.h>
using namespace std;

int n, m;
string ans;

void getIndices(string &a, string &b, vector<vector<int>> &dp) {
      int i = n, j = m;
      while (i > 0 && j > 0) {
            if(a[i-1] == b[j-1]) {
                  ans.push_back(a[--i]);
                  --j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                  ans.push_back(a[--i]);
            }
            else{
                  ans.push_back(b[--j]);
            }
      }
}

void LCS(string &a, string &b) {
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  if(a[i-1] == b[j-1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                  } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                  }
            }
      }
      getIndices(a, b, dp);
}

string shortestCommonSupersequence(string a, string b) {
      n = a.length(), m = b.length();
      ans = "";
      LCS(a, b);
      return ans;
}

int main() {
      string a, b;
      cin >> a >> b;
      cout << shortestCommonSupersequence(a, b);
}