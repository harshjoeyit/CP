//..................LCA - O(1)....................

#include<bits/stdc++.h> 
using namespace std; 

const int sz = 5e5+5;

vector<int> G[sz];    
vector<int> euler;            
int fiocc[sz];     	
int depth[sz]; 
int lookup[sz][18];  
int dis[sz];


void dfs(int u, int p, int dep) 
{ 
    fiocc[u] = euler.size();
    depth[u] = dep;
    for(int v: G[u])
		if(v != p)
		{
        	euler.push_back(u);
        	dfs(v, u, dep+1);
    	}
    euler.push_back(u);
}

void buildSparseTable() 
{ 
    memset(lookup, -1, sizeof(lookup)); 
	dfs(1,-1,0);
	
    int n = euler.size();
    for(int i=0; i<n; i++)
        lookup[i][0] = euler[i];

    for(int i=1; i<20; i++)
    {
        for(int j=0; j<n; j++)
        {
			int x = lookup[j][i-1];
			int y = lookup[j+(1<<(i-1))][i-1];
            if(x == -1 || y == -1)
                continue;
            if(depth[x] < depth[y]) 
                lookup[j][i] = x;
            else 
                lookup[j][i] = y;
        }
    }
}


int LCA(int a, int b)
{
    int l = fiocc[a];
    int r = fiocc[b];
    if(l > r)
		swap(l, r);
    int d = log2(r-l+1);

	int x = lookup[l][d];
	int y = lookup[r-(1<<d)+1][d];
	
	if(depth[x] < depth[y])
		return x;
    return y;
}


void LCA_query(int q)
{
    cout << "enter x, y for LCA(x, y): \n"; 
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
}


void dfs1(int u, int p)
{
    for(auto v: G[u])
        if(v != p)
        {
            dis[v] = dis[u] + 1;
            dfs1(v, u);
        }
}


void dist_between(int q)
{
    cout << "enter x, y for dis(x, y): \n"; 
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        cout << (dis[a] + dis[b] - 2 * dis[lca]) << endl;
    }
}


int main(int argc, char const *argv[]) 
{ 
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y); 
    	G[y].push_back(x); 
    }
	
    buildSparseTable();
	// lca in O(1)
 	LCA_query(q);
    // finding distance between any two nodes in O(1)
   	dfs1(1, 0);
   	dist_between(q);
  
    return 0; 
} 
