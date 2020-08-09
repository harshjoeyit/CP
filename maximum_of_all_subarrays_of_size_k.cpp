
/*
maximum of all subarray of size k
*/

#include <bits/stdc++.h>
using namespace std;

// using brute force O(n*k) time

// using balanced binary search tree or map O(nlog(n))
vector<int> maxOfArrayOfSizeK(vector<int> &nums, int k)
{
      if (nums.size() == 0)
      {
            return {};
      }

      int n = nums.size();
      vector<int> ans;

      map<int, int, greater<int>> mp;
      for (int i = 0; i < k - 1; i++)
      {
            mp[nums[i]] += 1;
      }

      for (int i = k - 1; i < n; i++)
      {
            mp[nums[i]] += 1;
            int mx = mp.begin()->first;
            ans.push_back(mx);
            int delKey = nums[i - k + 1];
            mp[delKey] -= 1;
            if (mp[delKey] == 0)
            {
                  mp.erase(delKey);
            }
      }

      return ans;
}

// using sliding window and deque, O(n) time
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
      deque<int> dq;
      vector<int> ans;
      // suppose a[i] <= a[j] where j > i then for every window 
      // in which i and j are present the max will be a[j], so it is better to remove a[i] 
      for (int i = 0; i < nums.size(); i++) {
            // removing the elements that are not the part of the window 
            if (!dq.empty() && dq.front() == i - k) {
                  dq.pop_front();
            }
            // remove all lesser elements from queue
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                  dq.pop_back();
            }
            // adding new element
            dq.push_back(i);
            // record ans
            if (i >= k - 1) {
                  ans.push_back(nums[dq.front()]);
            }
      }
      return ans;
}
int main()
{
}