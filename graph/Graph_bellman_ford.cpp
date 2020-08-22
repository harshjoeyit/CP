
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

struct edge {
    int a, b, cost;
};

const int INF = 1e9;
vector<edge> edges;
int n, m, v;

void shortestPath(int u) {
      vector<int> dis(n, INF);
      dis[u] = 0;
      bool any;

      for(int i=1; i<=n-1; i++) {
            any = false;
            // all edges relax n-1 times 
            for(auto e: edges) {
                  if (dis[e.a] < INF) {
                        if (dis[e.b] > dis[e.a] + e.cost) {
                              // relax the edge b/w a and b
                              dis[e.b] = dis[e.a] + e.cost;
                              any = true;
                        }
                  }
            }
            if(!any) {
                  break;
            }
      }

      // try relaxing 1 more time, if relaxes more then 
      // negetive wieght cycle is possible

      any = false;
      for(auto e: edges) {
            if (dis[e.a] < INF) {
                  if (dis[e.b] > dis[e.a] + e.cost) {
                        // relax the edge b/w a and b
                        dis[e.b] = dis[e.a] + e.cost;
                        any = true;
                  }
            }
      }

      if(any) {
            cout << "Neg weight cycle present\n";
      } else {
            for(int i=0; i<n; i++) {
                  cout << dis[i] << " ";
            }
            cout << "\n";
      }
}

void graphInput() {
      cin >> n >> m;
      for(int i=0; i<m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            edges.push_back({a, b, w});
      }
}

int main() {
      graphInput();
      shortestPath(0);
}