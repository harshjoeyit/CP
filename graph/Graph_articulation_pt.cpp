#include<bits/stdc++.h>
using namespace std;

#define NIL -1

const int V = 1000;
vector<int> G[V+1];

void bridges(int u, bool visited[], int disc[], int low[], int parent[])
{

    static int time = 0;
    int children = 0;
    visited[u] = true;
 
    disc[u] = low[u] = ++time;

    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!visited[v])
        {
            children ++;
            parent[v] = u;
            bridges(v, visited, disc, low, parent);
 
            low[u] = min(low[u], low[v]);              

            if(low[v] > disc[u])
                cout << u << " " << v << endl;
        }
        
        else if(v != parent[u])
        {
            low[u] = min(low[u], disc[v]);         
        }
    }   
}




void APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time = 0;

    // counting children in DFS Tree
    int children = 0;

    visited[u] = true;

    // discovery time 
    disc[u] = low[u] = ++time;

    // go to all the vertices adjacent to this
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];

        if(!visited[v])
        {
            children ++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            //Check if the subtare global variables made on heapree rooted with v has a connection to 
			// one of the ancestors of u 
            low[u] = min(low[u], low[v]);               // the vertex with lowest discovery time, that can be reached from u 
            // while backtracking , if v has some child that has the min low - i.e. the vertex with lowest time that can be reached form v  


            // articulation point if

            //1. u is root of DFS and has two or more children
            if(parent[u] == NIL && children > 1)
                ap[u] = true;

            //2. If u is not root and low value of one of its child is more 
			// than discovery value of u. 

            if(parent[u] != NIL && low[v] >= disc[u])
                ap[u] = true;
        }
        // if we visit an already visited node then 
        else if(v != parent[u])
        {
            low[u] = min(low[u], disc[v]);          // if there is an adjacent vertex that has disc time 
                                                    //less than low time of our vertex, that means we have path to it 
        }
    }   
}


int main()
{
    int n, m, x, y;
    bool *visited = new bool[V+1];
    int *disc = new int[V+1];
    int *low = new int[V+1];
    int *parent = new int[V+1];
    bool *ap = new bool[V+1];

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);  
        G[y].push_back(x);
    }

    for(int i = 1; i <= V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    cout << "articulation pts: ";
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            APUtil(i, visited, disc, low, parent, ap);

    for(int i = 1; i <= n; i++)
        if(ap[i])
            cout << i << " ";

    for(int i = 1; i <= V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        disc[i] = 0;
        low[i] = 0;
    }

    // in a tree all the edges are the bridges as there is one and only one unique path
    cout << endl << "bridges - \n";
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            bridges(i, visited, disc, low, parent);
}