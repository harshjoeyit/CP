

/*
Range Updates x1, y1, x2, y2
https://discuss.codechef.com/t/cens20a-editorial/75404
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n, m;
      cin >> n >> m;
      string s[n];
      for(int i=0; i<n; i++) {
            cin >> s[i];
      }
      
      vector<vector<int>> pref(n, vector<int>(m, 0));
      vector<vector<int>> a(n, vector<int>(m, 0));

      for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  a[i][j] = s[i][j] - '0';
            }
      }

      int q;
      cin >> q;
      while(q--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, x2--, y1--, y2--;

            pref[x1][y1] += 1;
            if(x2+1 < n && y2+1 < m) {
                  pref[x2+1][y2+1] += 1;
            } 
            if(x2+1 < n) {
                  pref[x2+1][y1] -= 1;
            }
            if(y2+1 < m) {
                  pref[x1][y2+1] -= 1;
            }
      }

      for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                  pref[i][j] += pref[i][j-1];
            }
      }

      for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                  pref[i][j] += pref[i-1][j];
            }
      }

      for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  if(pref[i][j] % 2 == 1) {
                        cout << 1-a[i][j]; 
                  } else {
                        cout << a[i][j];
                  }
            }
            cout << endl;
      }
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}