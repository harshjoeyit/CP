
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int go(vector<int>& nums,int st, int en) {
	if(st<0||en>=nums.size()||st>en)
		return 0;

    	int &ans = dp[st][en];
	if(ans != -1) {
		return ans;
	}
	
    	ans = INT_MIN;
    	int lval = st-1 < 0 ? 1 : nums[st-1];
    	int rval = en+1 >= nums.size() ? 1 : nums[en+1];

	for(int i=st;i<=en;++i) {
		ans = max(ans, nums[i] * lval * rval + go(nums,st,i-1) + go(nums,i+1,en));
	}
	return ans;
}

int maxCoins(vector<int>& nums) {
	dp.resize(nums.size(),vector<int>(nums.size(),-1));
	return go(nums,0,nums.size()-1);
}