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

const int N = 100005;
int par[N];


ll find(ll u)
{
    if(par[u] == u)
    return u;
    
    return par[u] = find(par[u]);
}


void Union(ll u, ll v)
{
    if(find(u) == find(v))
    return ;
    
    if(par[find(v)] < par[find(u)])         // by default the parent is the bigger number 
        par[find(v)] = find(u);
    else
        par[find(u)] = find(v);
}


int main()
{
    ll n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        par[i] = i;
    
    while(m--)
    {
        ll u,v;
        cin >> u >> v;
        Union(u,v);
    }      
    
    ll q;
    cin >> q;

    while(q--)
    {
        ll u,v;
        cin >> u >> v;

        ll frnd1 = find(u);         // friend with the largest value 
        ll frnd2 = find(v);
        
        if(frnd1 > frnd2)
            cout << u << endl;
        
        else if(frnd2 > frnd1)
            cout << v << endl;

        else
            cout << "TIE" << endl;
    
    }
}