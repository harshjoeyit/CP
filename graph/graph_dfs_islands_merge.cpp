
/*
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? 
(An island is a 4-directionally connected group of 1s).
*/

#include<bits/stdc++.h>
using namespace std;



int rows, cols;
// for marking id of islands
vector<vector<int>> ID, vis;
// map size of island to id
unordered_map<int, int> total;
int dirs[5] = {0, 1, 0, -1, 0};




int dfs(int i, int j, int id, vector<vector<int>>& grid) {
    vis[i][j] = 1;
    int cnt = 1;
	// set id 
    ID[i][j] = id;
    
    for(int k=0; k<4; k++) {
        int x = i + dirs[k];
        int y = j + dirs[k+1];
        
        if(x < 0 || y < 0 || x >= rows || y >= cols || vis[x][y] || grid[x][y] == 0) {
            continue;   
        }
        cnt += dfs(x, y, id, grid);
    }
    return cnt;
}



int largestIsland(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    
    ID.assign(rows, vector<int>(cols, 0));
    vis = ID;
    total.clear();
    
    int id = 1, ans = 0;
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                // set id and store size of island in map
                total[id] = dfs(i, j, id, grid);
                ans = max(ans, total[id]);
                id++;
            }
        }
    }

    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(grid[i][j] == 0) {
			
                unordered_set<int> islands;
                // select uniq islands , merged if grid[i][j] 0 -> 1
                
                for(int k=0; k<4; k++) {
                    int x = i + dirs[k];
                    int y = j + dirs[k+1];
                    
                    if(x < 0 || y < 0 || x >= rows || y >= cols || ID[x][y] == 0) {
                        continue;   
                    }    
                    islands.insert(ID[x][y]);
                }
                
                int curr = 1;
                // grid[i][j] 0 -> 1
                for(auto id: islands) {
                    curr += total[id];
                }
                ans = max(ans, curr);
            }
        }
    }
    
    return ans;
}