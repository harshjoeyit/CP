#include<bits/stdc++.h>
using namespace std;

#define ll                    long long int
#define ld                    long double
#define mid(s,e)              (s+(e-s)/2)
#define MOD                   1000000007
#define F                     first
#define S                     second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>

/*
As discussed in Bellman Ford algorithm, for a given source,
 it first calculates the
 shortest distances which have at-most one edge in the path. 
Then, it calculates shortest paths with at-nost 2 edges, and so on.
 After the i-th iteration of outer loop, 
the shortest paths with at most i edges are calculated. 
There can be maximum |V| – 1 edges in any simple path, 
that is why the outer loop runs |v| – 1 times.
 If there is a negative weight cycle,
 then one more iteration would give a shorted path.
*/


/*The Bellman-Ford algorithm works on directed graphs. 
To make it work with undirected graphs we must make each
 undirected edge into two directed edges (one in each direction
) with the same weights as the original undirected edge. Now any 
negative weight undirected cycle is transformed into a negative 
weight directed cycle, and hence would be detected. In any
 negative weight edge is transformed in a negative weight cycle o
f length two! Thus Bellman-Ford will always detect a negative cycle if 
there is any negative weight edge*/


const int INF = 10000007;
const int N = 100; 
vector<pair<int, pii>> Edge;
vi dis(N, INF);


void printArr(int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 1; i <= n; ++i) 
		printf("%d \t%d\n", i, dis[i]); 
} 

void BellmanFord(int src, int n, int m)
{
    dis[src] = 0;

    // relax n-1 times
    for(int i = 1; i <= n-1; i++)               // nodes - 1 times
    {
        for(int j = 0; j < m; j++)              // for m edges
        {
            int u = Edge[j].second.first;
            int v = Edge[j].second.second;
            int w = Edge[j].first;

            if(dis[u] != INF && dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
        }
    }
    // min dis found if there is no negetive weight cycles 

    // check -ve weight cycle 
    for(int i = 0; i < m; i++)
    {
        int u = Edge[i].second.first;
        int v = Edge[i].second.second;
        int w = Edge[i].first;

        if(dis[u] != INF && dis[u] + w < dis[v])
        {
            cout <<  "-ve cylce\n";
            return;
        }
    }

    printArr(n);
}

int main()
{
    
    int nodes, edges, x, y;
    int weight;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        Edge.pb(mp(weight, mp(x,y)));
    }
    
    BellmanFord(1, nodes, edges);
}