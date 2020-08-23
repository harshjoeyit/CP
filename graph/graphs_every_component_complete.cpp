
/*
check if every component is a complete graph
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN = 150010;
vector<int> g[mxN];
bool vis[mxN];
 
void dfs(int a, int & nodeCnt, int & edgeCnt) {
	vis[a] = true;
	
      ++nodeCnt;
	edgeCnt += g[a].size();

	for(int b : g[a]) {
            if(!vis[b]) {
                  dfs(b, nodeCnt, edgeCnt);
            }
      }
}
 
int main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			
                  int nodeCnt = 0, edgeCnt = 0;
			dfs(i, nodeCnt, edgeCnt);

                  // Note since the graph is undirected 
                  // we have every edge twice, so 
                  // edgeCount/2 = nodeCnt*(nodeCnt-1)/2
			
                  if(edgeCnt != (long long) nodeCnt * (nodeCnt - 1)) {
				puts("NO");
				return 0;
			}
		}
            
	cout << "YES\n";
}
