
/*
Find the longest substring with 
equal number of zeroes and ones
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      string s;
      cin >> s;
      int n = (int)s.length();
      vector<int> v(n + 1);

      for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                  v[i + 1] = 1;
            }
            else {
                  v[i + 1] = -1;
            }
            // prefix sum array;
            v[i + 1] += v[i];
      }

      int ans = 0;
      // <sum , first index> 
      unordered_map<int, int> ump;
      for (int i = 0; i <= n; i++) {
            // if the sum repeats in an array then there exists a subarray with sum = 0
            if (ump.count(v[i])) {
                  int j = ump[v[i]];
                  ans = max(ans, i - j);
            }
            else {
                  // if sum if encountered for the first time then the st, en index are same - subarrray size = en-st = 0
                  ump[v[i]] = i;
            }
      }

      cout << ans << "\n";
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}