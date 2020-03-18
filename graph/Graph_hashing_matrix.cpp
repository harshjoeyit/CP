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

    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, si, sj, di, dj, r, a, b, k = 1;
    cin >> si >> sj >> di >> dj >> n;
    
    map<pii, int> m;
    vector<bool> vis(100005);
    vi dis(100005);
    vis.assign(100005, false);
    dis.assign(100005, -1);
    

    for(int i = 0; i < n; i++)
    {
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++)
        {
            if(m[{r, j}] == 0)
                m[{r, j}] = k++;
        }
    }

    vi x = {1,1,1,0,-1,-1,-1,0};
    vi y = {-1,0,1,1,1,0,-1,-1};
    queue<pii> q;
    pii u = {si, sj};
    q.push(u);
    vis[m[u]] = 1;
    dis[m[u]] = 0;

    while(! q.empty())
    {
        u = q.front();
        q.pop();

        if((u.F == di) and (u.S == dj))
            break;
    
        for(int i = 0; i < x.size(); i++)
        {
            pii v = {u.F + x[i], u.S + y[i]};
            auto iter = m.find(v);

            if((iter != m.end())  && (vis[m[v]] == 0))
            {
                vis[m[v]] = 1;
                dis[m[v]] = dis[m[u]] + 1;
                q.push(v);
            }
        }
    }

    cout << dis[m[{di, dj}]] << endl;
}