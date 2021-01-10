/*
    https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

    Shortest path from (source --> dest) in DAG 
    Method 1: Bellman Ford (V^2)
    Method 2: Dijkstra (E + VlogV)
    
    Method 3: Toposort
*/


#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int> 
#define INF 1e9

int n, m;
vector<vector<pi>> g;
vector<int> dis, indegree;

void toposort(int s) {
    queue<int> q;
    dis.assign(n, INF);
    // distance of source = 0
    dis[s] = 0;
    q.push(s);

    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            // these vertices may be unreachable from s, so dis[i] may not be 0, and = INF
            // dis[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();  
        q.pop();

        for(auto p: g[u]) {
            int v = p.first, w = p.second;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            } 
            indegree[v] -= 1;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    g.assign(n, vector<pi>());
    indegree.assign(n, 0);

    for(int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        indegree[y] += 1;
    }

    int s;
    cin >> s;

    toposort(s);

    for(int i=0; i<n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}