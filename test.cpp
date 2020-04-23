

#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 2e5+10;
vector<int> g[mxN];
int a, b, c, n, m, vis[mxN], p[mxN], dis[mxN];

void bfs(int u, int w, int par[]) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    par[u] = -1;

    while(!q.empty()) {
        int u = q.front();  q.pop();
        if(u == w) 
            break;
        for(auto v: g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int calc_dis(int u, int w) {
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    dis[u] = 0;

    while(!q.empty()) {
        int u = q.front();  q.pop();
        if(u == w) 
            break;
        for(auto v: g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[w];
}

void solve() {
    cin >> n >> m >> a >> b >> c;
    --a; --b; --c;
    int x, y;

    for(int i=0; i<m; i++)
        cin >> p[i];
    sort(p, p+m);

    for(int i=0; i<n; i++)
        g[i].clear();

    for(int i=0; i<m; i++) {
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    int par1[n];            // for a - b 
    int par2[n];            // for b - c
    
    bfs(a, c, par1);
    bfs(b, c, par2);

    int v = c;
    while(par1[v] == par2[v]) {
        v = par1[v];
    }

    // v is the intersection 
    // cout << "v: " << v <<endl; 

    int av = calc_dis(a, v);
    int bv = calc_dis(b, v);
    int cv = calc_dis(c, v);

    // cout << av << " " << bv << " " << cv << endl;
    int ans = 0;

    for(int i=0; i<bv; i++)
        ans += p[i];
    ans = 2*ans;

    for(int i=bv; i<av+bv+cv; i++)
        ans += p[i];

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