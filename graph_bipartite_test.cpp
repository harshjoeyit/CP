#include<bits/stdc++.h>
using namespace std;

vector<int> G[200];
vector<bool> vis(200);
vector<int> col(200);

// a graph with the cycle of odd length is always a bipartite graph

bool bip_dfs(int u, int c)
{
    vis[u] = true;
    col[u] = c;
    cout << u << " - " << c << endl;

    for(auto v: G[u])
    {
        if(vis[v] == 0)
        {
            if(bip_dfs(v, c ^ 1) == false)
                return false;
        }
        else if(col[u] == col[v])
            return false;
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