#include<bits/stdc++.h> 
using namespace std; 

#define ll long long int
#define fi first
#define se second 
  
ll dp[MAX];
ll value[MAX],wt[MAX],depth[MAX],fiocc[MAX];
ll total;
vector<ll>v[MAX];
vector<ll>values;
ll lookup[MAX][20];   
  
// Time Complexity:
// O(q*sqrt(q)+n*sqrt(q))

void dfs2(ll i,ll p,ll d)
{
    fiocc[i]=values.size();
    depth[i]=d;
    for(ll u:v[i])if(u!=p)
    {
        values.push_back(i);
        dfs2(u,i,d+1);
    }
    values.push_back(i);
}

void pre()
{
    dfs2(1,-1,0);
    ll n=values.size();
    for(ll i=0;i<values.size();i++)
        lookup[i][0] = values[i];

    for(ll i=1;i<20;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(lookup[j][i-1]==-1 || lookup[j+(1<<(i-1))][i-1]==-1)
                continue;
            if(depth[lookup[j][i-1]]<depth[lookup[j+(1<<(i-1))][i-1]]) 
                lookup[j][i] = lookup[j][i-1];
            else 
                lookup[j][i] = lookup[j+(1<<(i-1))][i-1];
        }
    }
}

ll getlca(ll a,ll b)
{
    ll x=fiocc[a];
    ll y=fiocc[b];

    if(x>y)swap(x,y);
    ll d=log2(y-x+1);

    if(depth[lookup[x][d]] < depth[lookup[y-(1<<d)+1][d]])  
        return lookup[x][d];

    return lookup[y-(1<<d)+1][d];
}

ll getdis(ll a,ll b)
{
    ll x = getlca(a,b);
    return depth[a]+depth[b]-2*depth[x];
}

ll dfs(ll i,ll p)
{
    ll ans=0,ans1=0;
    for(ll u:v[i])
    {
        if(u==p)
            continue;
        ll x=dfs(u,i);
        ans+=x;
        ans1+=value[u];
    }
    ans+=ans1;
    ans1+=wt[i];
    value[i]=ans1;
    return ans;
}

void dfs1(ll i,ll p)
{
    if(p!=-1){
        ll x=dp[p];
        x+=total-2*value[i];
        dp[i]=x;
    }
    for(ll u:v[i])
        if(u!=p)
            dfs1(u,i);
}

void update()
{
    dp[1]=dfs(1,-1);
    total=value[1];
    dfs1(1,-1);
}


int main()
{
    ll a,b;
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>wt[i];
    for(ll i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(lookup,-1,sizeof(lookup));
    pre();
    update();
    ll c;
    ll t=sqrt(q);
    
    for(ll i=0;i<q;i+=t)
    {
        map<ll,ll>query;
        
        for(ll j=i;j<min(q,i+t);j++)
        {
            cin>>a>>b;
            if(a==1)
            {
                cin>>c;
                query[b]=c;
            }
            else 
            {
                ll ans=dp[b];
                for(pll u:query)
                {
                    ll x=getdis(b,u.fi);
                    ans-=x*wt[u.fi];
                    ans+=x*u.se;
                }
                cout<<ans<<'\n';
            }
        }
        for(pll u:query)
            wt[u.fi]=u.se;
            update();
    }
}
