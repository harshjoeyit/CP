/*
Bellman Ford's Algorithm:

Bellman Ford's algorithm is used to find the shortest paths from the 
source vertex to all other vertices in a weighted graph. 
It depends on the following concept: Shortest path 
contains at most n-1 edges, because the shortest path couldn't have a cycle.

In the beginning all vertices have a distance of "Infinity", but only 
the distance of the source vertex = , then update all the connected 
vertices with the new distances (source vertex distance + edge weights), 
then apply the same concept for the new vertices with new distances and so on

Optimized version is disjktra - O(V^2) , with min priority queue, O(V + Elog(V))
*/

#include<bits/stdc++.h>
using namespace std;

#define SIZE 100000 + 1

vector <pair<int, int> > v[SIZE];   
vector<int> dist(SIZE, INT_MAX);                    // set the vertices distances as infinity

vector<int> vis(SIZE);

void dijkstra()
{
                                                
    dist[1] = 0;
    multiset <pair<int, int> > s;                   // multiset do the job as a min-priority queue, complexity same, sorted in increasing order 

    s.insert({0 , 1});                              // insert the source node with distance = 0

    while(!s.empty())
    {

        pair <int , int> p = *s.begin();            // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; 

        if(vis[x]) 
        continue;                                   // check if the popped vertex is visited before
            
        vis[x] = true;

        for(int i = 0; i < v[x].size(); i++)
        {
            int w = v[x][i].first;                  // each neighbour vertex
            int neighb = v[x][i].second;

            if(dist[x] + w < dist[neighb])
            {                                       // check if the next vertex distance could be minimized
                dist[neighb] = dist[x] + w;
                s.insert({dist[neighb],  neighb});            // insert the next vertex with the updated distance
            }
        }
    }
}


int main()
{
    int nodes, edges, x, y;
    int weight;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        v[x].push_back(make_pair(weight, y));
        v[y].push_back(make_pair(weight, x));
    }

    dijkstra();

    for(int i = 1; i <= nodes; i++)
        cout << "dist of "<< i << " from " << 1 << " = " << dist[i] << endl; 

}