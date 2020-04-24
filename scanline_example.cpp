
/*
Scanline Algorithm

https://codeforces.com/contest/1343/problem/D

Your task is to replace the minimum number of elements (replacement is the following operation: 
choose some index i from 1 to n and replace ai with some integer in range [1;k]) to satisfy the following conditions:
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int 

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> pref(2*k+10);                               //  prefix array
    unordered_map<int, int> ump;                            // map for storing a[L]+a[R] - for checking if 0 change is required
    pair<int, int> p[n/2];                          

    for(auto &x: a)                                         // original array
        cin >> x;

    for(int i=0; i<n/2; i++) {
        p[i].first = min(a[i], a[n-i-1]);                   // storing the intervals 
        p[i].second = max(a[i], a[n-i-1]);                  
    }

    for(auto q: p) {
        int l = q.first+1;                                  // finding the minimum and maximum values that can be made with exactly one change
        int r = q.second+k;                                 // change r to 1 for min value and l to k for max value

        ump[q.first+q.second]++;

        pref[l]++;                                          // scan line - for query [l, r] - add 1 to starting of interval 
        pref[r+1]--;                                        // and -1 from 1 after the end of interval
    }

    int s = 0;
    for(int i=0; i<2*k+10; i++) {                           // after prefix sum we find for every i - its count of number of intervals it occurs in
        s += pref[i];
        pref[i] = s;
    }

    int ans = n;                // max changes possible
    for(int i=2; i<=2*k; i++) {                         // try all values of the final x
        int cnt0 = ump[i];                              // 0 change when x is already equal to a[i] + a[n-i-1]
        int cnt1 = pref[i] - cnt0;                      // remove zero changes 
        int cnt2 = n/2 - cnt1 - cnt0;                   // remainng are those require 2 changes
        
        ans = min(ans, cnt1 + cnt2*2);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}