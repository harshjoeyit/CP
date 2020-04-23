#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 2e5+10;
int n, a[mxN], k;

void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    map<int, int> mp;
    int maxlb = 0, minub = 2*k, s, lb, ub, x, y;

    for(int i=0; i<n/2; i++) {
        x = a[i];
        y = a[n-i-1];
        s = x+y;
        ++mp[s];

        lb = min(x, y);
        ub = max(x, y) + k;
        maxlb = max(maxlb, lb);
        minub = min(minub, ub);
    }
    // cout << maxlb << " " << minub << endl;
    int cnt, ans = n/2;            
    
    for(auto p: mp) {
        s = p.first;
        cnt = p.second;
        if(maxlb <= s && s <= minub) {     
            ans = min(ans, n/2-cnt);
        }
    }   

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}