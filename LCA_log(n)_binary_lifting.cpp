
/*
LCA using binary lifting
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7, mxN = 2e5, LG = 20;
// 1 based indexing 
vector<int> g[mxN];
int a[mxN], lvl[mxN], P[mxN][LG];

void dfs(int u, int p) {
    lvl[u] = 1+lvl[p];
    P[u][0] = p;
    for(auto v: g[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }
}

int LCA(int u, int v) {

    int lg, i;
    if(lvl[u] < lvl[v]) {
        swap(u, v);
    }

    // greatest lg such that 2^lg <= lvl[u]
    for(lg=0; (1<<lg) <= lvl[u]; lg++);
    lg--;                   

    // we move to lvl[v] by jumping 2^i steps until lvl[u] > lvl[v]
    for(i=lg; i>=0; i--) {
        if(lvl[u] - (1<<i) >= lvl[v]) {
            // u --> ancestor of u at 2^i
            u = P[u][i];
        }
    }
    // finally lvl[u] == lvl[v]
    // for the cases when v is ancestor of u
    if(u == v) {
        return u;
    }
    // move untill a uncommon ancestor is found
    for(i=lg; i>=0; i--) {
        if(P[u][i] != -1 and P[u][i] != P[v][i]) {
            u = P[u][i], v = P[v][i];
        }
    }
    // finally P[u][0] = P[v][0]
    return P[u][0];
}

// Get ancestor of node u which is "dis" distance above it
int getAncestor(int u, int dis) {
    
    dis = lvl[u] - dis;
    int i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(int i=lg; i>=0; i--) {
        if(lvl[u]-(1<<i) >= dis) {
            u = P[u][i];
        }
    }
    return u;
}

//returns the distance between
//two nodes "u" and "v".
int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = LCA(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}

void query(int q) {
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
        // cout << getAncestor(x, d) << endl;
        cout << dis(x, y) << endl;
    }
}

void solve() {
    int n, q, x, y;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i=0; i<LG; i++) {
        for(int j=0; j<n+1; j++) {
            P[j][i] = -1;
        }
    }
    
    lvl[0] = -1;
    dfs(1, 0);

    /*
    Let ancestor of u at height 2^i be x
    Let ancestor of x at height 2^i be y 
    Then ancestor of u at height 2^(i+1) is y
    So, 
        P[j][i] = x;
        P[j][i+1] = P[x][i] 
        P[j][i+1] = P[P[j][i]][i] 
    */

    for(int i=1; i<LG; i++) {
        for(int j=1; j<n+1; j++) {
            if(P[j][i-1] != -1) {
                P[j][i] = P[P[j][i-1]][i-1];
            }
        }
    }

    cin >> q;   
    query(q); 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
