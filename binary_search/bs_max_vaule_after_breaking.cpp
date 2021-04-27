/*
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
*/

#include<bits/stdc++.h>
using namespace std;

// finds the final size of the array with maximum vaule being = mid
int breakArray(int mid, vector<int> &nums) {
    int sz = 0;
    for(auto val: nums) {
        if(val > mid) {
            sz += ceil(1.0*val/mid);
        }
        else {
            sz += 1;
        }
    }
    return sz;
}

int minimumSize(vector<int>& nums, int mops) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    int ans = high;
    int n = nums.size();

    while(low <= high) {
        int mid = low + (high - low)/2;
        // find the size of the array with max value of the array being mid
        int sz = breakArray(mid, nums);
        if(sz <= mops + n) {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {

}