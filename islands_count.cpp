#include <bits/stdc++.h>
using namespace std;

// number of island problem using DFS

int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};

void dfs(int i, int j, vector<vector<char>> &grid)
{
      grid[i][j] = '0';
      int rows = grid.size(), cols = grid[0].size();

      for (int k = 0; k < 4; k++)
      {
            int x = i + dirx[k];
            int y = j + diry[k];
            if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == '0')
            {
                  continue;
            }

            dfs(x, y, grid);
      }
}

int numIslandsDFS(vector<vector<char>> &grid)
{
      if (grid.size() == 0 || grid[0].size() == 0)
      {
            return 0;
      }

      int rows = grid.size(), cols = grid[0].size();
      int ans = 0;

      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  if (grid[i][j] == '1')
                  {
                        ++ans;
                        dfs(i, j, grid);
                  }
            }
      }

      return ans;
}


// island problems using BFS

int numIslands(vector<vector<char>> &grid)
{
      int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  if (grid[i][j] == '1')
                  {
                        islands++;
                        grid[i][j] = '0';
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        while (!q.empty())
                        {
                              pair<int, int> p = q.front();
                              q.pop();
                              for (int k = 0; k < 4; k++)
                              {
                                    int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
                                    {
                                          grid[r][c] = '0';
                                          q.push({r, c});
                                    }
                              }
                        }
                  }
            }
      }
      return islands;
}


// another version of island problems 
// all connected 0 are island 
// island should be completely surrounded by the water(1) on all sides 
// that is island should not be on the border


int rows, cols;
    int dir[5] = {0, 1, 0, -1, 0};
    bool flag;
    
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 1;
        
        for(int k=0; k<4; k++) {
            int x = i + dir[k];
            int y = j + dir[k+1];
        
            if(x<0 || y<0 || x>=rows || y>=cols) {
                // border reached, not a island
                flag = false;
                // do not return, we have to exhaust all the 0 to 1
                // so continue
                continue;
            }
            if(grid[x][y] == 1) {
                continue;
            }

            dfs(x, y, grid);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 0) {
                    flag = true;
                    dfs(i, j, grid);
                    if(flag) {
                          // add if valid island
                        ans += 1;
                    }
                }
            }
        }
        
        return ans;
    }

int main() {
}