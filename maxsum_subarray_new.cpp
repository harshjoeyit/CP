#include<bits/stdc++.h>
using namespace std;

// Al the algorithm also test for negetive numbers too, no need to worry

// Kadane's
void kadane(int a[], int n) {
    int ans = a[0], sum = 0;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    cout << ans << endl;
}

// Kadane's also subarray indices  
void kadane_indices(int a[], int n) {
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
    cout << ans << endl;
    cout << ans_l << " " << ans_r << endl;
}


// Not kadane's
void max_subarray_sum(int a[], int n) {
    int ans = a[0], sum = 0, min_sum = 0;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }

    cout << ans << endl;
}

// Not kadane's finding indices too 
void max_sum_subarray(int a[], int n) {
    int ans = a[0], ans_l = 0, ans_r = 0;
    int sum = 0, min_sum = 0, min_pos = -1;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        int cur = sum - min_sum;
        if (cur > ans) {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }
        if (sum < min_sum) {
            min_sum = sum;
            min_pos = r;
        }
    }
    
    cout << ans << endl;
    cout << ans_l << " " << ans_r << endl;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    max_subarray_sum(a, n);
    max_sum_subarray(a, n);
    kadane(a, n);
    kadane_indices(a, n);
}