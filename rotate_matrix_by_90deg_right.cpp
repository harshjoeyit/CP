#include <bits/stdc++.h>
using namespace std;

// there is noticable pattern - to where the values a placed in rotated matrix 
// with respect to their original positions in the given matrix 
void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int a = 0;
      int b = n-1;
      // a == b means the center element in the matrix (if there is in n = 3, 5, 7.., so we stop)
      while(a < b) {
            for(int i=0; i<b-a; i++) {
                  swap(matrix[a][a+i], matrix[a+i][b]);
                  swap(matrix[a][a+i], matrix[b][b-i]);
                  swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a, --b;
      }
}

int main()
{
}