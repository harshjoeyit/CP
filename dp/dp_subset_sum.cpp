#include<bits/stdc++.h>
using namespace std;

// divide array into two subsets with with minimum difference b.w them 
// similar problem 
// https://leetcode.com/problems/last-stone-weight-ii/submissions/


// {index, sum}
int dp[32][3005];
int n, total;

int go(int i, int s, vector<int> &a) {
    if(i == n) {
        // s1 = s, s2 = total - s
        // diff = abs(s2 - s1) = abs(total - 2*s) 
        return abs(total - 2*s);
    }
    int &ans = dp[i][s];
    if(ans != -1) {
        return ans;
    }
    
    return ans = min(go(i+1, s, a), go(i+1, s + a[i], a));
}

int lastStoneWeightII(vector<int>& a) {
    n = a.size();
    total = accumulate(a.begin(), a.end(), 0);
    memset(dp, -1, sizeof(dp));
    return go(0, 0, a);
}