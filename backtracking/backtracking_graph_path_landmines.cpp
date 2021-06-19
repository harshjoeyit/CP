/*
    Find Shortest Path with Landmines 
    Rule, Neither the landmine, nor neighbour of a landmine can be visited
    https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> dirs = {-1,0,1,0,-1};

// BFS 
int bfs(int i, vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, 0});
    grid[i][0] = 0;
    int dis = 0;

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto i = q.front().first, j = q.front().second;
            q.pop();

            if(j == m-1) {
                return dis;
            }

            for(int k=0; k<4; k++) {
                int x = i + dirs[k];
                int y = j + dirs[k+1];
                if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == 0 || grid[x][y] == -1) {
                    continue;
                }
                q.push({x, y});
            }
        }
        dis++;
    }
    return INT_MAX;
}

// Backtracking DFS
int dfs(int i, int j, vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    if(j == m-1) {
        return 0;
    }
    int dis = INT_MAX;
    grid[i][j] = 0;

    for(int k=0; k<4; k++) {
        int x = i + dirs[k];
        int y = j + dirs[k+1];
        if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == 0 || grid[x][y] == -1) {
            continue;
        }
        dis = min(dis, dfs(x, y, grid));
    }

    grid[i][j] = 1;
    return (dis == INT_MAX) ? INT_MAX: (dis + 1);
}

// Note: Don't mark with 0, mark with any other number
void markNeighbours(int i, int j, vector<vector<int>> &grid, int n, int m) {
    if(i-1 >= 0)    grid[i-1][j] = -1;
    if(i+1 < n)     grid[i+1][j] = -1;
    if(j-1 >= 0)    grid[i][j-1] = -1;
    if(j+1 < m)     grid[i][j+1] = -1;
}

void shortestPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 0) {
                // cannot visit the neighbours of a landmine
                markNeighbours(i, j, grid, n, m);
            }
        }
    }
    int ans = INT_MAX;
    // BFS answer 
    for(int i=0; i<n; i++) {
        if(grid[i][0] == 1) {
            ans = min(ans, bfs(i, grid));
        }
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << "\n";

    // Backtraking answer
    for(int i=0; i<n; i++) {
        if(grid[i][0] == 1) {
            ans = min(ans, dfs(i, 0, grid));
        }
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << "\n";
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}
    };

    shortestPath(grid);
}