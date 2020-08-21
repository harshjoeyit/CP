#include <bits/stdc++.h>
using namespace std;

int go(int start, string &s, unordered_set<string> &dict, vector<int> &dp) {

      if(start == s.length()) {
            return 1;
      }
      if(dp[start] != -1) {
            return dp[start];
      }

      string curr = "";
      int ans = 0;
      // we are able to break the string succesfully before start 
      // now check of the string after start can be broken or not 
      for(int i=start; i<s.length(); i++) {
            curr.push_back(s[i]);
            // if curr substring matches we have 
            // option 1: to break here at i and look for after i+1
            if(dict.count(curr)) {
                  ans |= go(i+1, s, dict, dp);
            }
            // option 2: continue with loop and find if any other string (curr)
            // matches in dict or not (we have to look for all possiblities from start index)
      }
      dp[start] = ans;
      return dp[start];
}

// top down appraoch
bool wordBreak(string s, vector<string> &wordDict) {
      unordered_set<string> dict;
      vector<int> dp(s.length()+1, -1);
      for (auto &word : wordDict) {
            dict.insert(word);
      }
      return go(0, s, dict, dp);
}

// bottom up approach 
bool wordBreak(string s, vector<string> &wordDict) {
      unordered_set<string> dict;
      vector<bool> dp(s.length()+1, false);
      for (auto &word : wordDict) {
            dict.insert(word);
      }
    
      int n = s.length();
      dp[n] = true;
      for(int i=n-1; i>=0; i--) {
            string curr = "";
            for(int j=i; j<n; j++) {
                  curr.push_back(s[j]);
                  if(dict.count(curr)) {
                        // string s[i.....j] can be found in dict 
                        if(dp[j+1]) {
                              // dp[j+1] = true means
                              // string from s[j+1.........n] 
                              // can be succesfully broken 
                              dp[i] = true;
                              // this means s[i......n-1] can be succesfully broken
                            break;
                        }
                  }

            }
      }
      return dp[0];
}
int main() {
      string s;
      cin >> s;
      int n;
      cin >> n;
      vector<string> dict(n);
      for(int i=0; i<n; i++) {
            cin >> dict[i];
      }
      cout << wordBreak(s, dict);
}