
/*
Find the longest substring with 
equal number of 0s and 1s
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// O(nlogn) approach 
void go1(string &s) {
    int n = (int)s.length();
    vector<int> v(n+1);

    for(int i=0; i<n; i++) {
        if(s[i] == '1') {
            v[i+1] = 1;
        } else {
            v[i+1] = -1;
        }
        // prefix sum array;
        v[i+1] += v[i];
    }
    
    map<int, pair<int, int>> mp;
    mp[0] = make_pair(0, 0);
    for(int i=1; i<=n; i++) {
        // if the sum reoeats in an array then there exists a subarray with sum = 0
        if(mp.count(v[i])) {
            mp[v[i]].second = i;
        } else {
        // if sum if encountered for the first time then the st, en index are same - subarrray size = en-st = 0
            mp[v[i]] = make_pair(i, i);
        }
    }

    int ans = 0;
    for(auto &p: mp) {
        // finding the max size with a subarray sum = 0
        ans = max(ans, p.second.second - p.second.first);
    }

    cout << ans << "\n";
}

// O(n) appraoch
void go2(string &s) {
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
            // use the previous occurance to find the length of that array 
            if (ump.count(v[i])) {
                  int j = ump[v[i]];
                  ans = max(ans, i - j);
            }
            else {
                  // if sum if encountered for the first time store its first occurance 
                  ump[v[i]] = i;
            }
      }

      cout << ans << "\n";
}

void solve() {
    string s;
    cin >> s;
    go1(s);
    go2(s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}