#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 2e5+10;
int depth[mxN], siz[mxN], det[mxN];
vector<int> g[mxN];

int dfs(int u, int d=0, int p=-1) {
    depth[u] = d;
    for(auto v: g[u])
        if(v != p) 
            siz[u] += dfs(v, d+1, u);

    det[u] = siz[u] - depth[u];
    return siz[u]+1;
}

void solve() {
    int n, x, y, k;
    cin >> n >> k;

    for(int i=0; i<n-1; i++) {
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);

    sort(det, det+n);
    int ans = 0;

    for(int i=0; i<k; i++)
        ans += -det[i];
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
}