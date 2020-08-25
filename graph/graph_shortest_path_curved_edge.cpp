
/*  
You are given a list of edges in a graph and for each pair of vertices that are 
connected by an edge, there are two edges between them, one curved edge and one 
straight edge i.e. the tuple (x, y, w1, w2) means that between vertices x and y,
 there is a straight edge with weight w1 and a curved edge with weight w2. You 
 are given two vertices a and b and you have to go from a to b through a series 
 of edges such that in the entire path you can use at most 1 curved edge. Your 
 task is to find the shortest path from a to b satisfying the above condition.


 Approach 
1.Run dijkstra from node a. Let's call Da[i] be the shortest path to node i from node a using only straight edges.

2. Again run dijkstra from node b. Let's call Db[i] be the shortest path to node i from node b using only straight edges.

3. Let ans be our final answer. Initialize ans by Da[b] because this is the answer for using no curved edges.

4. So ans=Da[b];

5. Now for using exactly one curved edge we can check for every edge (u,v) by the following way,

6. ans=min(ans,Da[u]+weight of curved edge (u,v) +Db[v])

7. ans=min(ans,Da[v]+weight of curved edge (v,u) +Db[u])

8. Finally ans will be the answer for using at most one curved edge.

*/


#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int> 
const int INF = 1e9;
vector<vector<pi>> g;
vector<vector<int>> curved;
vector<int> da, db;
int n, m, a, b;

void dijkstra(int u, vector<int> &dis) {
      priority_queue<pi, vector<pi>, greater<pi>> pq;
      dis[u] = 0;
      pq.push({0, u});

      while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // cout << u << endl;

            for(auto p: g[u]) {
                  int v = p.first;
                  int w = p.second;
                  // cout << v << " .. " << w << endl;
                  if(dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        pq.push({dis[v], v});
                  }
            }
      }
}

int main() {
      cin >> n >> m;
      cin >> a >> b;

      g.assign(n, vector<pi>());
      da.assign(n, INF);
      db.assign(n, INF);
      
      for(int i=0; i<m; i++) {
            int x, y, w, cw;
            cin >> x >> y >> w >> cw;
            g[x].push_back({y, w});
            g[y].push_back({x, w});
            // curved edge weight
            curved.push_back({x, y, cw});
      }

      dijkstra(a, da);
      dijkstra(b, db);

      // ans = min distance from a -> b with at max one curved edge 
      // current ans wothout curved edge from a -> b = da[b]
      int ans =  da[b];

      for(int i=0; i<m; i++) {
            int u = curved[i][0];
            int v = curved[i][1];
            int cw = curved[i][2];

            ans = min(ans, da[u] + cw + db[v]);
            ans = min(ans, da[v] + cw + db[u]);
      }

      cout << ans << endl;
}