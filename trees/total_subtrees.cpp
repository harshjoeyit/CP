#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> G[N];
int subTreeSize[N];

int dfs(int u, int p)
{
    for(auto v: G[u])
        if(v != p)
            subTreeSize[u] += dfs(v, u);
            
    return subTreeSize[u] + 1;
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

    dfs(1, 1);

    for(int i = 1; i <= n; i++)
        cout << subTreeSize[i] << " ";
    cout << endl;
}