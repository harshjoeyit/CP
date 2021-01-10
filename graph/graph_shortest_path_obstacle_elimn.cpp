
/*
> finding the shortest path - if some matrix cells are obstatcle and some are free 
> at most k obstacles can be eliminated 
*/

#include<bits/stdc++.h>
using namespace std;

// BFS Approach 
int shortest_path(vector<vector<int>> grid, int k) {
      int rows = grid.size(), cols = grid[0].size();
      // initialising minSteps as shortest path possible
      // by assuming all the cells in the shortest path 
      // except the starting and ending are obstacles
      int minSteps = max(0, rows-1+cols-1), obstacles = minSteps - 1;

      if(k >= obstacles) {
            // take a shortcut if we can afford it
            // means we can reach end even if all the cells are obstacles in the path
            return minSteps;
      }

      // vis works as dp array 
      // vis[i][j] = minimum obstacles eliminated before reaching here
      vector<vector<int>> vis;
      vis.assign(rows, vector<int>(cols, -1));

      int dirs[5] = {0, 1, 0, -1, 0};
      queue<vector<int>> q;
      // starting from (0, 0) with k 
      // means we have power to elimate k obstacles 
      q.push({0, 0, k});
      vis[0][0] = k;
      int steps = 0;

      while(!q.empty()) {
            ++steps;
            // one level traversed 
            int sz = q.size(); 
            while(sz--) {
                  int i = q.front()[0];
                  int j = q.front()[1];
                  k = q.front()[2];
                  q.pop();

                  // for all adjacent cells 
                  for(int d=0; d<4; d++) {
                        int x = i + dirs[d];
                        int y = j + dirs[d+1];
                        
                        if(x < 0 || x >= rows || y < 0 || y >= cols) {
                              continue;
                        }

                        int remK = k - grid[x][y];
                        // k decrements if (x, y) is obstacle

                        if(vis[x][y] >= remK) {
                              // if been here before passing less obstacles, skip 
                              continue;
                        }

                        /* may be we can try a shortcut from here 
                        means check if we can reach the end even 
                        if all the cells in the path are obstacles from here 
                        even if all the cells are obstacles - the last must not be
                        max obstacles possible from here = steps_to_target-1 */

                        // shortcut code causing problem in 
                        // https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/submissions/

                        // int steps_to_target = (rows-x-1) + (cols-y-1);
                        // if(steps_to_target-1 <= remK) {
                        //       return steps + steps_to_target;
                        // }

                        q.push({x, y, remK});
                        vis[x][y] = remK;
                  }
            }
      }
      return -1;
}


int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int rows, cols, k;
      cin >> rows >> cols;
      vector<vector<int>> grid;
      grid.assign(rows, vector<int>(cols));

      // free cells are 0
      // obstacles are 1

      for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                  cin >> grid[i][j];
            }
      }      

      cin >> k;
      cout << shortest_path(grid, k) << endl;
}