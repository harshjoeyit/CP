

#include<bits/stdc++.h>
using namespace std;

string findMinWindow(string s, string pat) {
      int n = s.length();
      int m = pat.length();

      if(n < m) {
            return "";
      }

      int hashPat[256] = {}, hashStr[256] = {};

      for (int i = 0; i < m; i++) {
            hashPat[pat[i]] += 1;
      }

      int l = 0, ansLeft = -1, minLen = INT_MAX;
      int count = 0;

      for (int j = 0; j < n; j++) {
            hashStr[s[j]] += 1;

            if(hashPat[s[j]])
      }
}

int main() {

}