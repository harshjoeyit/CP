#include<bits/stdc++.h>
using namespace std;

// count subarrays with the product less than a given number
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int p = 1, st = -1, n = nums.size(), ans = 0;
    
	for(int en=0; en<n; en++) {
        p = p * nums[en];
        while(st < en && p >= k) {
            p /= nums[++st];
        }
        ans += en - st;
    }
    return ans;
}

int main() {
    vector<int> v = {1,9,2,8,6,4,3};
    cout << numSubarrayProductLessThanK(v, 150) << endl;
}

// better problem 

// subarray with product = k

// (subarray with product = k) => (subarray with product < k+1) - (subarray with product < k)