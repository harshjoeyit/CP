
/*
choosing k items either from back or front 
greedy - not dp
dp is used when some other factor is invloved too
here just sum is required  
using sliding window 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e5+10;
int n, k;
int a[2*mxN];

void solve() {
      cin >> n;
      for(int i=0; i<n; i++) {
            cin >> a[i];
            // copying array to the back
            a[n+i] = a[i];          
      }
      cin >> k;

      int s = 0;
      int ans = 0;
      // choosing initial array of size k
      for(int i=n-k; i<n; i++) {
            s += a[i];
      }
      ans = max(ans, s);
      // sliding window 
      for(int i=n-k; i<n; i++) {
            s -= a[i];
            s += a[i+k];
            ans = max(s, ans);
      }
      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}