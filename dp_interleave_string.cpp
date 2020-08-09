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


// all interleave patterns 
void interleave(string &a, string &b, int i, int j, string s) {
      if(i == a.length() && j == b.length()) {
            cout << s << endl;
            return;
      }

      if(i < a.length()) {
            interleave(a, b, i+1, j, s + a[i]);
      }

      if(j < b.length()) {
            interleave(a, b, i, j+1, s + b[j]);
      }
}


// may be efficient interleave 
void interleave2(string &a, string &b, int i, int j, string &s) {
      if(i == a.length() && j == b.length()) {
            cout << s << endl;
            return;
      }

      if(i < a.length()) {
            s.push_back(a[i]);
            interleave2(a, b, i+1, j, s);
            s.pop_back();
      }

      if(j < b.length()) {
            s.push_back(b[j]);
            interleave2(a, b, i, j+1, s);
            s.pop_back();
      }
}



int main() {

}