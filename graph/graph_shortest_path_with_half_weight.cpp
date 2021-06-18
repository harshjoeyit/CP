
/*
    Shortest path with 1 edge weight halved at most.
    https://cses.fi/problemset/task/1195/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

#define pi pair<int, int> 
const int mxN = 1e18;
vector<vector<pi>> g1, g2;
vector<vector<int>> edges;
vector<int> disA, disB, vis;

void dijkstra(int u, vector<vector<pi>> &g, vector<int> &dis) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dis[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto p: g[u]) {
            int w = p.second, v = p.first;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    g1.assign(n+1, vector<pi>());
    g2.assign(n+1, vector<pi>());
    disA.assign(n+1, mxN);
    disB.assign(n+1, mxN);

    for(int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
        g1[x].push_back({y, w});
        g2[y].push_back({x, w});
    }

    vis.assign(n+1, 0);
    dijkstra(1, g1, disA);
    vis.assign(n+1, 0);
    dijkstra(n, g2, disB);
    
    int ans = mxN;

    for(auto e: edges) {
        int u = e[0], v = e[1], w = e[2];
        int op = disA[u] + w/2 + disB[v];
        ans = min(ans, op);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}