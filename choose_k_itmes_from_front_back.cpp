
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
int a[mxN];

void solve() {
      cin >> n;
      cin >> k;
      int tot = 0;
      for (int i = 0; i < n; i++) {
            cin >> a[i];
            tot += a[i];
      }

      int s = 0, i;
      int ans = 0;
      // choosing initial array of size n-k
      // remaining elements are n-k from front and back
      for(i=0; i<n-k; i++) {
            s += a[i];
      }
      ans = max(ans, tot - s);
      // sliding window 
      for(; i<n; i++) {
            s -= a[i-(n-k)];
            s += a[i];
            ans = max(ans, tot - s);
      }

      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}