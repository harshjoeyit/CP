
/*
finding the shortest path - if some matrix cells are obstatcle and some are not
at most k obstacles can be eliminated 
*/

#include<bits/stdc++.h>
using namespace std;

// BFS Approach 
int shortest_path(vector<vector<int>> grid, int k) {
      int rows = grid.size(), cols = grid[0].size();
      // initialising minsteps as shortest path possible
      // and assuming all the cells in the shortest path 
      // except the starting and ending are obstacles
      int min_steps = max(0, rows-1+cols-1), obstacles = min_steps - 1;
      // take a shortcut if we can afford it
      // means we can reach end even if all the cells are obstacles in the path
      if(k >= obstacles) {
            return min_steps;
      }

      vector<vector<int>> visited;
      visited.assign(rows, vector<int>(cols, -1));
      vector<vector<int>> dirs({{1, 0}, {0, 1}, {-1, 0}, {0, -1}});
      queue<vector<int>> q;
      // starting from (0, 0) with k
      q.push({0, 0, k});
      visited[0][0] = k;
      int steps = 0;

      while(!q.empty()) {
            ++steps;
            int sz = q.size();
            // BFS - sz defines one level in the bfs 
            while(sz--) {
                  int r = q.front()[0], c = q.front()[1], k = q.front()[2];
                  q.pop();
                  // for all adjacent cells of (r, c)
                  for(auto dir: dirs) {
                        int rr = r + dir[0], cc = c + dir[1];
                        if(rr < 0 || rr >= rows || cc < 0 || cc >= cols) {
                              continue;
                        }
                        int kk = k - grid[rr][cc];
                        // if been here before passing less obstacles, skip 
                        if(visited[rr][cc] >= kk) {
                              continue;
                        }

                        // may be we can try a shortcut from here 
                        // means check if we can reach the end even 
                        // if all the cells in the path are obstacles from here 
                        int steps_to_target = (rows-rr-1) + (cols-cc-1);
                        // even if all the cells are obstacles - the last must not be
                        // steps_to_target-1 = max_obstacles_possible
                        if(steps_to_target-1 <= kk) {
                              return steps + steps_to_target;
                        }
                        q.push({rr, cc, kk});
                        visited[rr][cc] = kk;
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

      for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                  cin >> grid[i][j];
            }
      }      

      cin >> k;

      cout << shortest_path(grid, k) << endl;
}