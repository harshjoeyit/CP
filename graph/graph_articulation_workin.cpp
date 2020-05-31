#include <iostream>
#include <vector>
using namespace std;


void dfs(int u,int *dis,int *low,vector<int> *a,int *par,bool *vis,int *time1,bool *b)
{
    vis[u]=true;
	  (*time1)++;
    
	dis[u]=low[u]=*time1;
    int child=0;
    
	for(auto v:a[u]){
        if(!vis[v])
		{
            child++;
            par[v]=u;
          
		    dfs(v,dis,low,a,par,vis,time1,b);
          
		    low[u]=min(low[u],low[v]);
          
		    if(par[u]==-1 && child >1)
                b[u]=1;
          
		    else if(par[u]!= -1 && low[v]>=dis[u])
                b[u]=1;
        }
        
		else if(par[u]!=v){
        
		    low[u]=min(low[u],dis[v]);
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,k,i,x,y,time1;
	    cin >> n >> m >> k;
	    vector<int> a[n];
	    int par[n];
	
	    for(i=0;i<m;i++)
		{
	        cin>>x>>y;
	        a[x].push_back(y);
	        a[y].push_back(x);
	    }
	    
		bool vis[n]={false};
	    
		for(i=0;i<n;i++)
		{
	        par[i]=-1;
	    }
	    
		time1=0;
	    
		int dis[n],low[n];
	    
		bool b[n]={0};
	    
		dfs(0,dis,low,a,par,vis,&time1,b);
	    
		time1=0;
	    
		for(auto i:b)
		{
	        if(i)
		    {
                time1++;
            }
	    }
	    
		cout<<time1*k<<endl;
	    
	}
	return 0;
}
