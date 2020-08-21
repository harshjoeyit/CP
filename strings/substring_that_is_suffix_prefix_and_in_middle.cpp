
/*
Finding a substring that is
1. prefix 
2. suffix
3. occurs in middle atleast once
in the string s
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> prefix_function(string s) {
      int n = s.length();
      vector<int> pi(n);
      for(int i=1; i<n; i++) {
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j]) {
                  j = pi[j-1];
            }
            if(s[i] == s[j]) {
                  ++j;
            }
            pi[i] = j;
      }
      return pi;
}

void solve() {
      string s;
      cin >> s;
      auto pi = prefix_function(s);
      int n = s.length();
      string ans;

      // case 1: there is no suffix ending that is a prefix 
      if(pi[n-1] == 0) {
            ans = "Just a legend";
      
      // case 2: a suffix of length pi[n-1] is also a prefix  
      //          and also a substring that is of same length or larger that the suffix at n-1
      //          we satisfy the required conditions  
      } else if(*max_element(pi.begin(), pi.end()-1) >= pi[n-1]) {
            ans = s.substr(0, pi[n-1]);
      
      //  case 3: only two instances occur of suffix at n-1 (one is prefix and other is itself)
      } else if(pi[pi[n-1]-1] == 0) {
            ans = "Just a legend";
      
      // else three or more instances occur of the suffix at n-1 of length pi[n-1]
      } else {
            ans = s.substr(0, pi[pi[n-1]-1]);
      }
      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}