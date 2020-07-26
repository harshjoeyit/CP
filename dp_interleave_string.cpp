#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int go(string &s1, string &s2, string &s3, int i, int j, int k) {
      if (i == s1.length() && j == s2.length() && k == s3.length()) {
            return 1;
      }
      
      if (dp[i][j] != -1) {
            return dp[i][j];
      }

      if (i < s1.length() && s1[i] == s3[k]) {
            // include this char in first string 
            if(go(s1, s2, s3, i + 1, j, k + 1)) {
                  return dp[i][j] = 1;
            }
      }
      if (j < s2.length() && s2[j] == s3[k]) {
            // include this char in the second string 
            if(go(s1, s2, s3, i, j + 1, k + 1)) {
                  return dp[i][j] = 1;
            }
      }

      return dp[i][j] = 0;
}

bool isInterleave(string s1, string s2, string s3) {
      if (s1.length() + s2.length() != s3.length()) {
            return false;
      }
      memset(dp, -1, sizeof(dp));
      return go(s1, s2, s3, 0, 0, 0);
}

int main() {

}