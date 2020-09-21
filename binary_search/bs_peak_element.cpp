
/*
Peak Element - element strictly greater than its neighbours 
given an array - a[-1] = a[n] = -INF, find any peak element in log(n)

Logic - find mid - compare a[mid-1], a[mid] - choose the next half to go in

case 1: a[mid-1] > a[mid] - then peak is in [l, mid-1] - because
        if a[l] < a[mid-1] then there has to be a peak even if array is strictly increasing in [l, mid-1]
        if a[l] > a[mid-1] then peak is at l even if array is strictly decreasing in [l, mid-1]
        we dont need to check these cases 

case 2: a[mid-1] < a[mid] - there may not be a peak in [l, mid-1], but
        peak is at mid even if array is strinctly dereasing in [mid, h]
        peaxk is at h even if array is strictly increasing in m[mid, h]

// watch erichto's video
*/




#include<bits/stdc++.h>
using namespace std;
#define int long long int

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(l < h) {
                int mid = (l+h+1)/2;
                if(nums[mid-1] > nums[mid]) {
                        h = mid-1;
                } else {
                        l = mid;
                }
        }
        return l;
}

// OR another implementation 
int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(l < h) {
                int mid = (l+h)/2;
                if(nums[mid] > nums[mid+1]) {
                        h = mid;
                } else {
                        l = mid + 1;
                }
        }
        return l;
}

void solve() {
        int n;
        cin >> n;
        vector<int> nums;
        for(int i=0; i<n; i++) {
                cin >> nums[i];
        }
        cout << findPeakElement(nums);
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
}