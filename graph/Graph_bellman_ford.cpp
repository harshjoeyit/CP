
/*
Bellman Ford algorithm 
- Single Source Shortest Path 
- Directed Graphs 
- Works with negetive weight edges
- Fails on negetive weight cycles

Time Complexity - 
|E| edges are relaxed for |V-1| times => O(E*V)
in the worst case E = |V|*(|V|+1)/2 
O(|V|^3)

After the i-th iteration of outer loop, the shortest paths with at most i edges are calculated. 
There can be maximum |V| – 1 edges in any simple path, 
that is why the outer loop runs |v| – 1 times.


If there is not any negetive weight cycles then the then 
we have got the final answer after relaxation for |V-1| times, else 
If there is a negative weight cycle, then one more iteration detects it.


The Bellman-Ford algorithm works on directed graphs.
 
To make it work with undirected graphs we must make each
You just have to specify any edges {u, v} twice (u, v) and (v, u).
But don't forget, that this also means any edge with a negative weight 
will count as a loop. As the Bellman-Ford algorithm ONLY works on graphs 
that don't contain any cycles with negative weights this actually means 
your un-directed graph mustn't contain any edges with negative weight.
If it doesn't its pretty fine to use Bellmann-Ford.

That is why if no negtive edge has negetive wieght we can use DIJKSTRA

more : https://cp-algorithms.com/graph/bellman_ford.html
*/



#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<vector<int>> edges;
int n, m;

void graph_input() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
}

bool relax(vector<int> &dis) {
      bool any = false;
      for(auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            if(dis[u] != inf && dis[v] > dis[u] + w) {
                  dis[v] = dis[u] + w;
                  any = true;
            }
      }
      return any;
}

bool bellmanFord(int u) {
      vector<int> dis(n, inf);
      dis[u] = 0;

      for (int i = 0; i < n - 1; i++) {
            if(!relax(dis)) {
                  break;
            }
      }
      return relax(u);
}

int main() {
      graph_input();
      // relax 1 more time to find neg weight cycle 
      if(bellmanFord(0)) {
            cout << "neg weight cycle\n";
            return;
      }
      for (int i = 0; i < n; i++) {
            cout << 0 << " " << i << " : " << dis[i] << endl;
      }
}