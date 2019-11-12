#include<bits/stdc++.h>
using namespace std;

void display(vector<pair<int, int>> adj[], int N)
{
     // nodes 1 - n
    for(int i = 1;i <= N;++i)
    {   
        cout << i << ": ";
        for(int j = 0;j < adj[i].size();++j)
        {
            if(j == adj[i].size() - 1)
                cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")" << endl;
            else
                cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")" << " , ";
        }
        if(adj[i].size() == 0)
            cout << endl;
    }
    cout << endl;
}


void BFS_0_1(vector<pair<int, int>> G[], int N, int u)
{
    deque<int> dq;
    dq.push_back(u);
    
    vector<int> distance(N+1, INT_MAX);      // -1 for not connected 
    distance[u] = 0;

    while( ! dq.empty())
    {
        int v = dq.front();
        dq.pop_front();
        cout << v << endl;

        for(int i = 0; i < G[v].size(); i++)
        {

            /* if distance of neighbour of v from start node is 
            greater than sum of distance of v from start node and
            edge weight between v and its neighbour (distance 
            between v and its neighbour of v) ,then change it */
            int neighb = G[v][i].first;
            int wt = G[v][i].second;

            if(distance[neighb] > distance[v] + wt)
            {
                distance[neighb] = distance[v] + wt; 
                
                if(wt == 0)
                    dq.push_front(neighb);
                else
                    dq.push_back(neighb);
            }            
        }
    }

    cout << "from " << u << endl;
    for(int i = 1; i <= N; i++)
        cout << "dis " << i << " = " << distance[i] << endl;
}


int main()
{
    // weighted undirected graph
    int x, y, nodes, edges, wt;
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges
    
    vector<pair<int, int>> G[nodes+1];  //1 - N
            // vertex, weight 

    for(int i = 0; i < edges; ++i)
    {
            cin >> x >> y >> wt;
        G[x].push_back({y, wt});        //Undirected Graph
        G[y].push_back({x, wt});        
    }

    display(G, nodes);
    BFS_0_1(G, nodes, 1);

    return 0;
}