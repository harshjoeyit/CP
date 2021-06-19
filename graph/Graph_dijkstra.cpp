 /*
Bellman Ford's Algorithm:

    O(E.V) = complete graph - O(V^3)
    Bellman Ford's algorithm is used to find the shortest paths from the 
    source vertex to all other vertices in a weighted graph. 
    It depends on the following concept: Shortest path 
    contains at most n-1 edges, because the shortest path couldn't have a cycle.

Dijkstra Algo: 

    In the beginning all vertices have a distance of "Infinity", but only 
    the distance of the source vertex = 0, then update all the connected 
    vertices with the new distances (source vertex distance + edge weights), 
    then apply the same concept for the new vertices with new distances and so on

Optimized version is disjktra - O(V^2) , with min priority queue or multiset or set, O(V + Elog(V))


Time Complexity: 

    O(V*V) with adjacency matrix representation
    O(ElogV) with adjacency list represtation


Similar problem 
    - maximum probability path
    - Shortest Path in directed graph 
    - Shortest Path in Directed Acyclic Graph - Topological Sort 

To print the paths to each vertex 
    -simply use a parent array an the job 

NOTE: Dijkstra Cannot be used to find LONGEST PATH 
https://cs.stackexchange.com/questions/17980/is-it-possible-to-modify-dijkstra-algorithm-in-order-to-get-the-longest-path
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

vector<pair<int, int>> g[SIZE];
// initialize with INF distance
vector<int> dist(SIZE, INT_MAX); 
vector<int> vis(SIZE);
vector<int> nodesInPath(SIZE, 1e6);
vector<int> parent(SIZE);

void printPath();

// using priority queue
void dijkstraUsingPQ() {
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto pr: g[u]) {
            int w = pr.first;
            int v = pr.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    /*printing shortest path from 0 as source*/
    // printPath();
}

// multiset do the job as a min-priority queue 
void dijkstraUsingMultiset() {
    dist[0] = 0;
    multiset<pair<int, int>> s;
    // insert the source node with distance = 0
    s.insert({0, 0});
    
    while(!s.empty()) {
        int u = s.begin()->second;
        s.erase(*s.begin());

        // vis array is only for further optimization 
        // since there can be more than one pairs of {w, vertex}, in the multiset
        // we are only concerned with the one with min w 
        // all other would be aoutomatically be ignored by condition put below 
        if(vis[u] == true) {
            continue;
        }
        vis[u] = true;

        for(auto pr: g[u]) {
            int w = pr.first;
            int v = pr.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }
}

// using a set, dont need visited array, since every vertex has single {w, vertex} pair 
void dijkstraUsingSet() {
    set<pair<int, int>> s;
    dist[0] = 0;
    s.insert({0, 0});

    while(!s.empty()) {
        int u = s.begin()->second;
        s.erase(*s.begin());

        for(auto pr: g[u]) {
            int w = pr.first;
            int v = pr.second;
            
            if(dist[u] + w < dist[v]) {
                // means v is in the set already
                if(dist[v] != INT_MAX) {
                    // erase it from the set, update with lower weight later
                    s.erase(s.find({dist[v], v}));
                }    
                dist[v] = dist[u] + w;
                s.insert({dist[v], v}); 
            }
        }
    }
}


// For minimum nodes/edges in path (path is still shortest but with min nodes)
void dijkstraMinNodesPath() {
      nodesInPath[0] = 1;
      dist[0] = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({0, 0});

      while (!pq.empty())
      {
            int u = pq.top().second;
            pq.pop();

            for (auto pr : g[u]) {
                  int w = pr.second;
                  int v = pr.first;

                  if (dist[u] + w < dist[v]) {
                        parent[v] = u;
                        nodesInPath[v] = nodesInPath[u] + 1;
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                  
                  } 
                  else if ((dist[u] + w == dist[v]) && (nodesInPath[u] + 1 < nodesInPath[v])) {
                        nodesInPath[v] = nodesInPath[u] + 1;
                        parent[v] = u;
                  }
            }
    }

    /*printing shortest path from 0 as source*/
//     printPath();
}


int n, m;
void graph_input() {
      cin >> n >> m;
      for (int i = 0; i < m; i++)
      {
            int x, y, w;
            cin >> x >> y >> w;
            g[x].push_back({y, w});
            g[y].push_back({x, w});
      }
}

int main() {
    graph_input();
}

void printPath() {
    for (int i = 0; i < n; i++) {
        int j = i;
        vector<int> path;
        path.push_back(i);
        while (parent[j] != j) {
            path.push_back(parent[j]);
            j = parent[j];
        }
        reverse(path.begin(), path.end());
        cout << "path for " << i << " : ";
        for (auto u : path) {
            cout << u << " ";
        }
        cout << endl;
    }
}
