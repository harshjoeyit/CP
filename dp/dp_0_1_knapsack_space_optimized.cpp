

/*
Space Optimesd solution for 0-1 Knpsack
fill knapsack with max val sum with wieghts sum <= capacity

*/


#include<bits/stdc++.h>
using namespace std;

const int mxW = 1e6; 
int dp[mxW];            // dp[w] - max value possible for wieght w

int fill_knapsack(int val[], int wt[], int n, int w) {
    
    for(int i=0; i<n; i++) 
        for(int j=w; j>=wt[i]; j--) 
            dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);

    return dp[w];
}

int main() {
    int val[] = {8, 6, 4, 3}; 
    int wt[] = {3, 6, 2, 2}; 
    int w = 10;                 // w <= 1e6
    int n = sizeof(val)/sizeof(val[0]);

    cout << fill_knapsack(val, wt, n, w);
}