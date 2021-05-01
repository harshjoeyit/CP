
/*
https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<bits/stdc++.h>
using namespace std;

// O(n*log(n)), O(1) Space
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

// Method 1
// O(n) time & space, 
int findLongestConseqSubseq(int a[], int n) {
    unordered_set<int> st;
    for(int i=0; i<n; i++) {
        st.insert(a[i]);
    }

    int ans = 0;
    while(!st.empty()) {
        int curr;
        for(auto val: st) {
            if(!st.count(val-1)) {
                curr = val;
                break;
            }
        }
        // curr is the first element of a sequence, count & erase the seq
        int cnt = 0;
        while(st.count(curr)) {
            st.erase(curr);
            cnt++;
            curr++;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

// Method 2
// O(n) time & space 
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