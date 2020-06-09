
/*
https://codeforces.com/contest/1365/problem/C

given two arrays a, b 
maximum element matching in two arrays after cyclic rotations of the array 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n;
      int x;
      cin >> n;
      vector<int> a(n);
      unordered_map<int, int> ump;
      unordered_map<int, int> freq;

      for(int i=0; i<n; i++) {
            cin >> a[i];
      }
      // mapping index for the values in second premutation
      for(int i=0; i<n; i++) {
            cin >> x;
            ump[x] = i;
      }
      // finding how many right cyclic rotations would each element take to match with the element in second array
      for(int i=0; i<n; i++) {
            x = a[i];
            // index in second array for value x
            int j = ump[x];         
            if(j-i >= 0) {
                  freq[j-i] += 1;
            } else {
                  freq[n+(j-i)] += 1;
            }
      }

      // we have stored the rotations in groups 

      // the ans is where the maximum elements match 
      int ans = 0;
      for(auto p: freq) {
            // cout << p.first << " " << p.second << endl;
            ans = max(ans, p.second);
      }

      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}