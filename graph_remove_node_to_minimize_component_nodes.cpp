
/*
Given a tree, find a node(x) such that 
after removing x and all the edges connecting x
the maximum nodes in a component is minimized 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n, x, w;
vector<vector<int>> g;

int dfs(int u, int par = 0) {
    // tot = total nodes in this subtree(including this node)
    int tot = 1, mx = 0;

    for (auto v : g[u]) {
        if(v != par) {
            int c = dfs(v, u);
            // c = count of nodes in the subtree 
            mx = max(mx, c);
            tot += c;
        }
    }

    // mx = max of all the nodes in subtrees and 
    // the parent part, which is equal has (n - tot) nodes 
    mx = max(mx, n - tot);
    if(mx < w) {
        // minimize the answer 
        w = mx;
        x = u;
    } else if(mx == w) {
        // minimize the node number 
        x = min(x, u);
    }

    return tot;
}

void solve() {
    cin >> n;
    g.assign(n+1, vector<int>());

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    w = INT_MAX;
    dfs(1);
    cout << x << " " << w << "\n";
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}