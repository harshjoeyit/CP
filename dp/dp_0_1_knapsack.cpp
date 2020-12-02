#include<bits/stdc++.h>
using namespace std;
#define int long long int

/*
      original problem: 
      Given a knapsack(W) and n weights , 
      find if kanpsack can be filled completely 

      or simly

      find a subset with sum = W 
*/

// 1. top down DP

// 2. bottom up DP

void go() {
	int dp[1000] = {};
	int n, x, W;
	cin >> n >> W;
	dp[0] = true;
	for(int id = 0; id < n; id++) {
		cin >> x;
		for(int i = W; i >= x; i--) {
			if(dp[i-x]) dp[i] = true;
		}
	}
	cout << (dp[W] ? "YES" : "NO");
}

/*
3. Using bitset

after this operation all every ith bit is set 
such that sum i is possible using the value up untill now  
Examlpe
x = 2     dp = ..00000000101 			         	- possible sums {2}
x = 3     dp = ..0000000101 | ..000000101000 = ..00000101101 	- possible sums {2, 3, 5}
x = 4     dp = ..00000101101 | ..01011010000 = ..1011111101  	- possible sums {2, 3, 5, 4, 4, 7, 9} 
Note: writing this way it is faster than dp = dp | (dp << x)
*/

void go() {
	bitset<1000001> dp;
    	int w, n, x;                   // n <= 1000, w < 1000000
    	cin >> n >> w;

    	dp[0] = 1;                     // 0 wieght is always possible 
    	for(int i=0; i<n; i++) {
    	    cin >> x;
    	    dp |= (dp << x);       
    	}
	cout << (dp[w] ? "YES" : "NO");
}



// .......................................max value knapsacks ................................................

// O(N * W)
// top-down

int n, capc;
int dp[102][100005];

int go(int i, int capc, int val[], int wt[]) {
      if(i == n || capc < 0) {
            return 0;
      }
      int &ans = dp[i][capc];
      if(ans != -1) {
            return ans;
      }
      // we can always skip the current 
      ans = go(i+1, capc, val, wt);
      if(capc >= wt[i]) {
            // we may only include, if capacity allows 
            ans = max(ans, val[i] + go(i+1, capc - wt[i], val, wt));
      }

      return ans;
}





// O(N * W)
// space optimized
const int mxW = 1e6; 
int dp[mxW];            // dp[w] - max value possible for wieght w

int go(int val[], int wt[], int n, int w) {
    for(int i=0; i<n; i++) 
        for(int j=w; j>=wt[i]; j--) 
            dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);

    return dp[w];
}




// O(N * (N * maxVal))
// knapsack with larger weights 

const int mxN = 100;                 
const int mxW = 1000000005;
const int mxV = 1000;          
// dp[i][j] = minmum weights for including i objects for making up value = j  
int dp[mxN+5][mxN*mxV + 5];                 

void solve() {
    int n, capc;
    cin >> n >> capc;
    int val[n];
    int wt[n];

    // total_val is max possible value of the knapsack when capacity is enough to hold all elements 
    int total_val = 0, ans = 0;

    for(int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
        total_val += val[i];               
    }

    dp[0][0] = 0;
    for (int i = 1; i <= total_val; i++) 
		dp[0][i] = 1e18;

    for(int i=0; i<n; i++) {
        for(int j=0; j<= total_val; j++) {                     
            // i = number of objects included
            // j = total val of knapsack 
            if(j >= val[i]) {   
                // we have two choices
                // skip or include this value
                dp[i + 1][j] = min(dp[i][j], dp[i][j - val[i]] + wt[i]);
            } else { 
                // we cannot include the ith object up untill now since its value > curr val j
                dp[i + 1][j] = dp[i][j];
            }

            // since dp[i][j] <= capacity of our knapsack, means 
            // this value (j) might maximize our ans
            if(dp[i+1][j] <= capc) {
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;
}