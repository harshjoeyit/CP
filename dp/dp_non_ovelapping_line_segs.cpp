
/*
https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/submissions/
*/

#include<bits/stdc++.h>
using namespace std;

int n;
const int mod = 1e9+7;
long long int dp[1005][1005][3];

// startHere = 1, means we can start to draw a line from here 
// startHere = 0, means line is continuing we can choose to stop 
//                and start a new from this very point

int go(int i, int k, int startHere) {
    if(k == 0) {
        return 1;
    }
    if(i == n) {
        return 0;
    }
    
    // skip this point
    // if startHere = 1, if we skip, we choose not to draw a line
    // if startHere = 0, if we skip, we choose to continue this line 
    //                   without marking and end point here
    long long int &ans = dp[i][k][startHere];
    if(ans != -1) {
        return ans;
    } 
    ans = go(i+1, k, startHere);
    
    if(startHere == 1) {
        // start the line 
        ans += go(i+1, k, 0);
        // we do not reduce k, we will decrement it when we find the end point of this line
    } else {
        // end the line here at (i), decrement k, 
        // since we can start a new line again from here at (i), so
        ans += go(i, k-1, 1);
    }
    
    ans %= mod;
    return ans;
}

int numberOfSets(int n, int k) {
    this->n = n;
    memset(dp, -1, sizeof(dp));
    return go(0, k, 1);
}
