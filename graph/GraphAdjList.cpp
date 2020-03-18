#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int> G[], int u, vector<int> &visited)
{
    queue<int> q;

    q.push(u);
    visited[u] = 1;

    while( ! q.empty())
    {
        u = q.front();
        q.pop();
        cout << u << " ";

        for(int i = 0; i < G[u].size(); i++)
        {
            if( ! visited[G[u][i]])
            {
                q.push(G[u][i]);
                visited[G[u][i]] = 1;
            }
        }
    } 
}

void BFSTraversal(vector<int> G[], int N)
{
    vector<int> visited(N+1, 0);

    printf("BFS: ");
    for(int i = 1; i <= N; i++)
        if(visited[i] == 0)
            BFS(G, i, visited);
}



int main()
{
    vector <int> adj[10];
    int x, y, nodes, edges;
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges

    for(int i = 0;i < edges;++i)
    {
            cin >> x >> y;
        adj[x].push_back(y);        //Directed Graph
     }

     // nodes 1 - n
    for(int i = 1;i <= nodes;++i)
    {   
        cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj[i].size();++j)
        {
            if(j == adj[i].size() - 1)
                cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
        }
    }
    cout << endl;

    BFSTraversal(adj, nodes);
    cout << endl;

    return 0;
}