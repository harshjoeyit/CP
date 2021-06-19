#include<bits/stdc++.h>
using namespace std;

int bfs(int u, int n, bool graph[101][101], vector<bool> &vis, vector<int> &color, int m) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
	int mxColor = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v=0; v<n; v++) {
            if(graph[u][v]) {
                if(color[v] == color[u]) {
                    color[v]++;
					mxColor = max(mxColor, color[v]);
					if(mxColor > m) {
						return 0;
					}
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
	return 1;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<bool> vis(n, 0);
    vector<int> color(n, 1);        // 1 <= color[u] <= m
    
    for(int u=0; u<n; u++) {
        if(!vis[u]) {
            // color this component with minimum possible colors
            if(!bfs(u, n, graph, vis, color, m)) {
				return false;
			}
        }
    }

	return true;
}


int main() {
	
}
