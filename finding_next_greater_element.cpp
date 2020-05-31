#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ans[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
        ans[i] = -1;                        // if none element in the array after it is greater than this element
    }
    
    int INF = 1e18+5;
    stack<pair<int, int>> s;
    s.push({INF, -1});
    
    for(int i=0; i<n; i++) {
        pair<int, int> p = {-1, -1};
        while(s.top().first <= a[i]) {
            p = s.top();
            s.pop();
            ans[p.second] = a[i];
        }
        s.push({a[i], i});
    }
    for(int i=0; i<n; i++)
        cout <<ans[i] << " ";
    cout <<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}