#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int INF = 10e+7;
const int N = 100;
int n;
vector<vector<int>> cpct;
vector<int> g[N];

int bfs(int s, int t, vector<int> &p) {
	fill(p.begin(), p.end(), -1);
	p[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INF});

	while(! q.empty()) {
		int u = q.front().first;
		int flow = q.front().second;
		q.pop();

		for(int v: g[u]) {
			if(p[v] == -1 && cpct[u][v]) {
				p[v] = u;
				int new_flow = min(flow, cpct[u][v]);
				if(v == t)
					return new_flow;
				q.push({v, new_flow});
			}
		}
	}
	return 0;
}

// O(VE^2)
int max_flow(int s, int t) {
	int flow = 0;
	vector<int> p(n);
	int new_flow;

	while(new_flow = bfs(s, t, p)) {
		flow += new_flow;
		int cur = t;
		while(cur != s) {
			int prev = p[cur];
			cpct[prev][cur] -= new_flow;
			cpct[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

signed main() {
	cin >> n;
	cpct.assign(n, vector<int>(n));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> cpct[i][j];

	// adding on those edges where either u -> v edge exist or v -> u edge exists(capacity is given)
	// because later a back edge will be needed 
	// there is no need of any edges where neither is present		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(cpct[i][j] == 0 && cpct[j][i] == 0)
				continue;
			else
				g[i].push_back(j);
		}
	}

	int s, t;
	cin >> s >> t;	
	cout << max_flow(s, t) << endl;
}