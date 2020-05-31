#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 105;
int n, a[mxN];

void solve() {
    cin >> n;
    int mx = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    
    int mxcnt = 0;
    for(int i=2; i<=mx; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(a[j]%i == 0)
                ++cnt;
        }
        mxcnt = max(cnt, mxcnt);
    }
    cout << mxcnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}