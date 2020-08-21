
/*
https://www.geeksforgeeks.org/painting-fence-algorithm/

Given a fence with n posts and k colors, find out the number 
of ways of painting the fence such that at most 2 adjacent 
posts have the same color

painting a 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;
int dp[100007][101];

int solve(int n, int k) {
      if (n == 0)
            return 0;
      // k colors - so k ways to paint 1 post 
      if (n == 1)
            return k;
      // k colors - (paint both same in k ways + paint both different in k * (k-1) ways)
      if (n == 2)
            return dp[n][k] = k + k * (k - 1);

      if (dp[n][k] != -1)
            return dp[n][k];

      // consider n-2 painted, then we can paint the remaining 2 in k-1 ways
      // consider n-1 painted then we can paint the remaining 1 in k-1 ways 
      // total = (solve(n-2) + solve(n-1)) * (k-1)
      int ans = (solve(n - 2, k) % mod + solve(n - 1, k) % mod) % mod;
      ans *= (k - 1) % mod;
      ans %= mod;

      return dp[n][k] = ans;
}

signed main()
{
      int t;
      cin >> t;
      memset(dp, -1, sizeof(dp));
      while (t--)
      {
            int n, k;
            cin >> n >> k;
            cout << solve(n, k) << endl;
      }
}