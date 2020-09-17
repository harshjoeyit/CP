
/*
https://www.spoj.com/problems/ADASALES/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 1e5+10;
vector<int> g[mxN];
int val[mxN], in[mxN], out[mxN];
int n, q;

void dfs1(int u, int p) {
    in[u] = 0;
    for(auto v: g[u]) {
        if(v != p) {
            dfs1(v, u);
            
            // profit = when he buys at u and sells at v
            int profit = max(val[v] - val[u], (int)0);      
            in[u] = max(in[u], in[v] + profit);
        }
    }
}

void dfs2(int u, int p) {
    int mx1(-1), mx2(-1);

    for(int v: g[u]) {
        if(v != p) {
            // profit = when he buys at u and sells at v
            int profit = max((int)0, val[v]-val[u]);
            // finding the first two maximum profit path
            if(in[v] + profit >= mx1) {
                mx2 = mx1;
                mx1 = in[v] + profit;

            } else if(in[v] + profit > mx2) {
                mx2 = in[v] + profit;
            }
        }
    }

    for(int v: g[u]) {
        if(v != p) {

            // profit = when he buys at u and sells at v
            // using one of the two maximums
            int profit = max((int)0, val[v] - val[u]);
            int use = mx1;
            if(mx1 == in[v] + profit) {
                use = mx2;
            }

            // use - maximum money earned from the sibling
            // out[u] - maximum when parent is considered 
            // curr - profit when he moves v -----> u
            // out[v] is max of the gain on v --- > u then either u----> p  or u-----> sibling 

            int curr = max((int)0, val[u] - val[v]);
            out[v] = curr + max(out[u], use);

            dfs2(v, u);
        }
    }
}

void solve() {
    cin >> n >> q;
    int x, y;

    for(int i=0; i<n; i++) {
        cin >> val[i];
    }
	for(int i=0; i<n-1; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

    // construct the in-out dp
    dfs1(0, -1);
    dfs2(0, -1);

    // for(int i=0; i<n; i++) {
    //     cout << in[i] << " ";
    // }cout << endl;

    // for(int i=0; i<n; i++) {
    //     cout << out[i] << " ";
    // }cout << endl;

    while(q--) {                        // query for answering the profit given the starting vertex 
        cin >> x;
        cout << max(in[x], out[x]) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
