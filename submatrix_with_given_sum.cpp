#include <bits/stdc++.h>
using namespace std;

// we use same approach that we use for 1-d array 

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
      if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
      }

      int rows = matrix.size(), cols = matrix[0].size();
      vector<vector<int>> prefixColSum(rows+1, vector<int>(cols));

      // calculating prefix sum for each column, 
      // the first row of the prefixColSum - 0, 0, .....
      for(int j=0; j<cols; j++) {
            for(int i=0; i<rows; i++) {
                  prefixColSum[i+1][j] = matrix[i][j] + prefixColSum[i][j];
            }
      }

      unordered_map<int, int> ump;
      int ans = 0;

      // we fix each row then so down as much as we can 
      // this is similar to the way we find subarrays in an array 
      for(int fixedRow = 0; fixedRow < rows; fixedRow++) {
            // go down the remaining rows 
            // the top side id on the fixed row 
            for(int row = fixedRow; row < rows; row++) {
                  // the height of all the rectangles for
                  // this iteration id defference b/w
                  // row and fixedRow
                  
                  ump.clear();
                  int s = 0;

                  // moving accross all the columns just like 
                  // we would have done it in a 1-d array 
                  for(int j=0; j<cols; j++) {
                        // the width of the column is decided by j
                        s += prefixColSum[row + 1][j] - prefixColSum[fixedRow][j];

                        // this code is similar to 1-d version
                        if(s == target) {
                              ans += 1;
                        }   
                        if(ump.count(s - target) > 0) {
                              ans += ump[s - target];
                        }
                        ump[s] += 1;
                  }
            } 
      }

      return ans;
}

int main() {
      int rows, cols, s; 
      cin >> rows >> cols >> s;
      vector<vector<int>> v(rows, vector<int>(cols));

      for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                  cin >> v[i][j];
            }
      }

      cout << numSubmatrixSumTarget(v, s) << endl;
}