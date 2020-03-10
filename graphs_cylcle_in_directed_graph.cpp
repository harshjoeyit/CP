#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
int recStack[100005];
int vis[100005];
int n, m;

bool cycle_in_directed_graph(int u)
{
    vis[u] = true;
    recStack[u] = true;
    for(auto v: G[u])
    {
        if( !vis[v] && cycle_in_directed_graph(v))
            return true;
        else if(recStack[v])      
            return true;
    }   

    recStack[u] = false;
    return false;
}

// if the directed graph is not connected then there are components
bool find_cycle()
{
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            if(cycle_in_directed_graph(i))
                return true;
    return false;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    cout << find_cycle() << endl;
}