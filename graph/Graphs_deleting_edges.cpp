// deleting some edges so that at most k edges remain
// and the shortest path of maximum vertices is preserved 
// logic run dijkstra for k+1 vertices only - as edges are k


#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 3E5 + 50;
int n, m, K;

int dis[N], vis[N];
vector<int> ans;
vector<edge> g[N];
priority_queue<edge> pq;

struct edge  {
	int v, id, c;
	edge(int _v, int _id, int _c) : v(_v), id(_id), c(_c) {}
    	// defining the less than operator fot the structure
	bool operator < (const edge &a) const {
		return a.c < c;
	}
};
 
int main() {
	cin >> n >> m >> K;
	for(int i = 1, u, v, c; i <= m; i++) {
		cin >> u >> v >> c;
		g[u].push_back(edge(v, i, c));
		g[v].push_back(edge(u, i, c));
	}
	
	vis[1] = 1;
	for(auto s : g[1]) {
		pq.push(s);
	}
	K = min(K, n - 1);

	// dijkstra running 
	for(int i = 1; i <= K; ++i) {
		edge e = pq.top(); 
        	pq.pop();
		
        	for(; vis[e.v]; e = pq.top(), pq.pop()) {
			if(pq.empty()) {
				break;
			}
		}
		
		if(vis[e.v]) {
			break;
		}
	
        	ans.push_back(e.id);
		vis[e.v] = 1, 

        	dis[e.v] = e.c;
		for(auto u : g[e.v]) {
			pq.push(edge(u.v, u.id, dis[e.v] + u.c));
		}
	}

    
	cout << ans.size();
	for(auto u: ans) {
		cout << u << " ";
	}cout << endl;
}



// #include<bits/stdc++.h>
// using namespace std;

// #define int int int

// vector<pair<int, int>> G[3000005];
// bool vis[3000005];
// map<pair<int, int>, int> M;
// vector<int> ans;
// vector<int> dist(3000005);

// void dijkstra(int k)
// {
//     int cnt = 0;
//     multiset<pair<pair<int, int>, int>> s;
//     dist[1] = 0;
//     s.insert({{0, 1}, 1});

//     while(! s.empty() && cnt < k+1)
//     {
//         pair<pair<int, int>, int> p = *s.begin();
//         s.erase(s.begin());

//         int u = p.first.second;

//         if(vis[u])
//             continue;

//        // cout << "->" << u <<  endl;
//         vis[u] = 1;
//         ++cnt;
//         if(u != 1)
//         {
//             if(M[{u, p.second}])
//                 ans.push_back(M[{u, p.second}]);
//             else
//                 ans.push_back(M[{p.second, u}]);
//         }

//         for(auto &q: G[u])
//         {
//             int v = q.second;
//             int w = q.first;

//             if(dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 s.insert({{dist[v], v}, u});
//             }
//         }
//     }
// }




// signed main()
// {
//     int n, m, k, x, y, w, j = 1;
//     cin >> n >> m >> k;

//     for(int i = 0; i < m; i++)
//     {
//         cin >> x >> y >> w;
//         G[x].push_back({w, y});
//         G[y].push_back({w, x});
//         M[{x, y}] = j++;
//     }

//     dist.assign(n+1, 100000000000005);

//     if(k+1 > n) 
//         k = n-1;
//     dijkstra(k);

//     cout << ans.size() << endl;
//     //sort(ans.begin(), ans.end());
//     for(int &i: ans)
//         cout << i << " ";
//     cout << endl;
// }

