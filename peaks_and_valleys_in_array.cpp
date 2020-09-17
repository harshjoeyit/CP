
/*
find peaks and valleys (the a[0] and a[n-1] are to be always to be taken)

Example 
4 1 4 5 3 4 1
peaks - 4 5 4
valley - 1 3 
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++) {
            cin >> a[i];
      }
      vector<int> ans;
      vector<int> diff(n);

      for(int i=1; i<n; i++) {
            diff[i] = a[i] - a[i-1];
      }

      ans.push_back(a[0]);
      for(int i=1; i<n; i++) {
            //    peak condition                       valley condition
            if((diff[i-1] > 0 && diff[i] < 0) || (diff[i-1] < 0 && diff[i] > 0)) {
                  ans.push_back(a[i-1]);
            }
      }      
      ans.push_back(a[n-1]);

      cout << ans.size() << endl;
      for(auto x: ans) {
            cout << x << " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}