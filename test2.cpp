#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int x, n;
      cin >> n;
      vector<bitset<12>> v(n);
      for(int i=0; i<n; i++) {
            cin >> x;
            v[i] = bitset<12>(x);
            cout << v[i] << endl;
      }

      if(n % 2 == 1) {
            cout << -1 << endl;
            return;                 
      }

      int ans = 0;
      for(int i=0; i<11; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                  if(v[j][i] == 1) {
                        cnt += 1;
                  }
            }
            if(cnt == n/2) {
                  ans += (1 << i);
            }
      }
      if(ans == 0) {
            ans = -1;
      }
      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--) {
            solve();
      }
}