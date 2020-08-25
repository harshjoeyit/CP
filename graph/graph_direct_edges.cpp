

/*
a directed tree is given 
change the direction of edges such that a path exist from every vertex to 0 exisits 
find minimum such esges that need to be changed
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;

int dfs(int u) {
	int change = 0;
	vis[u] = true;
	for(auto v: g[u]) {
		if(!vis[abs(v)]) {
			change += dfs(abs(v));
			change += (v > 0);
		}
	}
	return change;
}

int minReorder(int n, vector<vector<int>> &conn) {
	g.assign(n, vector<int>());
	vis.assign(n, false);

	for(auto e: conn) {
		g[e[0]].push_back(e[1]);
		// storing a negetive vertex for the reverse edge
		g[e[1]].push_back(-e[0]);
	}

	dfs(0);
}

int main() {
	vector<vector<int>> conn;
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		conn.push_back(vector<int>(2, 0));
		cin >> conn.back()[0] >> conn.back()[1];
	}
	cout << minReorder(n, conn);
}