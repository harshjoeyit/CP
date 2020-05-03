
/*
https://codeforces.com/contest/337/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 1e5+10;
const int INF = 2e5;
vector<int> g[mxN];
int a[mxN], in[mxN], out[mxN], dp[mxN], mark[mxN];
int n, m, d;

void dfs1(int u, int p) {
    // finding largest distance of each node from a marked vertex in a subtree    
    if(mark[u] == 0) {
        // for the case when no marked vertex is present in the subtree
        in[u] = -INF;
    } else {                            
        // marked vertex is 0 distance away from itself 
        in[u] = 0;
    }
    
    for(int v: g[u]) {
        if(v != p) {
            dfs1(v, u);
            in[u] = max(in[u], 1+in[v]);
        }
    }
}

void dfs2(int u, int p) {
    // finding max distance of a marked node from current node not in the subtree
    int mx1(-INF), mx2(-INF);

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
            
            out[v] = max(1+out[u], 2+use);
            if(mark[v] && out[v] < 0) {
                out[v] = 0;
            }

            dfs2(v, u);
        }
    }
}

void solve() {
    cin >> n >> m >> d;
    int x, y;

    for(int i=0; i<n; i++) {
        mark[i+1] = 0;
        in[i+1] = INF;
    }
    for(int i=0; i<m; i++) {
        cin >> x;
        mark[x] = 1;
    }
	for(int i=0; i<n-1; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs1(1, 0);
    // when 1 is not marked then out[1] has to be minimum since ans for it is in[1]
    out[1] = -INF;      
	dfs2(1, 0);
    if(mark[1] == 1) {
        // if marked then ans 0 for the calculation of other nodes
        out[1] = 0;
    }

    dfs2(1, 0);
    int ans = 0;

    // for(int i=0; i<n; i++) {
    //     cout << in[i+1] << " ";
    // }cout << endl;
    // for(int i=0; i<n; i++) {
    //     cout << out[i+1] << " ";
    // }cout << endl;

	for(int i=0; i<n; i++) {
		ans += (in[i+1] <= d && out[i+1] <= d);
	}
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
