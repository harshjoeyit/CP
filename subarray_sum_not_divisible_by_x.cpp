
/*
Longest Subarray with sum not divisible by x 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n, x;
      cin >> n >> x;
      vector<int> a(n);
      
      int s = 0;
      bool alldiv = true;

      for(int i=0; i<n; i++) {
            cin >> a[i];
            s += a[i];
            if((a[i] % x) != 0) {
                  alldiv = false;
            }
      }
      // if all the elements are divisible by x - then - no subarray possible
      if(alldiv) {
            cout << -1 << endl;
            return;
      }
      // if sum of all the elements is not divisible by x
      if(s % x != 0) {
            cout << n << endl;
            return;
      }

      // a valid subarray exist, we remove elements from prefix or suffix - 
      // because removing from both ends would shorten the array uneccesarily
      // also removing elements that are divisible by x - renders the array sum still divisible by x
      // so we find the first pos i from start such that a[i] % x != 0 and remove the whole prefix
      // or we find the first pos i from end such that a[i] % x != 0 and remove the whole suffix      

      int ans=0;
      for(int i=0; i<n; i++) {
            if(a[i] % x != 0) {
                  // remaining array size if prefix is removed = n-(i+1)
                  // if suffix is removed = i
                  ans = max({ans, n - (i+1), i});
            }
      }
      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}