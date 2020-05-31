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

// graph is connected with bidirectional roads 
// a, b are cities with the fair going on
// find number of pairs of vertices (x, y) such that going from x to y or y to x
// you have to pass through a and b both 

// approach 
// DFS on a - mark the vertices that can be visited with a
// DFS on b - mark the vertices that can be visited with b,
//             if the vertex is marked a then mark it -1 

// count the vertices of a && b , ans = a*b
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, a, b, x, y;                  
        cin >> n >> m >> a >> b;
        
        vi G[n+1];
        vi vec(n+1);                    // vec is for marking the vertex                
        vector<bool> vis(n+1);

        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            G[x].pb(y);
            G[y].pb(x);
        }

        for(int i = 0; i < n; i++)
        {
            vec[i] = 0;
            vis[i] = false;
        }

        //DFS on a
        stack<int> s;
        s.push(a);
        vis[a] = true;

        while(! s.empty())
        {
            int u = s.top();
            s.pop();

            for(int v: G[u])
            {
                if(!vis[v])
                {
                    if(v == b)              // we dont want to go past b, so no further DFS on b
                        continue;

                    s.push(v);
                    vis[v] = true;
                    vec[v] = a;             // mark vertex with a 
                }
            }
        }

        for(int i = 1; i <= n; i++)
            vis[i] = false;                 // reset 

        while(!s.empty())
            s.pop();                    // make sure empty 

        // DFS on b
        s.push(b);
        vis[b] = true;

        while(! s.empty())
        {
            int u = s.top();
            s.pop();
            
            for(int v: G[u])
            {
                if(!vis[v])
                {
                    if(v == a)                  // we dont want to go through a 
                        continue;

                    s.push(v);      
                    vis[v] = true;
                    if(vec[v] == a)             // if marked a then -1
                        vec[v] = -1;
                    else
                        vec[v] = b;                // else mark b
                }
            }
        }

        // count
        ll A = 0, B = 0;
        for(int i = 0; i <= n; i++)
        {
            if(vec[i] == a)
                ++A;
            else if(vec[i] == b)
                ++B;
        }

        cout << A * B << endl;
    }
    
}