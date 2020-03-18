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

    
vi topo_sort(vi G[], vi &indegree, int n)
{
    set<int> s;
    vi topo;

    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            s.insert(i);

    while( ! s.empty())
    {
        auto u = *s.begin();
        s.erase(s.begin());
        topo.pb(u);

        sort(G[u].begin(), G[u].end());
        for(auto &v: G[u])
        {
            --indegree[v];
            if(indegree[v] == 0)
                s.insert(v);   
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


}