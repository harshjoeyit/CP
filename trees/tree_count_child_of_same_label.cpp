
/*
Number of Nodes in the Sub-Tree With the Same Label
https://leetcode.com/contest/weekly-contest-198/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/


learned 

- do not use unordered map or map as return type of DFS function 
- try and use the method below for child processing 
- array further decrease the runtime when used in place of cnt vector 
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

void dfs(int u, int par, vector<int> &ans, vector<int> &cnt, string &labels)
{
      for (auto v : g[u])
      {
            if (v != par)
            {
                  vector<int> childCnt(26, 0);
                  dfs(v, u, ans, childCnt, labels);
                  for (int i = 0; i < 26; i++)
                  {
                        cnt[i] += childCnt[i];
                  }
            }
      }

      int c = labels[u] - 'a';
      cnt[c] += 1;
      ans[u] = cnt[c];
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
      if (n == 0 || edges.empty())
      {
            return {};
      }

      g.assign(n, vector<int>());
      for (auto e : edges)
      {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
      }

      vector<int> cnt(26, 0);

      vector<int> ans(n);
      dfs(0, -1, ans, cnt, labels);

      return ans;
}

int main()
{
}