
//..................LCA - O(1)....................

#include<bits/stdc++.h> 
using namespace std; 
#define sz 101 
  
vector < int > adj[sz];    
vector < int > euler;      
vector < int > depthArr;    
  
int FAI[sz];     // stores first appearence index of every node 
int level[sz];   
int ptr;         // pointer to euler walk 
int dp[sz][18];  // sparse table 
int logn[sz];    // stores log values 
int p2[20];      // stores power of 2 



void buildSparseTable(int n) 
{ 
    memset(dp,-1,sizeof(dp)); 
  
    for (int i = 1; i < n; i++) 
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i; 
  
    // dp to fill sparse table 
    for (int l=1; l<15; l++) 
      for (int i=0; i<n; i++) 
        if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1) 
        {
            dp[i][l] = (depthArr[dp[i][l-1]] > depthArr[dp[i+p2[l-1]][l-1]]) ? dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
            //cout << i << "-" << p2[l] << " -> " << i << "-" << p2[l-1] << " + " << i+p2[l-1]<< "-" << endl;
        }
        else
             break; 
} 


int query(int l,int r) 
{ 
    int d = r-l; 
    int dx = logn[d]; 
    if (l == r) 
        return l; 
    
    //cout << l << "-" << r << " -> " << l << "-" << p2[dx] << " + " << r-p2[dx]<< "-" << r << endl;

    if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]) 
        return dp[r-p2[dx]][dx]; 
    else
        return dp[l][dx]; 
} 



// memoization so that time complexity can be reduced
void preprocess() 
{ 
    // memorizing powers of 2 
    p2[0] = 1; 
    for (int i=1; i<18; i++) 
        p2[i] = p2[i-1]*2; 
  
    // memorizing all log(n) values 
    int val = 1, ptr = 0; 
    for (int i=1; i<sz; i++) 
    { 
        logn[i] = ptr-1; 
        if (val==i) 
        { 
            val*=2; 
            logn[i] = ptr; 
            ptr++; 
        } 
    } 
} 


void dfs(int u, int p, int dep) 
{ 
    if (FAI[u] == -1) 
        FAI[u] = ptr; 
  
    level[u] = dep; 
    euler.push_back(u); 
    ptr++; 
  
    for (auto v : adj[u]) 
    { 
        if (v != p) 
        { 
            dfs(v , u, dep+1); 
            euler.push_back(u);         // push while backtracking
            ptr++; 
        } 
    } 
} 
  
// Create Level depthArray corresponding 
// to the Euler walk Array 
void makeArr() 
{ 
    for (auto x : euler) 
        depthArr.push_back(level[x]); 
} 
  
int LCA(int u,int v) 
{ 
    // trival case 
    if (u==v) 
       return u; 
  
    if (FAI[u] > FAI[v]) 
       swap(u,v); 
  
    // doing RMQ in the required range 
    int indx = query(FAI[u], FAI[v]);
    return euler[indx]; 
} 


void addEdge(int u,int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  


int main(int argc, char const *argv[]) 
{ 
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
  
    // performing required precalculations 
    preprocess(); 
  
    // doing the Euler walk 
    ptr = 0; 
    memset(FAI,-1,sizeof(FAI)); 
    dfs(1,0,0); 
  
    // creating depthArray corresponding to euler[] 
    makeArr(); 
  
    // building sparse table 
    buildSparseTable(depthArr.size()); 
    
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
  
    return 0; 
} 
 