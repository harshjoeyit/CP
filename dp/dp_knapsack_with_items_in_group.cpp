
/*
given girls with w and b
some girls are friend and belong to same group

given a knapsack with capacity cap
maximize value of kanpsack (b)

such that either 1 girl pf the whole group is picked for the knapsack

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1005;
int w[mxN], b[mxN], dp[mxN];
int n, m, cap, cnt=0;
vector<int> g[mxN], group[mxN];
bool vis[mxN];

void dfs(int u) {
    vis[u] = 1;
    group[cnt].push_back(u);
    for(auto v: g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m >> cap;
    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }
    int x, y;
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // breaking into groups
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
        ++cnt;
    }

    for(int i=0; i<cnt; i++) {
        
        for(int j=cap; j>=0; j--) {
            int grp_b = 0, grp_w = 0;

            // picking 1 element from each group 
            for(auto k: group[i]) {
                // wieght of current item from group i is less than j 
                if(j >= w[k]) {
                    // maximising beauty for weight j
                    dp[j] = max(dp[j], dp[j-w[k]] + b[k]);
                }
                // sum of beauty and weight over whole group
                grp_b += b[k];
                grp_w += w[k];
            }
            // picking whole group
            if(j >= grp_w) {
                // maximizing beauty for weight = j
                dp[j] = max(dp[j], dp[j-grp_w] + grp_b);
            }
        }
    }
    cout << dp[cap] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}