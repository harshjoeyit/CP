#include <bits/stdc++.h>
using namespace std;

// 1. brute force 
long long go(int i, vector<int> &nums, long long target) {
      if (i == nums.size()) {
            return target == 0;
      }
      return go(i + 1, nums, target - nums[i]) + go(i + 1, nums, target + nums[i]);
}

// 2. DP 
map<pair<int, int>, int> dp;

long long go(int i, vector<int> &nums, long long target) {
      if (i == nums.size()) {
            return target == 0;
      }
      if (dp.count({i, target})) {
            return dp[{i, target}];
      }
      return dp[{i, target}] = (go(i + 1, nums, target - nums[i]) + go(i + 1, nums, target + nums[i]));
}

int findTargetSumWays(vector<int> &nums, int target) {
      int n = nums.size();
      dp.clear();
      return go(0, nums, target);
}


// 3. best Approach 
/*
      Sp-Sn = target
      Sp-Sn + (Sp+Sn) = target + sum(array)
      2.Sp = target+sum(array)
      Sp = (target+sum(array))/2
      check for target+sum(array) to be even
*/
 
int dp[21][1005];

int go(int i, vector<int> &nums, int &s) {
      
      if(i == nums.size()) {
            return s == 0;
      } 
      if(s < 0) {
            return 0;
      }

      int &ans = dp[i][s];
      if(ans != -1) {
            return ans;
      }

      return ans = go(i+1, nums, s-nums[i]) + go(i+1, nums, s);
}

int findTargetSumWays(vector<int> &nums, int target) {
      int n = nums.size();
      int s = 0;
      for(auto &x: nums) {
            s += x;
      }
      s += target;
      if(s % 2 == 1) {
            return 0;
      }
      s = s/2;
      // problems reduced to - count ways to make sum = s (knapsack)
      memset(dp, -1, sizeof(dp));
      return go(0, nums, target);
}

int main() {
      int n, target;
      cin >> n >> target;
      vector<int> v(n);
      for(int i=0; i<n; i++) {
            cin >> v[i];
      }
      cout <<findTargetSumWays(v, target);
}