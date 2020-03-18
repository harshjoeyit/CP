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


void priority_traversal(vector<int> G[], int n)
{
    priority_queue < int, vector<int>, greater<int> >  pq;
    vector<bool> visited(n+1);

    pq.push(1);
    visited[1] = true;

    while( !pq.empty())
    {
        int u = pq.top();
        pq.pop();
        cout << u << " ";

        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(! visited[v])
            {
                pq.push(v);
                visited[v] = true;
            }
        }
    }
}

    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, x, y;
    cin >> n >> m;

    vector<int> G[n+1];

    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    priority_traversal(G, n);
    cout << endl;
}