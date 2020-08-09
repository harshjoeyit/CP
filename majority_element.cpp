
/* Read all the approaches on leetcode 
https://leetcode.com/problems/majority-element/solution/
*/

#include<bits/stdc++.h>
using namespace std;

// divide and conquer 
int majority(vector<int> &a, int l, int r) {
      if(l == r) {
            return a[l];
      }
      
      int mid = (l+r)/2;
      int left = majority(a, l, mid);
      int right = majority(a, mid+1, r);
      
      if(left == right) {
            return left;
      }

      int cntLeft = count(a.begin()+l, a.begin()+r+1, left);
      int cntRight = count(a.begin()+l, a.begin()+r+1, right);

      if(cntLeft > cntRight) {
            return left;
      }
      return right;
}

int majorityElement(vector<int>& nums, int noUse) {
      return majority(nums, 0, nums.size()-1);
}

int majorityElement(vector<int>&nums) {
      int curr, cnt = 0;
      for(auto &num: nums) {
            if(cnt == 0) {
                  curr = num;
                  cnt = 1;
            } else if(num != curr) {
                  cnt -= 1; 
            } else {
                  cnt += 1;
            }
      }
      return curr;
}

/*
Another implementation

int majorityElement(vector<int>&nums) {
      int curr = nums[0], cnt = 1;
      for(int i=1; i<nums.size(); i++) {
            if(num[i] == curr) {
                  cnt += 1;
            } else {
                  cnt -= 1;
                  if(cnt == 0) {
                        cnt = 1;
                        curr = nums[i];
                  }
            }
      }
      return curr;
}
*/


int main() {
      vector<int> a = {1,2,3,1,1,1,4};
      cout << majorityElement(a);
}