#include <bits/stdc++.h>
using namespace std;

/*
Application 
- maxsum rectangle in a matrix 
- an array of 0 and 1s find the subarray with max(count(0) - count(1)) - approach convert 0 -> 1 and 1 -> -1 find maxsum subarray 
- circular maxsum array 
- maxsum with one element skip
- k concatinated arrays
*/

// find maxsum
int maxSumSub(vector<int> a, int n) {
    int ans = a[0], sum = 0;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
}

// find left and right
int maxSumSubarray(vector<int> a, int n) {
    int ans = a[0], ans_l = 0, ans_r = 0;
    int sum = 0, minus_pos = -1;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }
        if (sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    }
}

// min sum subarray kadanes approach
int min_sum_subarray_kadane(vector<int> a) {
    int sum = 0;
    int ans = 0;
    for (auto it = a.begin(); it != a.end(); it++) {
        if (sum + *it < 0)
            sum = sum + *it;
        else
            sum = 0;
        if (sum < ans)
            ans = sum;
    }
    return ans;
}


int max_cross_sum_subarray(vector<int> a, int l, int mid, int h) {
    if (l == h)
        return a[l];

    int sum = 0, l_sum = INT_MIN, r_sum = INT_MIN;

    for (int i = mid; i >= l; i--) {
        sum += a[i];
        l_sum = max(sum, l_sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= h; i++) {
        sum += a[i];
        r_sum = max(sum, r_sum);
    }

    return l_sum + r_sum;
}

// divide and conquor approach
int max_sum_subarray_div_con(vector<int> a, int l, int h)
{
    if (l == h)
        return a[l];

    int mid = (l + h) / 2;
    int left_sum = max_sum_subarray_div_con(a, l, mid);
    int right_sum = max_sum_subarray_div_con(a, mid + 1, h);
    int cross_sum = max_cross_sum_subarray(a, l, mid, h);

    int ans = max(left_sum, right_sum);
    ans = max(ans, cross_sum);

    return ans;
}


// masum circular 
int maxSubarraySumCircular(vector<int>& v) {
        int max_so_far = v[0];
        int max_end_here = v[0];
        int totalsum = v[0];
        int min_so_far = v[0];
        int min_end_here = v[0];

        for(int i=1; i<v.size(); i++){
                totalsum += v[i];
                max_end_here = max(max_end_here + v[i], v[i]);
                max_so_far = max(max_end_here, max_so_far);
                min_end_here = min(min_end_here + v[i], v[i]);
                min_so_far = min(min_so_far, min_end_here);
        }
        if(max_so_far < 0){ //means all element are negative
                return max_so_far;
        }
        return max(max_so_far, (totalsum - min_so_far));
}


// K concatenated array - maxSum
// array has been concatinated k times 
int kConcatenationMaxSum(vector<int>& arr, int k) {
      long long arraySum = accumulate(arr.begin(), arr.end(), 0LL);
      const int mod = 1e9 + 7;
      int n = arr.size();
      int maxSubarraySum = 0, s = 0;
      // finding maxSum for 2 concatinated arrays
      // considereing it to be a complete array of size 2*n
      for (int i = 0; i < 2 * n; i++) {
            s += arr[i % n];
            maxSubarraySum = max(maxSubarraySum, s);
            s = max(0, s);
      }

      return (maxSubarraySum + (arraySum > 0 ? arraySum * (k - 2) : 0)) % mod;
}


// Maximum Subarray Sum with One Deletion/Skip
// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
int maximumSum(vector<int>& a) {
    if(a.size() == 1) {
        return a[0];
    }
    int n = a.size();
    
    int ans = kadane(a);
    if(ans < 0) {
        return ans;
    }
    
    // find the left and the right sum 
    // just as we do in kadane 
    vector<int> leftSum(n, 0);
    vector<int> rightSum(n, 0);
    
    int s = 0;
    for(int i=0; i<n; i++) {
        s += a[i];
        s = max(s, 0);  // cant be neg
        leftSum[i] = s;
    }
    
    s = 0;
    for(int i=n-1; i>=0; i--) {
        s += a[i];
        s = max(s, 0);  // cant be neg
        rightSum[i] = s;
    }
    // rightSum[1] -> skip a[0]
    // leftSum[n-1] -> skip a[n-1]
    ans = max({ans, rightSum[1], leftSum[n-2]});
               
    for(int i=1; i<n-1; i++) {
        // leftSum[i-1] + rightSum[i+1]  -->  skip a[i]
        // get maxsum from left and right  
        ans = max(ans, leftSum[i-1] + rightSum[i+1]);
    }
               
    return ans;
}

int main()
{
    vector<int> a = {1, 1, -3, 3, -1, 2};
    cout << "max sum : " << max_sum_subarray_kadane(a) << endl;
    cout << "max sum : " << max_sum_subarray_div_con(a, 0, a.size() - 1) << endl;
}
