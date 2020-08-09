#include <bits/stdc++.h>
using namespace std;

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

// min su, subarray kadanes approach
int min_sum_subarray_kadane(vector<int> a)
{
    int sum = 0;
    int ans = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        if (sum + *it < 0)
            sum = sum + *it;
        else
            sum = 0;
        if (sum < ans)
            ans = sum;
    }
    return ans;
}


int max_cross_sum_subarray(vector<int> a, int l, int mid, int h)
{
    if (l == h)
        return a[l];

    int sum = 0, l_sum = INT_MIN, r_sum = INT_MIN;

    for (int i = mid; i >= l; i--)
    {
        sum += a[i];
        l_sum = max(sum, l_sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= h; i++)
    {
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

int main()
{
    vector<int> a = {1, 1, -3, 3, -1, 2};
    cout << "max sum : " << max_sum_subarray_kadane(a) << endl;
    cout << "max sum : " << max_sum_subarray_div_con(a, 0, a.size() - 1) << endl;
}
