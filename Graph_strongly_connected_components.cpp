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
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>


void DFS(vi G[], int u, vector<bool> &vis)
{
    vis[u] = true;
    cout << u << " ";

    for(auto &v: G[u])
        if(! vis[v])
            DFS(G, v, vis);
}


void fillOrder(vi G[], int u, vector<bool> &vis, stack<int> &stck)
{
    vis[u] = true;

    for(auto &v: G[u])
        if(!vis[v])
            fillOrder(G, v, vis, stck);;

    // All vertices reachable from v are processed by now, push v 
    stck.push(u);
}


void disp(vi G[], int n)
{
    for(int i = 1; i <= n; i++)
    {    
        cout << i << "---> ";
        for(auto &v: G[i])
            cout << v << " ";
        cout << endl;
    } 
}


void printSCCs(vi G[], int n)
{
    stack<int> stck;

    vector<bool> vis(n+1);
    for(int i = 1; i <= n; i++)
        vis[i] = false;

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            fillOrder(G, i, vis, stck);

    vi g[n+1];

    for(int i = 1; i <= n; i++)
        for(auto v: G[i])
            g[v].push_back(i);

    //disp(g, n);

    for(int i = 1; i <= n; i++)
        vis[i] = false;

    while( ! stck.empty())
    {
        int v = stck.top();
        stck.pop();

        if( !vis[v])
        {
            DFS(g, v, vis);
            cout << endl;
        }
    }
}



int main()
{
    int n, m, x, y;
    cin >> n >> m;

    vi G[n+1];

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].pb(y);         // directed 
        // G[y].pb(x);
    }

    printSCCs(G, n);

}