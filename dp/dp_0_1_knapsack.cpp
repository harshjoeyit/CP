#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Check if knapsack can be filled completely (subset sum problem)

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
Check if knapsack can be filled completely (Using bitset)

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



// Find Max value of the knapsack


// O(N * W) time and space 
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

// O(N*W), time and space
// bottom up

void fill_knapsack(){
    int dp[n+1][capc+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=capc; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=; j<=capc; j++) {
            if(j < wt[i-1])          // array index 0 for item 1 // item cannot contribute in knapsack
                    dp[i][j] = dp[i-1][j];      // best can do without including the item

            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                
        }
    }

    cout << dp[n][capc] << "\n";
}


// O(N * W) time and space
// space optimized

const int mxW = 1e6; 
int dp[mxW];            
// dp[w] = max value possible for wieght w

int go(int val[], int wt[], int n, int w) {
    for(int i=0; i<n; i++) 
        for(int j=w; j>=wt[i]; j--) 
            dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);

    return dp[w];
}



// O(N * (N * maxVal)) time and space
// knapsack with larger weights 

const int mxN = 100;                 
const int mxW = 1000000005;
const int mxV = 1000;          
int dp[mxN+5][mxN*mxV + 5];                 
// dp[i][j] = minimum weights for including i items for making up value = j  

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
                // we cannot include the ith object, 
				// since its value > curr item's val(j) 
                dp[i + 1][j] = dp[i][j];
            }

            // if dp[i][j] <= capacity of our knapsack, means 
            // this value (j) might maximize our ans
            if(dp[i+1][j] <= capc) {
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;
}