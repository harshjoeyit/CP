
/*
Read - https://codeforces.com/problemset/status/212/problem/E/page/2?order=BY_PROGRAM_LENGTH_ASC

Brute force approach - find subtrees of each node and their sizes

eg subtree sizes of a node: [1, 2, 3]
possible sums -(1, 5), (2, 4), (3, 3)
basically we have to find the number of distinct ways we can divide the sizes in two subsets

below is efficient approach similar to bitset_subset_sum_knapsack.cpp
we set all the ith bits such that sum = i is possible (adding the sizes of the subtrees) in the tree 
finaly we check which sizes possible 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int mxN = 5005;
vector<int> g[mxN]; 
int sz[mxN], n;
bitset<mxN> ans, temp[mxN];

void dfs(int u, int p) {
        sz[u] = 1;
        temp[u][0] = 1;
        for(auto v: g[u]) {
                if(v != p) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        temp[u] |= temp[u] << sz[v];
                }
        }
        temp[u] |= temp[u] << (n - sz[u]); 
        ans |= temp[u];
}

void solve(){
        cin >> n;
        int x, y;
        for(int i=0; i<n-1; i++) {
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        dfs(1, 0);
        set<int> res;
        for(int i=1; i<n-1; i++) {   // ingnoring the leaf nodes by not considering i = n since it is not a valid case
                if(ans[i]) {
                        res.insert(i);
                }
        }
        cout << res.size() << "\n";
        for(auto x: res) {
                cout << x << " " << (n-x-1) << "\n";
        }
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);     
        solve();
}