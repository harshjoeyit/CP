#include<bits/stdc++.h>
using namespace std;


int maxSumDivThree(vector<int>& a) {
      int n = a.size();
      int dp[3][n+1];
      
      memset(dp, 0, sizeof(dp));
      dp[1][0] = dp[2][0] = INT_MIN;
      
      for(int i=1; i<=n; i++) {
            if(a[i-1] % 3 == 0) {
                  dp[0][i] = max(dp[0][i-1], dp[0][i-1] + a[i-1]);
	            dp[1][i] = max(dp[1][i-1], dp[1][i-1] + a[i-1]);
	            dp[2][i] = max(dp[2][i-1], dp[2][i-1] + a[i-1]);
          
          } else if(a[i-1] % 3 == 1) {
                  dp[0][i] = max(dp[0][i-1], dp[2][i-1] + a[i-1]);
                  dp[1][i] = max(dp[1][i-1], dp[0][i-1] + a[i-1]);
                  dp[2][i] = max(dp[2][i-1], dp[1][i-1] + a[i-1]);
          
          } else {
                  dp[0][i] = max(dp[0][i-1], dp[1][i-1] + a[i-1]);
                  dp[1][i] = max(dp[1][i-1], dp[2][i-1] + a[i-1]);
                  dp[2][i] = max(dp[2][i-1], dp[0][i-1] + a[i-1]);
          }
      }
      
      return dp[0][n];
}

int main() {
      int n, k;
      cin >> n >> k;
      vector<int> a(n);
      for(auto &val: a) {
            cin >> val;
      }
      // cout << maxScore(a, k);
}