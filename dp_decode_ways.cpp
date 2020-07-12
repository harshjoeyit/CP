
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

find number of ways to decode the message 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

int go(string s, int i, vector<int> &dp)
{
      if (i >= s.size())
            return 1;

      if (s[i] == '0')
            return 0;

      if (dp[i] != -1)
            return dp[i];

      // Handle one character
      int result = go(s, i + 1, dp);

      // Handle two characters
      if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
      {
            result += go(s, i + 2, dp);
      }
      dp[i] = result;
      return result;
}

signed main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while (t--)
            solve();
}