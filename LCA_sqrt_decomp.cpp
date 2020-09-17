// LCA using Square root decompostion  

#include <bits/stdc++.h> 
using namespace std; 
#define MAXN 1001
  
vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN];
int jump_parent[MAXN];
int block_sz; 

int LCANaive(int u,int v) 
{ 
    if (u == v)  return u; 
    if (depth[u] > depth[v]) 
        swap(u,v); 
    v = parent[v];          // 1 jump
    return LCANaive(u,v); 
} 

// precomputation
void dfs(int u, int p)
{
    depth[u] = depth[p]+1;
    parent[u] = p;
    
    if(depth[u] % block_sz == 0)
        jump_parent[u] = parent[u];
    else
        jump_parent[u] = jump_parent[p];

    for(auto v: tree[u])
        if(v != p)
            dfs(v, u);
}


int LCASqrt(int u, int v)
{
    while(jump_parent[u] != jump_parent[v])
    {
        if(depth[u] > depth[v])
            swap(u, v);
        v = jump_parent[v];     // block_sz jump
    }

    return LCANaive(u, v);
}


int main()
{
    int n, h, q;
    cin >> n >> h >> q;
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    block_sz = sqrt(h);         // height
    depth[0] = -1; 
    dfs(1, 0);

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << "LCA: "<< LCASqrt(x, y) << endl;
    }
}

