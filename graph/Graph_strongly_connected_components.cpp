/* 
Strongly connected components -

>> Kosajaru's Algorithm

>> https://www.youtube.com/watch?v=RpgcYiky7uw

- we store vertex in increasing order of finsh/exit time in df1 
- after this if we consider SCC to be a single node then
- reverse graph looks like Directed Acyclic Graph
- and now we can find the SCC in topological sort order
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g, gr;
vector<bool> vis;
vector<int> order, component;
int n, m;

template <typename T>
void print(vector<T> v) {
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

void dfs1(int u) {
    vis[u] = true;
    for(auto v: g[u]) {
        if(!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    component.push_back(u);
    for(auto v: gr[u]) {
        if(!vis[v]) {
            dfs2(v);
        }
    }
}

void graphInput() {
      cin >> n >> m;
      g.assign(n, vector<int>());
      // transpose/reversed graph
      gr.assign(n, vector<int>());
      
      for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            gr[v].push_back(u);
      }
}

int main() {
    graphInput();

    // store vertices int order of finish time 
    vis.assign(n, false);
    for(int i = 0; i < n; i++) {
        if( !vis[i]) {
            dfs1(i);
        }
    }
    
    // use the reversed graph
    // generate SCCs in topological sort 
    vis.assign(n, false);
    for(int i = 0; i < n; i++) {
        int u = order[n-i-1];
        if( !vis[u]) {
            dfs2(u);
            print(component);
            component.clear();
        }
    }
}
