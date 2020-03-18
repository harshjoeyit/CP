#include<bits/stdc++.h>
using namespace std;

const int nMx = 505;
int n, k, x;
int adj[nMx][nMx];
int a[nMx];
int match[nMx];
bool vis[nMx];

bool bpm(int u) {
    vis[u]=1;
	for(int v=0; v<n; ++v) {
		if(adj[u][v] && (match[v]<0 || !vis[match[v]] && bpm(match[v])) ) {
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int maxBPM() {
	memset(match, -1, 4*n);
	int flow=0;
	for(int i=0; i<n; ++i) {
		memset(vis, 0, n);
		flow += bpm(i);
	}
	return flow;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		memset(adj, 1, sizeof(adj));
		for(int i=0; i<n; ++i)
			adj[i][i]=0;
		while(k--){
			for(int i = 0; i < n; i++) {
				cin >> a[i];
				--a[i];
				for(int j = 0; j < i; j++)		
					adj[a[j]][a[i]] = 0;			// since on j - jobs
			}										// since on i - candidates
		}

		// those whose matching was not found
		cout << n-maxBPM() << endl;
		for(int i = 0; i < n; i++) 
			cout << match[i] + 1 << " ";
		cout << endl;
	}
}