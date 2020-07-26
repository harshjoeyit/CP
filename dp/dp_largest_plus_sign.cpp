
/*
largest plus sign in a binary matrix 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
      vector<vector<int>> mat;
      vector<vector<pair<int, int>>> dp1, dp2;
      dp1 = dp2 = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {0, 0}));
      mat = vector<vector<int>>(n, vector<int>(n, 1));

      for (auto pt : mines) {
            mat[pt[0]][pt[1]] = 0;
      }

      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  if (mat[i][j] == 0) {
                        continue;
                  }

                  if (i == 0 || j == 0) {
                        dp1[i][j].first = dp1[i][j].second = 1;
                        continue;
                  }

                  dp1[i][j].first = dp1[i-1][j].first + 1;
                  dp1[i][j].second = dp1[i][j-1].second + 1;
            }
      }

      for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                  if (mat[i][j] == 0) {
                        continue;
                  }

                  if (i == n - 1 || j == n - 1) {
                        dp2[i][j].first = dp2[i][j].second = 1;
                        continue;
                  }

                  dp2[i][j].first = dp2[i+1][j].first + 1;
                  dp2[i][j].second = dp2[i][j+1].second + 1;
            }
      }

      int ans = 0;
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  ans = max(ans, min({dp1[i][j].first, dp2[i][j].first, dp1[i][j].second, dp2[i][j].second}));
            }
      }

      return ans;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      vector<vector<int>> v = {{3, 0}, {3, 3}};
      cout << orderOfLargestPlusSign(5, v);
}