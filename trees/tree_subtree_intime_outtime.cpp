#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> G[N], intime(N), outtime(N), vis(N);
int t = 0;

// intime and outtime for a tree - find if a node is in the subtree of another 
void dfs(int u)
{
    vis[u] = 1;
    intime[u] = ++t;

    for(auto v: G[u])
        if(!vis[v])
            dfs(v);

    outtime[u] = ++t;
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

    // root
    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << "i: " << intime[i] << " o: " << outtime[i] << endl; 
}