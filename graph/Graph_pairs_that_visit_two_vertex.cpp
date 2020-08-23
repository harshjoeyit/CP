#include<bits/stdc++.h>
using namespace std;

// graph is connected with bidirectional roads 
// a, b are cities with the fair going on
// find number of pairs of vertices (x, y) such that going from x to y or y to x
// you have to pass through a and b both 

// approach 
// DFS on a - mark the vertices that can be visited with a
// DFS on b - mark the vertices that can be visited with b,
//             if the vertex is marked a then mark it -1 

// count the vertices of a and b , ans = a*b
    
vector<vector<int>> g;
vector<bool> vis;
vector<int> marked;
int n, m, a, b;

void graphInput() {
      cin >> n >> m >> a >> b;
      g.assign(n, vector<int>());
      for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
      }
}

void dfs1(int u) {
      if(u == b) {
            return;
      }
      vis[u] = true;
      marked[u] = a;

      for(auto v: g[u]) {
            if(!vis[v]) {
                  dfs1(v);
            }
      }
}

void dfs2(int u) {
      if(u == a) {
            return;
      }
      if(marked[u] == a) {
            marked[u] = -1;
      } else if(marked[u] == -1) {
            marked[u] = b;
      }
      vis[u] = true;

      for(auto v: g[u]) {
            if(!vis[v]) {
                  dfs2(v);
            }
      }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        graphInput();
        vis.assign(n, 0);
        marked.assign(n, -1);
        
        dfs1(a);
        vis.assign(n, false);
        dfs2(b);

        // count
        int cntA = 0, cntB = 0;
        for(int i=0; i<n; i++) {
              // we dont want to count a and b so 
              if(marked[i] == a &&  i != a) {
                    cntA += 1;
              } else if(marked[i] == b && i != b){
                    cntB += 1;
              }
            // cout << marked[i] << " ";
        }

        cout << cntA * cntB << endl;
    }
}