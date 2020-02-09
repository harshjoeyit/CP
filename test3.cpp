#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> G[100005];
vector<int> val(100005);


int dfs(int u)
{
    cout << u << endl;
    int s = 0;
    for(auto &v: G[u])
        s += val[v] * val[v] + dfs(v);
    return s;
}

signed main()
{
    int n, x, y;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> val[i];
    
    for(int i = 0; i < n; i++)
        cout << val[i] << " ";
    cout << endl;    

    for(int i = 1; i <= n-1; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }

    int q, t, u, v;
    cin >> q;

    while(q--)
    {
        cin >> t;
        
        if(t == 1)
        {
            cin >> u >> v;
            val[u] = v;
        }
        else
        {
            cin >> u;
            cout << val[u] * val[u] + dfs(u) << endl;
        }
    }
}