#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
	if (n <= 1)	{
		return {0};
	}

	vector<int> degree(n, 0);
	vector<int> g[n];

	for (auto e : edges) {
		int u = e[0], v = e[1];
		g[u].push_back(v);
		g[v].push_back(u);
		degree[u] += 1;
		degree[v] += 1;
	}

	queue<int> q;
	int vis = 0;

	for (int i = 0; i < n; i++) {
		if (degree[i] == 1) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int sz = q.size();

		if (n - vis <= 2) {
			break;
		}

		while (sz--) {
			int u = q.front();
			q.pop();
			vis += 1;

			for (auto v : g[u]) {
				degree[v] -= 1;
				if (degree[v] == 1) {
					q.push(v);
				}
			}
		}
	}

	vector<int> ans;
	// size can be 2 max
	while (!q.empty()) {
		ans.push_back(q.front());
		q.pop();
	}

	return ans;
}