#include <bits/stdc++.h>
using namespace std;

// .........................................................................................................
// https://leetcode.com/problems/combination-sum/

// slower apprach
void go(vector<int> &a, int i, int s, vector<int> curr, vector<vector<int>> &ans)
{
      if (i == a.size() || s < 0)
      {
            if (s == 0)
            {
                  ans.push_back(curr);
            }
            return;
      }

      go(a, i + 1, s, curr, ans);
      curr.push_back(a[i]);
      go(a, i, s - a[i], curr, ans);
}
vector<vector<int>> combinationSum(vector<int> &a, int target)
{
      vector<vector<int>> ans;
      vector<int> curr;
      go(a, 0, target, curr, ans);

      return ans;
}

// faster approach
void go(vector<int> &candidates, int target, int pos, vector<int> &item, vector<vector<int>> &result)
{
      if (target == 0)
      {
            result.push_back(item);
            return;
      }
      if (target < 0)
      {
            return;
      }
      // jump to ith position from here
      for (int i = pos; i < candidates.size(); ++i)
      {
            if (target - candidates[i] > 0)
            {
                  item.push_back(candidates[i]);
                  go(candidates, target - candidates[i], i, item, result);
                  item.pop_back();
                  // pop for the since for the every iteration we want item unchanged
            }
      }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
      vector<vector<int>> result;
      vector<int> item;
      go(candidates, target, 0, item, result);

      return result;
}

// .........................................................................................
// https://leetcode.com/problems/combinations/

// my optimised approach
void go(vector<vector<int>> &ans, vector<int> curr, int i, int n, int k)
{
      // a subset of size k found
      if (curr.size() == k)
      {
            ans.push_back(curr);
            return;
      }
      // limit exceeded
      if (i == n + 1)
      {
            return;
      }
      // even if we take all elements from here onwards
      // then also we cannot form a subset of size k
      if (curr.size() + n - i + 1 < k || curr.size() > k)
      {
            return;
      }

      // skip current
      go(ans, curr, i + 1, n, k);

      // include current
      curr.push_back(i);
      go(ans, curr, i + 1, n, k);
}

vector<vector<int>> combine(int n, int k)
{
      vector<vector<int>> ans;
      vector<int> curr;
      go(ans, curr, 1, n, k);
      return ans;
}

// There is an iterative solution for this too

// ..................................................................................
// https://leetcode.com/problems/combination-sum-iii/

// my implementation
void go(int i, int k, int target, vector<int> curr, vector<vector<int>> &ans)
{
      if (target == 0)
      {
            if (curr.size() == k)
            {
                  ans.push_back(curr);
            }
            return;
      }
      if (i > 9 || target < 0 || curr.size() > k)
      {
            return;
      }
      // skip this i
      go(i + 1, k, target, curr, ans);
      // include
      curr.push_back(i);
      go(i + 1, k, target - i, curr, ans);
}

vector<vector<int>> combinationSum3(int k, int target)
{
      vector<vector<int>> ans;
      vector<int> curr;
      go(1, k, target, curr, ans);
      return ans;
}

// better implementation
void go(int i, int k, int target, vector<int> curr, vector<vector<int>> &ans)
{
      if (target == 0)
      {
            if (curr.size() == k)
            {
                  ans.push_back(curr);
            }
            return;
      }
      if (curr.size() > k || target < 0)
      {
            return;
      }
      for (int j = i; j <= 9; j++)
      {
            curr.push_back(j);
            if (j <= target)
            {
                  go(j + 1, k, target - j, curr, ans);
            }
            curr.pop_back();
      }
}


// ............................................................................................