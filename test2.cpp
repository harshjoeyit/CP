#include <bits/stdc++.h>
using namespace std;
vector<int> countBits(int n) {
      if (n == 0) {
            return {0};
      }
      vector<int> dp(n + 1);
      
      dp[0] = 0, dp[1] = 1;         // 0 has 0 '1' bits,  1 has 1 '1' bits 
      int cnt = 0;                  // cnt stores length(count of number to next power of 2) to the next power of 2
      int power = 2;                // current power of 2

      for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - power] + 1;          // according to pattern we found + 1 bit
            ++cnt;                              // increase count
            
            if (cnt == power) {                 // time to go to next power of 2, count becomes 0 again
                  cnt = 0;
                  power = power << 1;
            }
      }
      
      return dp;
}