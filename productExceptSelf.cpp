#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
      int n = nums.size();
      vector<int> ans(n);
      int p = 1;
      for(auto x: nums) {
            p *= x;
      }
      for(int i=0; i<n; i++) {
            ans[i] = p/nums[i];
      }
      return ans;
} 

// O(n) space and time coomplexity 
vector<int> productExceptSelf(vector<int> &nums) {
      int n = nums.size();
      vector<int> ans(n), left(n), right(n);
      left[0] = right[n-1] = 1;
      for(int i=1; i<n; i++) {
            left[i] = left[i-1] * nums[i-1];
      }
      for(int i=n-2; i>=0; i--) {
            right[i] = right[i+1] * nums[i+1];
      }
      for(int i=0; i<n; i++) {
            ans[i] = left[i] * right[i];
      }
      
      return ans;
}     

// O(n) time O(1) space complexity 
vector<int> productExceptSelf(vector<int> &nums) {
      int n = nums.size();
      int left = 1, right = 1;
      vector<int> ans(n, 1);
      for(int i=0; i<n; i++) {
            ans[i] *= left;
            left *= nums[i];
      }
      for(int i=n-1; i>=0; i--) {
            ans[i] *= right;
            right *= nums[i];
      }
      return ans;
}

int main() {
      
      productExceptSelf()
}