#include<bits/stdc++.h> 
using namespace std; 

#define int long long
const int mxN = 5e5+5;
const int MOD = 1e9+7;

vector<int> G[mxN];    
vector<int> euler;            
int fiocc[mxN];     	
int depth[mxN]; 
int lookup[mxN][18];  
int hq[mxN];
int cost[mxN];

inline int mul(int a,int b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    int c=a*b;
    c=(c+MOD)%MOD;
    return c;
}
inline int add(int a,int b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    int ans=(a+b);
    ans=(ans+MOD)%MOD;
    return ans;
}
int power(int a,int b,int c=0){
    int ans=1;
    while(b){
        if(b&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b=b/2;
    }
    return ans;
}


void dfs(int u, int p, int dep)  { 
    fiocc[u] = euler.size();
    depth[u] = dep;
    for(int v: G[u]) {
		if(v != p) {
        	euler.push_back(u);
        	dfs(v, u, dep+1);
    	}
    }
    euler.push_back(u);
}
void buildSparseTable() { 
    memset(lookup, -1, sizeof(lookup)); 
	dfs(1,-1,0);
	
    int n = euler.size();
    for(int i=0; i<n; i++)
        lookup[i][0] = euler[i];

    for(int i=1; i<20; i++) {
        for(int j=0; j<n; j++) {
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
int LCA(int a, int b) {
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

int count_divisors(int n) {
    if(n == 1)
        return 1;
    
    int cnt = 0;
    for(int i=1; i*i<=n; i++) {
        if(n%i == 0) {
            if(i == n/i)
                ++cnt;
            else 
                cnt +=2;            // for i, n/i
        }
    }
    return cnt;
}

void dfs1(int u, int p, int c) {
    hq[u] = mul(cost[u], c);
    c = hq[u];
    for(auto v: G[u])
        if(v != p)
            dfs1(v, u, c);
}
void query(int q) {
    // cout << "enter x, y for dis(x, y): \n"; 
    while(q--) {
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        // cout <<"lca: " << lca << endl;

        int hqab = mul(hq[a], hq[b]);
        hqab = mul(hqab, cost[lca]);
        int hqlca = mul(hq[lca], hq[lca]);
        hqlca = power(hqlca, MOD-2, MOD);

        int ans = mul(hqab, hqlca);
        // cout << "hq: " << ans << endl;
        // cout << "divs: ";
        cout << count_divisors(ans) << endl;
    }
}

void solve() {

    int n;
    cin >> n;   
    
    // empty all
    for(int i=1; i<mxN; i++) {
        G[i].clear();
    }
    euler.clear();
    memset(fiocc, 0, sizeof(fiocc));
    memset(depth, 0, sizeof(depth));
    memset(hq, 0, sizeof(hq));
    memset(cost, 0, sizeof(cost));
    memset(lookup, 0, sizeof(lookup));

    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y); 
    	G[y].push_back(x); 
    }
    
    buildSparseTable();
    
    // cout << "cost array\n";
    for(int i=1; i<=n; i++)
        cin >> cost[i];

    dfs1(1, 0, 1);
    
    int q;
    cin >> q;
    query(q);
}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
} 
