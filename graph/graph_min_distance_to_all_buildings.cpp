
/*
      mat[i][j] = {0, 1, 2}
      0 - empty, can pass through
      1 - building, cannot pass through
      2 - obstacle, cannot pass through 
      Find the empty block such that all the buildings are at shortest distance from it.

      cnt[i][j] - number of building reachable 
      dis[i][j] - total distance to reachable buildings from here 
*/

#include<bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<int>> dis, vis, cnt;
int dirs[5] = {0, 1, 0, -1, 0};

void bfs(int i, int j, vector<vector<int>> &mat) {
      queue<pair<int, int>> q;
      q.push({i, j});
      vis[i][j] = 1;
      int level = 0;

      while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                  i = q.front().first;
                  j = q.front().second;
                  q.pop();

                  if(mat[i][j] == 0) {
                        dis[i][j] += level;
                        cnt[i][j] += 1;
                  }

                  for (int k = 0; k < 4; k++) {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];

                        if(x < 0 || y < 0 || x >= rows || y >= cols || vis[x][y] == 1 || mat[x][y] != 0) {
                              continue;
                        }

                        vis[x][y] = 1;
                        q.push({x, y});
                  }
            }
            level += 1;
      }
}

int shortestDistanceFromAll(vector<vector<int>> &mat) {
      rows = mat.size(), cols = mat[0].size();

      dis.assign(rows, vector<int>(cols, 0));
      vis = cnt = dis;

      int buildCnt = 0;
      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  // if it is building
                  if(mat[i][j] == 1) {
                        buildCnt += 1;
                        vis.assign(rows, vector<int>(cols, 0));
                        bfs(i, j, mat);
                  }
            }
      }

      int ans = INT_MAX;

      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  if(mat[i][j] == 0 && cnt[i][j] == buildCnt) {
                        ans = min(ans, dis[i][j]);
                  }
            }
      }

      return (ans == INT_MAX) ? -1 : ans;
}

int main() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> v(n, vector<int>(m, 0));
      for(auto &vec: v) {
            for(auto &val: vec) {
                  cin >> val;
            }
      }
      cout << shortestDistanceFromAll(v) << "\n";
}