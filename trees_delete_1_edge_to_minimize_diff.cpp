
/*
Given an undirected tree whose each node is associated with a weight. 
We need to delete an edge in such a way that difference between sum 
of weight in one subtree to sum of weight in other subtree is minimized.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> weight;
int n, total;
int ansi, ansj, ansDiff;

int findEdge(int u, int par = -1) {
      int sum = weight[u];
      for(auto v: g[u]) {
            if(v != par) {
                  sum += findEdge(v, u);
            }      
      }
      // lets delete this edge(par--u) and see what difference is genrerated 
      // sum of this subtree = sum 
      // sum of the remaining tree when this edge(par--u) is deleted = total - sum
      // diff = abs ((total - sum) - sum) = abs(total - 2*sum)
      if(u != 0 && abs(total - 2*sum) < ansDiff) {
            ansDiff = abs(total -2*sum);
            ansi = u, ansj = par;
      }
      return sum;
}

int main() {
      cin >> n;
      int x, y;
      g.assign(n, vector<int>());
      for(int i=0; i<n-1; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
      }

      total = 0;
      weight.assign(n, 0);
      for(int i=0; i<n; i++) {
            cin >> weight[i];
            total += weight[i];
      }

      ansDiff = INT_MAX;
      findEdge(0);

      cout << ansDiff << endl;
      cout << ansi << "---" << ansj << endl;
}