
/*
https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
      if(nums.size() == 0) {
            return 0;
      }
      sort(nums.begin(), nums.end());
      int maxL = 1;
      int curr = 1;
      for(int i=1; i<nums.size(); i++) {
            if(a[i] = a[i-1] + 1) {
                  curr += 1;
            } else if(a[i] == a[i-1]) {
                  continue
            } else {
                  ans = max(ans, curr);
                  curr = 1;
            }
      }
      ans = max(ans, curr);
      return ans;
}

// O(n)
int longestConsecutive(vector<int>& nums) {
      if(nums.size() == 0) {
            return 0;
      }
      unordered_set<int> uniq;
	  // store the unique values in the set 
      for(auto &num: nums) {
            uniq.insert(num);
      }
      int ans = 1;
      while(uniq.size() > 0) {
            int save, val;
			// we get some random value from the set 
            save = val = *uniq.begin();
            int curr = 1;
			// we check if this values is part of some continuous sequence 
			// by checking one value less than previous each time
            while(uniq.count(++val)) {
                  curr += 1;
                  uniq.erase(val);
				  // we erase since this value will not occur in any other sequence
            }
            val = save;
			// we also check if this val might me middle of some sequence with extends further 
			// this value(and these values are present int the set)
            while(uniq.count(--val)) {
                  curr += 1;
                  uniq.erase(val);
            }
			// erase due to reason explained above
            uniq.erase(save);
            ans = max(ans, curr);
      }
      return ans;
}

int main() {
      vector<int> v = {};
}