
/*
    finding quadruples such that 
    a + b + c = d;
    idx(x) - index of x
    idx(a) < idx(b) < idx(c) < idx(d) 
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, vector<int>> mp;
      
    // a + b + c = d or
    // a + b = d - c
    // we find pairs of (a + b)  - where idx(a) < idx(b)

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    for(int i=0; i<n; i++)                      // a[i] -> b, a[j] -> a
        for(int j=0; j<i; j++) 
            mp[ a[i]+a[j] ].push_back(i);         // vector stores index of b, since when we find c we need index of b
    
    int ans = 0;

    // finding (d-c) pairs
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            int val = a[i] - a[j], cnt;           // a[i] -> d, a[j] -> c
            if(mp.count(val) > 0) {
                cnt = lower_bound(mp[val].begin(), mp[val].end(), j) - mp[val].begin();         // we find largest index of c such that idx(c) < idx(d)
                ans += cnt;
            }                                                                                   // all the lower indices will be in cnt
        }
    }
    cout << ans << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
