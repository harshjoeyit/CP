#include <bits/stdc++.h>
using namespace std;

// Easiest method 
void transpose(vector<vector<int>> &mat) {
    int n = mat.size();
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void rotateby90Clockwise(vector<vector<int>>& mat) {
    transpose(mat);
    for(auto &v: mat) {
        reverse(v.begin(), v.end());
    }
}

void rotateby90Anticlockwise(vector<vector<int>>& mat) {
    transpose(mat);
    int n = mat.size(), m = mat[0].size();
    // reverse each column
    for(int j=0; j<m; j++) {
        for(int i=0; i<n/2; i++) {
            swap(a[i], a[n-i-1]);
        }
    }
}

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