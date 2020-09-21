
#include<bits/stdc++.h>
using namespace std;

int maxProductPath(vector<vector<int>>& grid) {
    const int mod = 1e9+7;
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<long long int>> pos(rows, vector<long long int>(cols, 0));
    auto neg = pos;
    
    long long int p = 1;
    for(int j=0; j<cols; j++) {
        p *= grid[0][j];
        if(p == 0) {
            pos[0][j] = neg[0][j] = 0; 
        } else if(p > 0) {
            pos[0][j] = p;
            // neg path does not exist to [i, j]
            neg[0][j] = 1;
        } else {
            neg[0][j] = p;
            // positive path does not exist to [i,j]
            pos[0][j] = -1;
        }
    }
    
    p = 1;
    
    for(int i=0; i<rows; i++) {
        p *= grid[i][0];
        if(p == 0) {
            pos[i][0] = neg[i][0] = 0; 
        } else if(p > 0) {
            pos[i][0] = p;
            // positive path does not exist to [i,j]
            neg[i][0] = 1;
        } else {
            neg[i][0] = p;
            // positive path does not exist to [i,j]
            pos[i][0] = -1;
        }
    }

    for (int i = 1; i < rows; i++) {
          for (int j = 1; j < cols; j++) {
                // max pos path
                auto mp = max(pos[i - 1][j], pos[i][j - 1]);
                // min neg path
                auto mn = min(neg[i - 1][j], neg[i][j - 1]);

                if (grid[i][j] == 0) {
                      pos[i][j] = neg[i][j] = 0;
                }
                else if (grid[i][j] > 0) {
                      pos[i][j] = mp * grid[i][j];
                      neg[i][j] = mn * grid[i][j];
                }
                else {
                      pos[i][j] = mn * grid[i][j];
                      neg[i][j] = mp * grid[i][j];
                }
          }
    }

    auto &ans = pos[rows - 1][cols - 1];
    // if negetive path does not exit return -1
    return (ans < 0) ?-1 :ans % mod;
}