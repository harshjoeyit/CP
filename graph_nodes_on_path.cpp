
// essence of the problem 
// query 
// each query contains some nodes 
// find if there exist a path from 1 to any node u such that all nodes lie on it

// concept use - intime - outtime (euler tour)
// https://codeforces.com/contest/1328/problem/E

#include<bits/stdc++.h>
using namespace std;

#define int long long int 
const int mxN=2e5+10; 
int tin[mxN], tout[mxN], dis[mxN], par[mxN];
vector<int> g[mxN];
int n, T=0, q;

void dfs(int u, int p=-1) {
    tin[u] = T++;
    for(auto v: g[u]) {
        if(v == p)  continue;
        dis[v] = dis[u]+1;
        par[v] = u;
        dfs(v, u);
    }
    tout[u] = T++;
}

void tree_input() {
    for(int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void query() {
    for(int i=0; i<q; i++) {
        int k, fv=1;
        cin >> k;
        vector<int> v(k);

        for(int j=0; j<k; j++) {
            cin >> v[j];
            if(v[j] != 1)                       // replacing node by its parent 
                v[j] = par[v[j]];
            if(dis[v[j]] > dis[fv])
                fv = v[j];                      // finding the deepest node
        }
        // cout << "fv: " << fv << endl;

        // for(int j=0; j<k; j++)
        //     cout << v[j] << " ";
        // cout << endl;

        bool ans = true;
                                                // checking if all the nodes in the vector belong on path from (1 to fv)
                                                // this can only happen if in time of the node and outime of nodes is 
                                                // in between 1 and fv
        for(int j=0; (j<k) && ans; j++) {       
            if( tin[1] <= tin[v[j]] && tin[v[j]] <= tin[fv] && 
                tout[fv] <= tout[v[j]] && tout[v[j]] <= tout[1] ) {
                continue;
            } 
            else 
                ans = false;
        }
        cout << ((ans==1)?"YES":"NO") <<"\n";
    }
}

void solve() {
    cin >> n >> q;
    tree_input();
    dis[1]=0;
    par[1]=-1;
    dfs(1);

    query();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}