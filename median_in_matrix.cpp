#include<bits/stdc++.h>
using namespace std;

/*
    https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
    Find median in row-wise sorted matrix.

    Similar Question:
    https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
    Find kth smallest element 

     O(32 * r * log(c)) time and O(1) space
     The upper bound function will take log(c) time and is performed 
     for each row. And since the numbers will be max of 32 bit, so binary search 
     of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
*/
int median (vector<vector<int>> &mat, int r, int c) {
    int mx = 0, mn = 0;
    for(int i=0; i<r; i++) {
        mx = max(mx, mat[i][c-1]);
        mn = min(mn, mat[i][0]);
    }

    int halfLimit = (r*c + 1)/2;
    while (mn < mx) {
        int mid = mn + (mx - mn)/2;
        int cnt = 0;
        for (int i=0; i<r; i++) {
            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        if(cnt < halfLimit) {
            mn = mid + 1;
        }
        else {
            mx = mid;
        }
    }
    return mn;
}


int main() {
}