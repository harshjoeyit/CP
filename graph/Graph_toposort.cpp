
/*
Topological Sort
*/

#include<bits/stdc++.h>
using namespace std;

// toposort 
vector<vector<int>> g;
vector<int> inorder;
int n, m;

void toposort() {
      vector<int> tp;
      queue<int> q;
      for(int i=0; i<n; i++) {
            if(inorder[i] == 0) {
                  q.push(i);
            }
      }

      while(!q.empty()) {
            int u = q.front();
            q.pop();
            tp.push_back(u);

            for(auto v: g[u]) {
                  inorder[v] -= 1;
                  if(inorder[v] == 0) {
                        q.push(v);
                  }
            }
      }

      for(auto v: tp) {
            cout << v << " ";
      }cout << endl;
}

void graphInput() {
      cin >> n >> m;
      g.assign(n, vector<int>());
      inorder.assign(n, 0);
      for(int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            inorder[y] += 1;
      }
}

int main() {
      graphInput();
      toposort();
}