// Sparse Matrix DP approach to find LCA of two nodes 

#include <bits/stdc++.h> 
using namespace std; 
#define MAXN 100000 
#define level 18 
  
vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN][level]; 

// O(n)
void dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    parent[u][0] = p;           // first parent 2^0th parent
    for(int v: tree[u])
    {
        if(v != p)
            dfs(v, u);
    }
}

// nlogn
// populating 2^ith parent for each node in O(nlogn)
void precomputeSparse(int n)
{
    for(int i = 1; i < level; i++)
    {
        for(int node = 1; node <= n; node++)
        {
            if(parent[node][i-1] != -1)       
                parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}

// log(n)
int LCA(int u, int v)
{
    if(depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    // depth[v] > depth[u]
    // for every set bit condition is true;
    for(int i = 0; i < level; i++)
        if((diff >> i) & 1)             
            v = parent[v][i];   
    // v changes to its parent at i distance above the current level, 
    // finally it is at level of u

    if(u == v)
        return u;

    // checking the first LCA among all common parents 
    for(int i = level-1; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i];   
            v = parent[v][i]; 
        } 
    }

    // u, v are one node far from LCA 
    return parent[u][0];
}



int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    memset(parent,-1,sizeof(parent)); 
    dfs(1, 0);

    precomputeSparse(n);

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << "LCA: "<< LCA(x, y) << endl;
    }
}

