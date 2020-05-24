
/*
https://leetcode.com/problems/continuous-subarray-sum/

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a 
continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      //   size >= 2 and all elements must be 0 for k = 0
	  if(k == 0) {
            for(int i=0; i<nums.size()-1; i++) {
                if(nums[i] == 0 && nums[i+1] == 0) {
                    return 1;
                }
            }
            return false;
        }
        
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        unordered_map<int, int> mp;
        
        mp[0] = 0;
        for(int i=1; i<=n; i++) {
		//   adding num % k, since the rest it is only contribution in sum
            prefix[i] += prefix[i-1] + nums[i-1] % k;	
		
		//  Note: Logic
		// if the remainder of two prefix sums is same 
		// then it means that the numbers in range sum up to be divisible by k

		// if we have foud the same rem before - chaeck the array length
            if(mp.count(prefix[i] % k) == 1) {
                if(i - mp[prefix[i] % k] >= 2) {
                    return 1;
                }
		// insert the key rem with index as value
            } else {
                mp[prefix[i] % k] = i;   
            }
        }
        
        return 0;
    }
};