
/*
Find difference of the kth smallest diffrence pair 
*/

#include<bits/stdc++.h>
using namespace std;

// using counting sort method 
int smallestDistancePair(vector<int>& nums, int k) {
      int n = nums.size(), N = 1000000;
      // cnt[diff] = number of pairs with differnce = diff
      vector<int> cnt(N, 0);
      
      for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                  int diff = abs(nums[i] - nums[j]);
                  cnt[diff]++;
            }
      }
      
      for (int i = 0; i < N; i++) {
            if (cnt[i] >= k) {
                  // kth smallest diff falls in this category
                  return i;
            }
            k -= cnt[i];
      }
      return 0;
}

// using the binary search method 
// we use binary search over difference diff 

int smallestDistancePair(vector<int> &nums, int k) {
      int n = nums.size();

      sort(nums.begin(), nums.end());
      
      int low = 0, high = 1000000;
      while (low < high) {
            int diff = (low + high) / 2;
            // find pairs that have difference less than or equal to diff
            int cnt = 0, j = 0;
            for (int i = 0; i < n; i++) {
                  while(j < n && (nums[j] - nums[i] <= diff)) {
                        j += 1;
                  }
                  cnt += j - i - 1;
            }

            if(cnt < k) {
                  low = diff + 1;
            } else {
                  high = diff;
            }
      }
      return low;
}

int main() {
}