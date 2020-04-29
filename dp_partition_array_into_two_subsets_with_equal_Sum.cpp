#include<bits/stdc++.h>
using namespace std;

#define int long long 
int dp[100][100005];

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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        cout << ((solve() == 1)? "YES": "NO") << "\n";
}