#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n;
      cin >> n;
      if(n == 1) {
            cout << 1 << endl;
            return;
      } 
      int ans = 6*n*n - 12*n + 8;
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