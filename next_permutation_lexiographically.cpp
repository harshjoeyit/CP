/*
    https://leetcode.com/problems/next-permutation/submissions/
*/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n-1;
    while(i >= 1 && nums[i-1] >= nums[i])    i--;
    if(i == 0) {
        sort(nums.begin(), nums.end());
        return;
    } 
    // find the smallest number greater than nums[i-1], to its right
    int j=i;
    while(j < n && nums[j] > nums[i-1])     j++;
    swap(nums[i-1], nums[j-1]);
    sort(nums.begin()+i, nums.end());
}

int main() {
}