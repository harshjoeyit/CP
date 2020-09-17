#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
      if(nums.size() < 4) {
            return {};
      }
      vector<vector<int>> ans;
      int n = nums.size();
      sort(nums.begin(), nums.end());

      for (int i = 0; i < n-3; i++) {
            for (int j = i + 1; j < n-2; j++) {
                  int st = j + 1, en = n - 1;
                  while(st < en) {
                        int s = nums[i] + nums[j] + nums[st] + nums[en];
                        if(s < target) {
                              st += 1;
                        } else if(s > target) {
                              en -= 1;
                        } else {
                              ans.push_back({nums[i], nums[j], nums[st], nums[en]});
                              st += 1, en -= 1;
                              while (st < en && nums[st-1] == nums[st]) {
                                    st += 1;
                              }
                              while (st < en && nums[en] == nums[en+1]) {
                                    en -= 1;
                              }
                        }
                  }
                  while(j < n-1 && nums[j] == nums[j+1]) {
                  j += 1;
            }
            }
            while(i < n-1 && nums[i] == nums[i+1]) {
                  i += 1;
            }
      }
      return ans;
}

int main() {
      int t;
      int n;
	cin >> n >> t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
      auto ans = fourSum(a, t);
      for(auto val: ans) {
            cout << val[0] << " " << val[1] << " " << val[2] << " " << val[3] << endl;
      }
}