/*
Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

Ex -1 
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

Ex -2
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> dp;
    
int go(vector<int> &nums1, vector<int> &nums2, int i, int j) {
      if(i == nums1.size() || j == nums2.size()) {
            return 0;
      }
      if(dp[i][j] != -1) {
            return dp[i][j];
      }
      int ans = go(nums1, nums2, i+1, j);                                     // skip the element from first array
      ans = max(ans, go(nums1, nums2, i, j+1));                               // skip the element from second array
      ans = max(ans, (nums1[i] * nums2[j]) + go(nums1, nums2, i+1, j+1));     // include both elements and carry on
      
      return dp[i][j] = ans;
}

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    
      dp.assign(nums1.size(), vector<int>(nums2.size(), -1));
      
      int ans = go(nums1, nums2, 0, 0);
      
      if(ans > 0) {
          return ans;
      }
      
      // if all elements in one vector < 0
      // and all elements in another are > 0
      // then go() returns 0 
      // in that case ans = minpos * maxneg

      int maxneg = INT_MIN;
      int minpos = INT_MAX;
      if(ans == 0) {
            //  we dont know which vec has neg and which has pos so check both
            for(int i=0; i<nums1.size(); i++) {
                  if(nums1[i] < 0)
                        maxneg = max(maxneg, nums1[i]);
                  else 
                        minpos = min(minpos, nums1[i]);
            }
            for(int i=0; i<nums2. size(); i++) {
                  if(nums2[i] < 0) 
                        maxneg = max(maxneg, nums2[i]);
                  else
                        minpos = min(minpos, nums2[i]);
            }
      }
      
      ans = maxneg * minpos;
      return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}