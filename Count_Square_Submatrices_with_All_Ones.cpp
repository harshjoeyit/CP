
/*
counting square submatrices that have only 1s

for every cell we store the total number of square 
matrices that are possible conisdering this cell as 
bottom right corner 

 - for borders with i = 0 or j = 0, square matrix of size 1 is possible 
that too when matrix[i][j] = 1

- for inner cell we use the previously stored results(dp)
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long 

int countSquares(vector<vector<int>> &matrix) {

      int rows = matrix.size();
      if (rows == 0) {
            return 0;
      }
      int cols = matrix[0].size();
      int ans = 0;

      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  if (matrix[i][j] == 0) {
                        continue;
                  
                  if (i == 0 || j == 0) {
                        ans += 1;
                        continue;
                  }

                  // we the minimum of diagonal, top - length, left - length
                  // taking minimum makes sure that the square larger than 
                  // this side length is not possible 

                  int total = min({matrix[i - 1][j - 1],
                                  matrix[i - 1][j],
                                  matrix[i][j - 1]});

                  matrix[i][j] += total;
                  ans += matrix[i][j];
            }
      }

      return ans;
}

/*
Similar problem - find the area of the largest square with all one's inside 
                  - largest plus sign
*/