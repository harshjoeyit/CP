
#include <bits/stdc++.h>
using namespace std;

// Brute Forces - Recurision

// Otimized - Dp approach
// Space -  O(n)
vector<int> dp;
int go(int i, vector<int> &a)
{
      int n = (int)a.size();
      if (i >= n)
      {
            return 0;
      }
      int &ans = dp[i];
      if (ans != -1)
      {
            return ans;
      }

      return ans = max(go(i + 1, a), a[i] + go(i + 2, a));
}

// Using two variables
// Space O(1) appraoch
int goNice(vector<int> &a)
{
      int ex, inc, n = (int)a.size(), exNew;
      ex = 0, inc = a[0];

      for (int i = 1; i < n; i++)
      {
            exNew = (inc > ex) ? inc : ex;
            inc = ex + a[i];
            ex = exNew;
      }

      return (inc > ex) ? inc : ex;
}


// Similar problems on k-ary trees
// Find greatest sum, if you cannot select nodes with a edge between them
int func(int node, int select)
{
      if (dp[node][select] != -1)
            return dp[node][select];

      int ans = 0, i;

      // we can select this node     
      if (select)
            ans = node;
      
      //edges[i] stores children of node i
      for (i = 0; i < edges[node].size(); i++)
      {
            if (select)
                  // cannot select children, because this selected 
                  ans = ans + func(edges[node][i], 1 - select);
            else
                  // can either select or skip children
                  ans = ans + max(func(edges[node][i], 0), func(edges[node][i], 1));
      }

      dp[node][select] = ans;
      return ans;
}

int main()
{
      int n;
      cin >> n;
      vector<int> a(n, 0);
      dp.assign(n, -1);
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
      }

      // cout << go(0, a);

      // cout << goNice(a);

      // answer = max(func(root,0),func(root,1));
}