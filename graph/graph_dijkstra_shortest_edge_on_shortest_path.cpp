
/*
    Find the shortest edge on the shortest path 
    from source vertext to destination vertex. 
    NOTE: There can be multiple shortest paths.
*/

#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int> 
#define vi vector<int, int>

/* dis[i] = {d, w}
d = shortest distance from source vertex
w = shortest edge among all shortest paths from source vertex*/
vector<pi> dis;
vector<vector<pi>> g;

void dijkstra(int n, int s) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dis.assign(n+1, {INT_MAX, INT_MAX});
    
    dis[s] = {0, INT_MAX};
    pq.push({0, s});
    
    while(!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();
        
        for(auto p: g[u]) {
            int v = p.second, w = p.first;

            if(dis[v].first > dis[u].first + w) {
                dis[v] = {dis[u].first + w,  min(w, dis[u].second)};
                pq.push({dis[v].first, v});
            }
            else if(dis[v].first == dis[u].first + w) {
                dis[v] = {dis[v].first,  min({w, dis[u].second, dis[v].second})};
            }
        }
    }
}

int shortestEdge(const int n, const vector<vector<int> > &edges, const int s, const int d) {
    g.assign(n+1, vector<pi>());
    for(auto e: edges) {
        int u = e[0], v = e[1], w = e[2];
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    dijkstra(n, s);
	cout << "shortest path = " << dis[d].first << endl;
    cout << "shortest edge on shortest path = " << dis[d].second << endl;
    return dis[d].second;
}

int main(){
	int n, m, s, d;
	vector<vector<int>> edges;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({x, y, w});
	}
	cin >> s >> d;
	shortestEdge(n, edges, s, d);
}