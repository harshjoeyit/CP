#include<bits/stdc++.h>
using namespace std;

/*
-- The given number is greater than the current number: 
This will ensure, that all the elements in the current row are smaller 
than the given number as the pointer is already at the right-most element 
and the row is sorted. Thus, the entire row gets eliminated and continue 
the search on the next row. Here elimination means that row needs not to 
be searched.

-- The given number is smaller than the current number: 
This will ensure, that all the elements in the current column are greater 
than the given number. Thus, the entire column gets eliminated and continue 
the search on the previous column i.e. the column at the immediate left.

The given number is equal to the current number: This will end the search.
*/

// mat is row wise and column wise sorted matrix
void searchMatrix(vector<vector<int>> &mat, int target) {

      int rows = mat.size(), cols = mat[0].size();
      if(target < mat[0][0] && mat[rows-1][cols-1] < target) {
            cout << "can't be found\n";
            return;
      }

      int i = 0, j = cols-1;
      while(j >= 0 && i < rows) {
            if(mat[i][j] == target) {
                  cout << "found at " << i << "," << j << endl;
                  return;
            } else if(mat[i][j] > target){
                  // all the elements below this element in this column are bigger
                  j -= 1;    
            } else {
                  // mat[i][j] < target
                  i += 1;
            }
      }

      cout << "not found\n";
}

// similar problem 
// matrix is sorted as 
// Matrix is sorted in a way such that all elements in a row are sorted in increasing order 
// and for row ‘i’, where 1 <= i <= n-1, the first element of row ‘i’ is greater than or equal to the last element of row ‘i-1’.

// O(log(n) + log(m))

// 1. use binary search on last column, find index of row that has value >= target
// 2. use binary_search on this row, return ans


void searchEfficient(vector<vector<int>> &mat, int target) {
      int n = mat.size(), m = mat[0].size();
      
      int low = 0, high = n-1, mid, i = -1;
      
      while(low <= high) {
            mid = (low + high) / 2;
            if(mat[mid][m-1] < target) {
                  low = mid + 1;
            } else if (mat[mid][m-1] >= target) {
                  i = mid;
                  high = mid - 1;
            }
      }
      if(i == -1) {
            cout << "not found\n";
            return;
      }
      // find in ith row
      low = 0, high = m - 1, mid;
      while(low < high) {
            mid = (low + high) / 2;
            if(mat[i][mid] < target) {
                  low = mid + 1;
            } else if(mat[i][mid] > target) {
                  high = mid - 1;
            } else {
                  cout << i << " " << mid << endl;
                  return;
            }
      }
      cout << "not found\n";
}


int main() {     
      vector<vector<int>> v = { { 10, 20, 30, 40 }, 
                      { 15, 25, 35, 45 }, 
                      { 27, 29, 37, 48 }, 
                      { 32, 33, 39, 50 } };
      
      searchMatrix(v, 34);
}
