#include<bits/stdc++.h>
using namespace std;

vector<int> G[200];
vector<bool> vis(200);
vector<int> col(200);

// a graph with the cycle of odd length is not a bipartite graph

// IMP NOTE: a disconnected graph is bipartite if all the connected components are bipartite 

bool bip_dfs(int u, int c) {
    vis[u] = true;
    col[u] = c;

    for(auto v: G[u]) {
        if(vis[v] == 0) {
            if(bip_dfs(v, c ^ 1) == false)
                return false;
        } else if(col[u] == col[v]) {
            return false;
        }
    }
    
    return true;
}


// Checking for adjacency matrix  

bool check(int G[][MAX], int V, int src) {
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
  
    colorArr[src] = 1; 
  
    queue <int> q; 
    q.push(src); 

    while (!q.empty()) { 

        int u = q.front(); 
        q.pop(); 
  
        if (G[u][u] == 1) 
        return false;  
  
        for (int v = 0; v < V; ++v) { 
            
            if (G[u][v] && colorArr[v] == -1) { 
                
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    return true; 
}


int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vis.assign(200, false);
    if(bip_dfs(1, 1))   
        cout << "bipartite\n";
    else
        cout << "not bipartite\n";
}