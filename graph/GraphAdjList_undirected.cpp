#include<bits/stdc++.h>
using namespace std;

// for level of nodes in the tree 
void BFS(vector<int> G[], int u, vector<int> &visited, vector<int> &level)
{
    queue<int> q;

    q.push(u);
    visited[u] = 1;
    level[u] = 1;             // root is at level 

    while( ! q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = 0; i < G[u].size(); i++)
        {
            if( ! visited[G[u][i]])
            {
                q.push(G[u][i]);
                visited[G[u][i]] = 1;
                level[G[u][i]] = level[u] + 1;
            }
        }
    } 
}
// for level of nodes in a treee
void BFSTraversal(vector<int> G[], int N, vector<int> &level)
{
    vector<int> visited(N+1, 0);
    BFS(G, 1, visited, level);
}


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

void DFS(vector<int> G[], int u, vector<int> &visited)
{
    stack<int> s;

    s.push(u);
    visited[u] = 1;

    while( ! s.empty())
    {
        u = s.top();
        s.pop();
        cout << u << " ";

        for(int i = 0; i < G[u].size(); i++)
        {
            if( ! visited[G[u][i]])
            {
                s.push(G[u][i]);                // or emplace 
                visited[G[u][i]] = 1;
            }
        }
    } 
}

void DFSTraversal(vector<int> G[], int N)
{
    vector<int> visited(N+1, 0);

    printf("DFS: ");
    for(int i = 1; i <= N; i++)
        if(visited[i] == 0)
            DFS(G, i, visited);
}


void display(vector<int> adj[], int N)
{
     // nodes 1 - n
    for(int i = 1;i <= N;++i)
    {   
        cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj[i].size();++j)
        {
            if(j == adj[i].size() - 1)
                cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " ";
        }
        if(adj[i].size() == 0)
            cout << endl;
    }
    cout << endl;
}



int main()
{
    
    int x, y, nodes, edges;
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges

    vector<int> G[nodes + 1];

    for(int i = 0;i < edges;++i)
    {
            cin >> x >> y;
        G[x].push_back(y);        //Undirected Graph
        G[y].push_back(x);        
     }

    // display(adj);

    //BFSTraversal(G, nodes);
    //cout << endl;

    DFSTraversal(G, nodes);

    return 0;
}