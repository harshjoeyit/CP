
/*
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int dp[2][1005];
    
int go(int i, int swapped, vector<int> &a, vector<int> &b) {
    if(i == n) {
        return 0;
    }
       
    int &ans = dp[swapped][i];
    if(ans != -1) {
        return ans;
    }

    int aPrev = a[i - 1], bPrev = b[i - 1];
    int aCurr = a[i], bCurr = b[i];
    if (swapped) {
        // if previously swapped
        swap(aPrev, bPrev);
    }

    ans = n;

    // Note: these conditions cannot be in if else 
    // Sometimes both may work
    if(aCurr > aPrev && bCurr > bPrev) {
        // if corresponding are greater we do not swap 
        ans = min(ans, go(i + 1, 0, a, b));
    }
    if(aCurr > bPrev && bCurr > aPrev) {
        // if alternate are greater we swap 
        ans = min(ans, 1 + go(i + 1, 1, a, b));
    }

    return ans;
}
    
int minSwap(vector<int>& a, vector<int>& b) {
    n = a.size();
    memset(dp, -1, sizeof(dp));
    return min(go(1, 0, a, b), 1 + go(1, 1, a, b));
}