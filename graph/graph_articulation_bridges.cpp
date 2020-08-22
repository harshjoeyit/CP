
#include<bits/stdc++.h>
using namespace std;

int n; 
vector<vector<int>> g; 

vector<bool> visited;
vector<int> tin, low;
int timer;


// Articulation Point

void IS_CUTPOINT(int u) {
      //  (Caution that this can be called multiple times for a vertex).
      cout << u << "\n";
}
void dfs(int u, int p = -1) {
      visited[u] = true;
      tin[u] = low[u] = timer++;
      int children = 0;

      for (int v : g[u]) {
            if (v == p) {
                  // parent
                  continue;
            }
            if (visited[v]) {
                  // we reach a visited vertex, update the low
                  low[u] = min(low[u], tin[v]);
            } else {
                  dfs(v, u);
                  // backtracking, keep updating the low of u 
                  low[u] = min(low[u], low[v]);
                  if (low[v] >= tin[u] && p!=-1) {
                        // node is not a root and has a child with 
                        // has no back edge to parents of u
                        IS_CUTPOINT(u);
                  }
                  ++children;
            }
      }

      // special case for the root node 
      if(p == -1 && children > 1) {
            IS_CUTPOINT(u);
      }
}
void find_cutpoints() {
      timer = 0;
      visited.assign(n, false);
      tin.assign(n, -1);
      low.assign(n, -1);

      // considering graph to have more than one connected components 
      for (int i = 0; i < n; ++i) {
            if (!visited[i])
                  dfs (i);
      }
}


// Bridges


void IS_BRIDGE(int a, int b) {
     cout << a << " " << b << "\n";
}
void dfs(int u, int p = -1) {
      visited[u] = true;
      tin[u] = low[u] = timer++;

      for (int v : g[u]) {
            if (v == p) {
                  // parent
                  continue;
            }
            if (visited[v]) {
                  // update low since we reached a visited vertex
                  low[u] = min(low[u], tin[v]);
            } else {
                  dfs(v, u);
                  // update the low
                  low[u] = min(low[u], low[v]);
                  if (low[v] > tin[u]) {
                        // there is no back edges from v
                        IS_BRIDGE(u, v);
                  }
            }
      }
}
void find_bridges() {
      timer = 0;
      visited.assign(n, false);
      tin.assign(n, -1);
      low.assign(n, -1);
      for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                  dfs(i);
            } 
      }
}


void graphInput() {
      int m;
      cin >> n >> m;
      g.assign(n, vector<int>());
      
      for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
      }
}
int main() {
      // graphInput();
      // find_cutpoints();
      // find_bridges()
}