#include<bits/stdc++.h>
using namespace std;

#define int long long 
int dp[100][100005];

// top down
bool subset_with_given_sum(int a[], int n, int sum) {
    if(sum == 0) {
        return 1;
    }
    if(sum < 0 || n < 0) {
        return 0;
    }

    if(dp[n][sum] != -1)
        return dp[n][sum];

    return  dp[n][sum] = (subset_with_given_sum(a, n-1, sum-a[n]) | subset_with_given_sum(a, n-1, sum));
}

bool solve() {  
    int n, s=0;
    cin >> n;
    int a[n];
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++) {
        cin >> a[i];
        s += a[i];
    }

    if(s%2 == 1) {
        return 0;
    } 
    // cout << s/2 << endl;
    return subset_with_given_sum(a, n-1, s/2);
}

// using dp bottom up
bool canPartitionKnap(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum%2 != 0) return false;
    
    vector<bool> dp(sum/2 + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = sum/2; j > 0; --j) {
            if (nums[i] <= j) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
    }
    return dp.back();
}

// using recursion
bool canPartitionRecur(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum%2 != 0) return false;
    sort(nums.rbegin(), nums.rend());
    return dfs(nums, sum/2, 0);
}
bool dfs(vector<int>& nums, int target, int i) {
    if (i >= nums.size() || nums[i] > target) return false;
    if (nums[i] == target) return true;
    return dfs(nums, target-nums[i], i + 1) || dfs(nums, target, i + 1);
}

// using bitsets 
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum%2 != 0) return false;
    bitset<10001> bits(1);
    for (auto num : nums) bits |= bits << num;
    return bits[sum/2];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        cout << ((solve() == 1)? "YES": "NO") << "\n";
}