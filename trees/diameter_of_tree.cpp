#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> G[N];
int vis[N];
int w, mx;

void dfs(int u, int d)
{
    vis[u] = 1;
    if(d > mx)
    {
        mx = d;
        w = u;
    }  

    for(auto v: G[u])
        if(!vis[v])
            dfs(v, d+1);
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

    // random root
    dfs(2, 0);
    cout << "u: " << w << endl;
    memset(vis, 0, sizeof(vis));
    mx = 0;
    dfs(w, 0);
    cout << "v: " << w << endl;
    cout << mx << endl;
}