#include<bits/stdc++.h>
using namespace std;


// some of the nodes (m) of the tree have diamonds placed on them, find the minimum distance between the diamond nodes

#define int long long int
const int N = 1000005;
int vis[N];
int dia[N];
int dis[N];
int par[N];
vector<int> G[N];
int m;

// approach: multisource bfs

int bfs()
{
    int level = 1;
    queue<int> q;
    for(int i = 0; i < m; i++)
    {
        int u = dia[i];
        q.push(u);
        vis[u] = 1;
        dis[u] = 0;
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //cout << u << " " << endl;
        for(auto v: G[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
            else if(v != par[u])
            {
                //cout << u <<"-" << v << endl;
                return (dis[v] + dis[u] + 1);
            }
        }
    }
    return 0;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--)
    {
        int n;
        cin >> n >> m;
        
        for(int i = 0; i < n-1; i++)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for(int i = 0; i < m; i++)
            cin >> dia[i];
        
        cout << bfs() << endl;

        // for(int i = 1; i <= n; i++)
        //     cout << dis[i] << " ";
        // cout << endl;
    }
}