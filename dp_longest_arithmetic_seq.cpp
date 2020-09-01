
/*
Longest Arithmetic Sequence 
2 <= A.length <= 1000
0 <= A[i] <= 500

An arithmetic sequence is sequence with same difference between the consecutive terms (similar to AP)
*/

#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 
 
/*
1. since 0 <= A[i] <= 500, so -500 <= common difference <= 500
2. starting from n-1, for all the positions we check what are the possible common difference possible 
3. To store negetive difference we store them at index defined by 
4. (1005 + diff) % 1005 
5. dp[i][diff] - stores max length sequence possible from i with difference = diff
*/

int longestArithSeqLength(vector<int>& a) {
      if(a.size() == 2) {
            return 2;
      }
      
      int n = a.size();
      vector<vector<int>> dp(n, vector<int>(1005, 1));
      int ans = 2;
      
      for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                  // find the diff b/w a[i] and a[j]
                  int diff = (1005 + a[i] - a[j]) % 1005;
                  // update max length from (i, diff) by using the length from (j, diff) 
                  dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
                  // update ans
                  ans = max(ans, dp[i][diff]);
            }
      }
      
      return ans;
}
 