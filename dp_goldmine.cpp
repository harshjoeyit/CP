
/*
Goldmine Problem 

Given a gold mine of n*m dimensions. 
Each field in this mine contains a positive integer which is the amount of gold in tons. 
Initially the miner is at first column but can be at any row. 
He can move only  the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. 
Find out maximum amount of gold he can collect.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

int goldmine(vector<vector<int>> a) {
      int rows = a.size(), cols = a[0].size();
      int dirs[3] = {-1, 0, 1};
      vector<vector<int>> dp(a);

      for (int j = 1; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                  int mx = 0;
                  // check all the 3 possiblilities miner reaches this cell
                  for (int k = 0; k < 3; k++) {
                        int x = i + dirs[k], y = j - 1;
                        if(x < 0 || y < 0 || x >= rows || y >= cols) {
                              continue;
                        }
                        mx = max(mx, dp[x][y]);
                  }
                  dp[i][j] += mx;
            }
      }

      int ans = 0;
      for (int i = 0; i < rows; i++) {
            ans = max(ans, dp[i][cols - 1]);
      }
      return ans;
}

signed main() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> a(n, vector<int>(m, 0));
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                  cin >> a[i][j];
            }
      }

      cout << goldmine(a);
}