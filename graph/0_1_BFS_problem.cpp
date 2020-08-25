

/*
given a matrix with cells as 0, 1 only
0 - we can move without cost 
1 - we move with paying 1 as cost 

find min cost to reach all cells 
*/

#include<bits/stdc++.h>
using namespace std;

void minCost(vector<vector<int>> &mat) {
      int rows = mat.size(), cols = mat[0].size();
      
      const int INF = 1e9;
      vector<vector<int>> cost;
      cost.assign(rows, vector<int>(cols, INF));
      cost[0][0] = 0;

      deque<vector<int>> dq;
      dq.push_back({0, 0});
      int dirs[5] = {0, 1, 0, -1, 0};

      while (!dq.empty())  {
            int i = dq.front()[0];
            int j = dq.front()[1];
            dq.pop_front();

            for(int k=0; k<4; k++) {
                  int x = i + dirs[k];
                  int y = j + dirs[k+1];

                  if(x<0 || y<0 || x>=rows || y>cols) {
                        continue;
                  }
                    
                  if(cost[x][y] > cost[i][j] + mat[x][y]) {
                        cost[x][y] = cost[i][j] + mat[x][y];
                        if(mat[i][j] == 1) {
                              dq.push_back({x, y});
                        } else {
                              dq.push_front({x, y});
                        }
                  }
            }
      }

      for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                  cout << cost[i][j] << " ";
            }
            cout << "\n";
      }
}     

int main() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> mat(n, vector<int>(m,0));
      for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  cin >> mat[i][j];
            }
      }
      minCost(mat);
}