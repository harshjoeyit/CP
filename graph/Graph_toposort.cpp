#include<bits/stdc++.h>
using namespace std;

#define ll                    long long int
#define ld                    long double
#define mid(s,e)              (s+(e-s)/2)
#define MOD                   1000000007
#define F                     first
#define S                     second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll, ll>
#define pii                   pair<int,int>


vi toposort2;

void DFS_toposort(int u, vi G[], vi &vis)
{
    vis[u] = true;
    for(auto &v: G[u])
    {
        if(!vis[v])
            DFS_toposort(v, G, vis);
    }
    toposort2.push_back(u);
}
    
vi topo_sort(vi G[], vi &indegree, int n)
{
    queue<int> q;
    vi topo;

    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while( ! q.empty())
    {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);

        for(auto &v: G[u])
        {
            --indegree[v];
            if(indegree[v] == 0)
                q.push(v); 
        }
    }
    return topo;
}


int main()
{
    int n, m, x, y;
    cin >> n >> m;

    vi G[n+1];
    vi indegree(n+1, 0);

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].pb(y);
        ++indegree[y];
    }

    // Graph should have no cycles
    vi topo_sorted = topo_sort(G, indegree, n);
    for(auto &x: topo_sorted)
        cout << x << " ";
    cout << endl;

    vi vis(n+1, 0);
    DFS_toposort(1, G, vis);
    auto it = toposort2.end()-1;
    do
    {       
        cout << *it << " ";
        it--;
    }while(it != toposort2.begin());
    cout << *it << endl;
}