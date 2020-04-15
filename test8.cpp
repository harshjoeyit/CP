
// codeforces problem D

#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1e5+10;
int n;
vector<int> g[mxN];
int degree[mxN];
unordered_set<int> leafdis;

void dfs(int u, int p=-1, int dis=0) {
	bool nc = 1;

	for(auto v: g[u]) {
		if(v != p) {
			dfs(v, u, dis+1);
			nc = 0;
		}
	}
	if(nc)
		leafdis.insert(dis);
}

void solve() {
	memset(degree, 0, sizeof(degree));
	int x, y;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		cin>> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}

	int u;
	for(int i=0; i<n; i++) {
		if(degree[i] >= 2) {
			u = i;
			break;
		}
	}

	dfs(u);
	for(auto d: leafdis)
		cout << d << " ";
	cout << "\n";
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

        solve();
}
