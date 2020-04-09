

// Aman Spoj problem dfs ... ... .. 


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5+10;
vector<pair<int, int> > g[mxN];
int vis[mxN], b[mxN], sb[mxN], dp[mxN], inc[mxN];
map<pair<int, int>, int> mp;
int n;

void print(int a[], int l, int r) {
	for(int i = l; i <= r; i++) 
		cout << a[i] << " ";
	cout << endl;
}

void decide(int &m, int &sm, int &mv, int v, int x) {
	if(x > m) {
		sm = m;
		m = x;
		mv = v;
	} else if(x > sm)
		sm = x;
}

int dfs1(int u) {
	int m = 0, sm = 0, cur, mv = 0;
	vis[u] = 1;
	for(auto p: g[u]) {
		if( !vis[p.first]) {
			cur = p.second + dfs1(p.first);
			decide(m, sm, mv, p.first, cur);
		}
	}
	b[u] = m;
	sb[u] = sm;
	if(mv != 0)
	 	inc[mv] = 1;
	return b[u];
}

void dfs2(int u, int p) {
	vis[u] = 1;

	if(inc[u]) {
		if(dp[p] > b[p])
			dp[u] = dp[p] + mp[{u, p}];
		else
			dp[u] = max(b[u], (sb[p] + mp[{u, p}]));
	} else
		dp[u] = dp[p] + mp[{u, p}];
	
	for(auto p: g[u])
		if(!vis[p.first])
			dfs2(p.first, u);
}

void solve() {
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		g[x].push_back({y, d});
		g[y].push_back({x, d});
		mp[{x, y}] = d;
		mp[{y, x}] = d;
	}
	dfs1(1);
	print(b, 1, n);
	print(sb, 1, n);
	print(inc, 1, n);

	memset(vis, 0, sizeof(vis));
	dp[1] = b[1];
	vis[1] = 1;
	for(auto p: g[1])
		dfs2(p.first, 1);

	print(dp, 1, n);
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}