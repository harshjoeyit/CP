
/*
counting total submatrices with all 1s inside 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

// function to count number of rectangles possible with top left corner (x, y)

int countStartingFromThisCell(vector<vector<int>> &mat, int x, int y) {
      int rows = mat.size();
      int cols = mat[0].size();
      int bound = cols;
      int ans = 0;

      for (int i = x; i < rows; i++) {
            for (int j = y; j < bound; j++) {
                  if (mat[i][j] == 1) {
                        // add 1 since, if we are at i, j 
                        // it means this is (x, y) -> (i, j) is a new (unique rectangle)
                        ans += 1;
                  }
                  else {
                        // if mat[i][j] = 0
                        // then no rectangle past this point is possible with top left corner (x, y)
                        // so we shrink the search space 
                        bound = j;
                  }
            }
      }

      // ans = number of rectangles possible when the top left corner is (x, y)
      return ans;
}


int numSubmat(vector<vector<int>> &mat) {
      int rows = mat.size();
      int cols = mat[0].size();
      int ans = 0;

      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  ans += countStartingFromThisCell(mat, i, j);
            }
      }
      return ans;
}
