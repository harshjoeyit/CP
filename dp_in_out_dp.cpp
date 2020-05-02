
/*
In-Out DP on trees

Find the height of the tree for every vertex 
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 1e5+10;
vector<int> g[mxN];
int a[mxN], in[mxN], out[mxN], dp[mxN];

// simple dfs for finding in[u]
void dfs1(int u, int p) {
    in[u] = 0;
    for(int v: g[u]) {
        if(v != p) {
            dfs1(v, u);
            in[u] = max(in[u], 1+in[v]);
        }
    }
}

void dfs2(int u, int p) {
    int mx1(-1), mx2(-1);

    // finding top 2 maximum values in the in[v] i.e children of u
    for(int v: g[u]) {
        if(v != p) {
            if(in[v] >= mx1) {
                mx2 = mx1;
                mx1 = in[v];

            } else if(in[v] > mx2) {
                mx2 = in[v];
            }
        }
    }

    for(int v: g[u]) {
        if(v != p) {
            int use = mx1;
            if(mx1 == in[v]) {
                use = mx2;
            }
            // choose the max among siblings od the one from the parent 
            out[v] = max(1+out[u], 2+use);
            dfs2(v, u);
        }
    }
}

void solve() {
    int n, u, v;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
    // answer is independent of the root called with, so we choose 1
	dfs1(1, 0);
	dfs2(1, 0);
	
	for(int i=1; i<n+1; i++) {
		dp[i] = max(in[i], out[i]);
		cout << dp[i] << " " ;
	}

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
