#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e3+10;
int n, a[mxN], dp[mxN][mxN];

int go(int i, int j) {    
      if(i == n+1) {
            return 0;
      }
      if(dp[i][j] != -1) {
            return dp[i][j];
      }
      int ans;
      if(a[i] > a[j]) {
            ans = max(go(i+1, j), a[i] ^ go(i+1, i));
      } else {
            ans = go(i+1, j);
      }
      return dp[i][j] = ans;
}

void solve() {     
      cin >> n;
      for(int i=1; i<=n; i++) {
            cin >> a[i];
      }
      memset(dp, -1, sizeof(dp));
      cout << go(1, 0) << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}