
/*
https://leetcode.com/problems/jump-game-ii/

*/

#include <bits/stdc++.h>
using namespace std;

// count the min jumps
int jump(vector<int> &nums)
{
      int pos = 0;
      int des = 0;
      int jump = 0;

      for (int i = 0; i < nums.size() - 1; i++)
      {
            des = max(des, i + nums[i]);
            if (pos == i)
            {
                  pos = des;
                  jump++;
            }
      }
      return jump;
}

// check if last index can be visited
bool canJump(vector<int> &nums)
{
      // corner cases
      if (nums.size() == 1)
      {
            return true;
      }
      if (nums[0] == 0)
      {
            return false;
      }

      int n = nums.size();
      // maxFar stores the farthest index that we can to
      int maxFar = 0;

      for (int i = 0; i < n; i++)
      {
            // if at any time we can jump to last or further
            if (maxFar >= n - 1)
            {
                  return true;
            }
            if (nums[i] == 0)
            {
                  // check if we can jump farther than this 0
                  if (i < maxFar)
                  {
                        continue;
                  }
                  // if not
                  return false;
            }
            else
            {
                  // update
                  maxFar = max(maxFar, i + nums[i]);
            }
      }
      return true;
}

// can reach zero value index, using BFS
bool canReach(vector<int> &arr, int start)
{
      int n = arr.size();
      queue<int> que;
      que.push(start);
      vector<bool> vis(arr.size(), 0);
      vis[start] = 1;

      while (!que.empty())
      {
            int ind = que.front();
            que.pop();
            if (arr[ind] == 0)
            {
                  return true;
            }

            int x = (ind - arr[ind]);
            if (x >= 0 && x < n && !vis[x])
            {
                  vis[x] = 1;
                  que.push(ind - arr[ind]);
            }

            int y = (ind + arr[ind]);
            if (y >= 0 && y < n && !vis[y])
            {
                  vis[y] = 1;
                  que.push(ind + arr[ind]);
            }
      }
      return false;
}

// other approches
unordered_set<int> vis;
bool canReach(vector<int> &arr, int st)
{
      if (st >= 0 && st < arr.size() && vis.insert(st).second)
      {
            return arr[st] == 0 ||
                   canReach(arr, st + arr[st]) || canReach(arr, st - arr[st]);
      }
      return false;
}


//  we can jump if we are on i to i-1, i+1, and j, such that a[i] == a[j]
// find the min steps to reach n-1 
int minJumps(vector<int> &arr)
{
      if (arr.size() == 1)
      {
            return 0;
      }

      int n = arr.size();
      map<int, vector<int>> mp;
      for (int i = 1; i < n; i++)
      {
            mp[arr[i]].push_back(i);
      }

      queue<int> q;
      vector<bool> vis(n, false);
      int steps = 0;
      q.push(0);
      vis[0] = true;

      while (!q.empty())
      {
            int sz = q.size();
            //             standard level order traversal
            while (sz--)
            {
                  int i = q.front();
                  q.pop();
                  if (i == n - 1)
                  {
                        return steps;
                  }

                  int x = i - 1;
                  int y = i + 1;

                  if (0 <= x && x <= n - 1 && arr[x] != arr[i] && !vis[x])
                  {
                        vis[x] = true;
                        q.push(x);
                  }
                  if (0 <= y && y <= n - 1 && arr[y] != arr[i] & !vis[y])
                  {
                        vis[y] = true;
                        q.push(y);
                  }
                  for (auto idx : mp[arr[i]])
                  {
                        if (!vis[idx])
                        {
                              vis[idx] = true;
                              q.push(idx);
                        }
                  }

                  // this is the magic line - Otherwise TLE
                  // once we have used the value a[i], we have all the indices with this value in the queue, so we just loop it over once.
                  mp[arr[i]].clear();
            }
            //           increment steps after one level travelled
            ++steps;
      }

      return n - 1;
}

int main()
{
      int n;
      cin >> n;
      vector<int> v(n);
      for (auto &x : v)
      {
            cin >> x;
      }
      cout << jump(v) << endl;
}