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
    
    int n;
    cin >> n;

    vi G[n+1];
    vi a(n+1);
    vi dis(n+1);
    vector<bool> vis(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i]; 
        vis[i] = false;
        dis[i] = -1;

        if(i - a[i] >= 1)                       // a number given as a vertex has at most 2 edges - one to number i - a[i] 
            G[i - a[i]].pb(i);

        if(i + a[i] <= n)                       // and another to i+ a[i] provided they are in the range 
            G[i + a[i]].pb(i);
    }

    set<int> s;
    for(int u = 1; u <= n; u++)
    {
        for(int v : G[u])
        {
            if((a[u] + a[v]) % 2)               // finding those vertces that can be visited in single step, and if even number is connected directly to an odd number 
            {
                s.insert(v);
            }
        }
    }

    queue<int> q;                   // all other vertices will be visited from the 4
                                    // vertices that are in the set 
    for(int i: s)                   // and distances add on at each step 
    {
        q.push(i);
        dis[i] = 1;
        vis[i] = true;
    }

    while(! q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: G[u])
        {
            if(! vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;
}