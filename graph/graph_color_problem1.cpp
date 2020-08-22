
/*
coloring the graph -
1. with no adjacent same 
2. with the smallest color number not choosen by its neighbours   
https://codeforces.com/contest/1362/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 5e5+10;
int n, m;
pair<int, int> a[mxN];
vector<int> g[mxN];
bool vis[mxN], flag;

void dfs(int u) {
      vis[u] = true;
      // for a node with color c 
      // it must be connected with at least 1 node with color 1, 2, 3....c-1 
      // beacuse the problem says the node gets color with minimum missing number 
      // from the sorted sequence of its connected nodes 
      unordered_set<int> st;
      for(int i=1; i<a[u].first; i++) {
            st.insert(i);
      }
      for(auto v: g[u]) {
            // erase the node from set if found 
            if(st.count(a[v].first)) {
                  st.erase(a[v].first);
            }
            // adajcent nodes cannot be of same color
            if(a[u].first == a[v].first) {
                  flag = true;
                  return;
            }
            if(!vis[v]) {
                  dfs(v);
            }
      }
      // 1, 2, ...  c-1 - all must be connected
      if(st.size() > 0) {
            flag = 1;
      }
}

void solve() {
      int x, y;
      cin >> n >> m;
      
      for(int i=0; i<m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
      }
      
      for(int i=1; i<=n; i++) {
            cin >> a[i].first;
            // check for color must <= n
            if(a[i].first > n) {
                  flag = true;
            }
            a[i].second = i;
      }
      if(flag == true) {
            cout << -1 << endl;
            return;
      }

      flag = false;
      for(int u=1; u<=n; u++) {
            if(!vis[u]) {
                  dfs(u);
            }
            if(flag) {
                  cout << -1 << "\n";
                  return;
            }
      }
      
      // final sequence of coloring the graph
      // sorting according to the color of the vertex
      // the lowest color vertex is colored first, then the vertex with higher color;
      sort(a+1, a+n+1);
      for(int i=1; i<=n; i++) {
            cout << a[i].second << " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}