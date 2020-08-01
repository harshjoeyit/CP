#include <bits/stdc++.h>
using namespace std;

/* find area of largest square submatrix which has only 1s inside */

int maximalSquare(vector<vector<char>> &mat) {
      if(mat.size() == 0) {
            return 0;
      }
      int rows = mat.size(), cols = mat[0].size();
      vector<vector<int>> matrix(rows, vector<int>(cols, 0));

      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  if (mat[i][j] == '1') {
                        matrix[i][j] = 1;
                  }
            }
      }

      int maxSide = 0;
      // consider i, j as bottom left corner of the square 
      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  if (matrix[i][j] == 0) {
                        continue;
                  }
                  // matix[i][j] = 1

                  if (i == 0 || j == 0) {
                        if (maxSide == 0) {
                              maxSide = 1;
                        }
                        continue;
                  }

                  // we have to check the diagonal as well, since the matrix should be filled with 1
                  int maxPossible = min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
      
                  matrix[i][j] = maxPossible + 1;
                  
                  maxSide = max(matrix[i][j], maxSide);
            }
      }
      return (maxSide * maxSide);
}


/*
counting square submatrices that have only 1s inside 

for every cell we store the total number of square 
matrices that are possible conisdering this cell as 
bottom right corner 

1) for borders with i = 0 or j = 0, square matrix of size 1 is possible 
that too when matrix[i][j] = 1

2) for inner cell we use the previously stored results(dp)
 */

int countSquares(vector<vector<int>> &matrix) {
      if(matrix.size() == 0) {
            return 0;
      }
      int rows = matrix.size(), cols = matrix[0].size();
      int ans = 0;

      // if matrix[i][j] = p
      // then it means p squares of side 1, 2, 3.....p 
      // can be formed using i, j as bottom right corner of square    

      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  // no square can be formed using this as bottom left corner 
                  if (matrix[i][j] == 0) {
                        continue;
                  // squares on border 
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
                  // also correct 
                  // matrix[i][j] = total + 1; 
                  // (add 1 considering the square with side 1 at i, j)
                  // since matrix[i][j] is already 1, so += also works same

                  ans += matrix[i][j];
            }
      }

      return ans;
}

int main()
{
}