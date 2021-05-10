
/*
Two players play the game of choosing the stone fron either end.
On each change the score of sum of remainging stones after choosing.
Find the minimum score difference
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> prefix;
int dp[1002][1002];

int go(int i, int j, int sum, vector<int> &a) {
    if(i > j) {
        return 0;
    }
    
    int &ans = dp[i][j];
    if(ans != -1) {
        return ans;
    }
    
    // we subtract go(...)
    // because each player wants to substract the result of other player 
    int front = sum-a[i] - go(i+1, j, sum-a[i], a);
    int back = sum-a[j] - go(i, j-1, sum-a[j], a);
    // since alice has the first choice she has advantage of winning each time
    
    return ans = max(front, back);
}

int stoneGameVII(vector<int>& a) {
    int n = a.size();
    int sum = accumulate(a.begin(), a.end(), 0);
    memset(dp, -1, sizeof(dp));
    
    return go(0, n-1, sum, a);
}