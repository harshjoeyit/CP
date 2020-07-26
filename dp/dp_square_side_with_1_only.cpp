
/*
https://www.youtube.com/watch?v=vi_1eHCsR9A&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=41
finding the largest side of a square which is mode of 1 only 
1 0 0 1 1 1
0 1 0 1 0 1
0 1 1 1 1 1
0 1 1 0 0 1
ans = 3

*/

#include<bits/stdc++.h>
using namespace std;

int n, m;

class st {
public:
      int top, left;
};

void disp(vector<vector<st>> a) {
      for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                  cout << a[i][j].top << "," << a[i][j].left << "  "; 
            }cout << endl;
      }
}

int main() {
      cin >> n >> m;
      vector<vector<int>> v;
      v.assign(n+1, vector<int>(m+1));
      vector<vector<st>> dp;
      dp.assign(n+1, vector<st>(m+1));

      for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                  cin >> v[i][j];
            }
      }

      for(int j=1; j<=m; j++) {
            if(v[1][j] == 1) {
                  dp[1][j].left += dp[1][j-1].left + 1;
                  dp[1][j].top = 1;
            }
      }
      for(int i=1; i<=n; i++) {
            if(v[i][1] == 1) {
                  dp[i][1].top += dp[i-1][1].top + 1;
                  dp[i][1].left = 1;
            }
      }

      for(int i=2; i<=n; i++) {
            for(int j=2; j<=m; j++) {
                  if(v[i][j] == 1) {
                        dp[i][j].top += dp[i-1][j].top + 1;
                        dp[i][j].left += dp[i][j-1].left + 1;
                  }
            }
      }

      // disp(dp);
      int ans = 0;

      for(int i=n; i>=1; i--) {
            for(int j=m; j>=1; j--) {
                  int mx = min(dp[i][j].top, dp[i][j].left);
                  // two sides are ready with side-length = side
                  if(ans >= mx) {
                        continue;
                  }
                  for(int side=mx; side>=1; side--) {
                        if(ans >= side) {
                              break;
                        }
                        // go left side-1, go top side-1
                        int _j = j-(side-1);
                        int _i = i-(side-1);
                        if(dp[i][_j].top >= side && dp[_i][j].left >= side) {
                              ans = max(side, ans);
                        }
                  }
            }
      }

      cout << ans << endl;
}