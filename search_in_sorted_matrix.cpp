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
void searchMatrix(vector<vector<int>> &mat, int val) {

      int rows = mat.size(), cols = mat[0].size();
      if(val < mat[0][0] && mat[rows-1][cols-1] < val) {
            cout << "can't be found\n";
            return;
      }

      int i = 0, j = cols-1;
      while(j >= 0 && i < rows) {
            if(mat[i][j] == val) {
                  cout << "found at " << i << "," << j << endl;
                  return;
            } else if(mat[i][j] > val){
                  // all the elements below this element in this column are bigger
                  j -= 1;    
            } else {
                  // mat[i][j] < val
                  i += 1;
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