// deleting some edges so that at most k edges remain
// and the shortest path of maximum vertices is preserved 
// logic run dijkstra for k+1 vertices only - as edges are k





// #include<bits/stdc++.h>
// using namespace std;

// #define int long long int

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


#include <bits/stdc++.h>
using namespace std;
 
const int N = 3E5 + 50;
 
int n, m, K, vis[N];
long long dis[N];

struct ed 
{
	int v, id; long long c;

	ed(int v, int id, long long c) : v(v), id(id), c(c) {}

    // defining the less than operator fot the structure
	bool operator < (const ed &a) const 
    {
		return a.c < c;
	}
};


vector<int> ans;
vector<ed> g[N];
priority_queue<ed> las;
 
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1, u, v, c; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		g[u].push_back(ed(v, i, c));
		g[v].push_back(ed(u, i, c));
	}
	vis[1] = 1;


	for(auto s : g[1]) 
        las.push(s);
	K = min(K, n - 1);

	for(int i = 1; i <= K; ++i)             // distra running 
    {
		ed s = las.top(); 
        las.pop();
		
        for(; vis[s.v]; s = las.top(), las.pop()) 
        {
			if(las.empty()) 
                break;
		}
		if(vis[s.v])
            break;
        
        ans.push_back(s.id);
		vis[s.v] = 1, 
        dis[s.v] = s.c;

		// printf("u = %d dis = %lld\n", )

		for(auto u : g[s.v]) 
            las.push(ed(u.v, u.id, dis[s.v] + u.c));
        
	}

    
	printf("%d\n", (int) ans.size());
	for(auto u : ans) printf("%d ", u);
	return 0;
}