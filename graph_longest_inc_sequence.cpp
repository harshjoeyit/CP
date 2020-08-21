
// longest increasing sequnce in a matrix 
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> dp;
    int rows, cols;
    int dir[5] = {0, 1, 0, -1, 0};
    
    int dfs(int i, int j, vector<vector<int>> &mat) {
        
        int &maxFromHere = dp[i][j];
        if(maxFromHere != -1) {
            return maxFromHere;
        }
        
        maxFromHere = 0;
        for(int k=0; k<4; k++) {
            int x = i + dir[k];
            int y = j + dir[k+1];
            
            if(x<0 || y<0 || x>=rows || y>=cols || (mat[x][y] <= mat[i][j])) {
                continue;
            }
            
            maxFromHere = max(maxFromHere, dfs(x, y, mat));
        }
        
        return ++maxFromHere;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) {
            return 0;
        }
        
        rows = mat.size(), cols = mat[0].size();
        dp.assign(rows, vector<int>(cols, -1));
        int ans = 0;
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(dp[i][j] == -1) {
                    int curr = dfs(i, j, mat);
                    ans = max(ans, curr);
                }
            }
        }
        
        return ans;
    }
};