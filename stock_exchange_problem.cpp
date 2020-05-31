#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ans[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    stack<pair<int, int>> s;
    s.push({100000, -1});
    
    for(int i=0; i<n; i++) {
        while(s.top().first <= a[i]) {
            s.pop();
        }
        ans[i] = i-s.top().second;
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