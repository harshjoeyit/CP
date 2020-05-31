/* for finding strongly connected components. 
It follows that any edge (C,C′) 
in condensation graph comes 
from a component with a 
larger value of tout to 
component with a smaller value. 

the algorithm's scheme generates 
strongly connected components by
decreasing order of their exit times
i.e.
it generates components - 
vertices of condensation graph(acyclic graph with vertices as SCCs) - 
in topological sort order.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 100005; 
vector<int> g[N], gr[N];
vector<bool> vis;
vector<int> order, component;

template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

void dfs1(int u)
{
    vis[u] = true;
    for(auto v: g[u])
        if( !vis[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u)
{
    vis[u] = true;
    component.push_back(u);
    for(auto v: gr[u])
        if( !vis[v])
            dfs2(v);
}


int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);     // reverse graph
    }

    vis.assign(n+1, false);
    for(int i = 1; i <= n; i++)  
        if( !vis[i])
            dfs1(i);
    
    vis.assign(n+1, false);
    for(int i = 1; i <= n; i++)
    {
        int u = order[n-i];
        if( !vis[u])
        {
            dfs2(u);
            print(component);
            component.clear();
        }
    }
}
