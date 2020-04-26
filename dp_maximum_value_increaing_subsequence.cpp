
/*
https://atcoder.jp/contests/dp/tasks/dp_q

flower heights and their beauties are given 

Taro is pulling out some flowers so that the following condition is met:
The heights of the remaining flowers are monotonically increasing from left to right.

Find the maximum possible sum of the beauties of the remaining flowers.


O(n^2) approach

    dp[i] -  max total value so far if the last taken flower has height i
    
    Inshort - we go to all height less than current height 
            and the find the one with the mas value ad use it
            
            We need max(dp[i]) in range [0, h-1]        - h - current height 

    for(int flower = 0; flower < n; flower++) {
        for(int i = 0; i< h[flower]; i++) { 
            int &curr = dp[h[flower]];
            curr = max(curr, dp[i] + val[flower]); 
        }
    } 

    so we use iterative version of segment tree for max dp[i]
    Complexity - O(nlog(n))
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    
    // making a segemnt tree for finding masx(dp[i]) in some range 
    int base = 1;
    while(base <= n) {
        base *= 2;
    }
    // base is the smallest power of 2 that is not smaller than n

    // tree stores maximum value of dp[i] in a range 
    vector<int> tree(2*base);       


    int h[n];
    int val[n];
    for(int i=0; i<n; i++)
        cin >> h[i];
    for(int i=0; i<n; i++)
        cin >> val[i];
    
    int dp[n+1];                                        // dp[i] = max total value so far if the last taken flower has height i
    memset(dp, 0, sizeof(dp));

    for(int flower = 0; flower < n; flower++) {

        int x = h[flower] + base;                       // query for max dp[i] in range [0, h[flower]-1]          
        int best = 0;
        while(x > 1) {
            if(x%2 == 1) {
                best = max(best, tree[x-1]);
            }
            x /= 2;
        }
        dp[h[flower]] = best + val[flower];

        for(int i= base+h[flower]; i >= 1; i/=2) {      // update the tree 
            tree[i] = max(tree[i], dp[h[flower]]);
        }

        // for(int i = 0; i< h[flower]; i++) {
        //     int &curr = dp[h[flower]];
        //     curr = max(curr, dp[i] + val[flower]); 
        // }
    }

    int ans = 0;
    for(int i=0; i<=n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}