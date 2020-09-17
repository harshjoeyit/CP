
/*
suppose the diameter is the length b/w two vertex (w<------------->z)
if we find any one of those, the using dfs we can find the z and the distance as well 

Similar problems 
for every root v of the tree find the max path length possible with contains v

Sol - use in out dp
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> G[N];
int vis[N];
// w = deepest node, mx = max distance to deepest node 
int w, mx;

void dfs(int u, int d) {
    vis[u] = 1;
    if(d > mx) {
        mx = d;
        w = u;
    }  

    for(auto v: G[u]) {
        if(!vis[v]) {
            dfs(v, d+1);
        }
    }
}

int main()  {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    // dfs from a random root
    dfs(2, 0);
    cout << "w: " << w << endl;
    memset(vis, 0, sizeof(vis));
    // resetting 
    mx = 0;
    // we found w, now dfs from w  
    dfs(w, 0);
    cout << "z: " << w << endl;
    cout << mx << endl;
}