#include<bits/stdc++.h>
using namespace std;

const int nMx = 100;
int n, m;
bool g[nMx][nMx];
int match[nMx];
bool vis[nMx];

bool bpm(int u) {
    vis[u]=1;
	for(int v=0; v<n; ++v) {        
		if(g[u][v] && (match[v]<0 || !vis[match[v]] && bpm(match[v]))) {
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
    cin >> m >> n;              // m applicants , n jobs
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) 
            cin >> g[i][j];
    
    cout << " max matching: " << maxBPM() << endl;
    for(int i = 0; i < n; i++) 
        if(match[i] >= 0)
            cout << match[i] << " -> " << i << endl;
    
}
