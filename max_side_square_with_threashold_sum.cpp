

#include<bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<int>> prefix;

void calcPrefix(vector<vector<int>>& mat) {
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + mat[i-1][j-1] - prefix[i-1][j-1];
        }
    }
}

int sum(int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1][y2] - prefix[x2][y1] + prefix[x1][y1];
}


// Method 1 O(n*mLog(min(n, m)))

bool findOne(int side, vector<vector<int>>& mat, int threshold) {
    // check each square with side = side
    for(int i=side; i<=rows; i++) {
        for(int j=side; j<=cols; j++) {
            // i, j - lower right corner of square
            int s = prefix[i][j]  - prefix[i-side][j] - prefix[i][j-side] + prefix[i-side][j-side];
            if(s <= threshold) {
                return true;
            }
        }
    }
    return false;
}

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    rows = mat.size();
    cols = mat[0].size();
    
    prefix.assign(rows + 1, vector<int>(cols + 1, 0));
    calcPrefix(mat);

    int low = 1, high = min(rows, cols);
    int ans = 0;
    
    while(low <= high) {
        int side = (low + high) / 2;
        if(findOne(side, mat, threshold)) {
            // found at least one valid square 
            ans = max(ans, side);
            low = side + 1;
        } else {
            // couldn't find any valid square
            high = side - 1;
        }
    }
    
    return ans;
}



// Method 2 O(n*m)

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    rows = mat.size();
    cols = mat[0].size();
    
    prefix.assign(rows + 1, vector<int>(cols + 1, 0));
    calcPrefix(mat);
    
    int res = 0;
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            int len = res+1;
            while (i+len <= rows && j+len<= cols && sum(i, j, i+len, j+len) <= threshold) {
                res = len;
                len++;
            }
        }
    }
    return res;
}