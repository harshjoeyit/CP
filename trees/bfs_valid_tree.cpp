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

vector<int> G[200010];
vector<bool> visited(200010);
vector<int> nxt(200010);                    // nxt array for which nodes have a preference over the other even when they are on the same level
                                            // their preference is decided by the parent at the same level that occur first - its children will occur first
vector<int> dis(200010);
vector<int> bfs(200010);    

void BFS()
{
    queue<int> q;

    int u = 1;
    q.push(u);
    dis[u] = 0;
    visited[u] = 1;

    while( ! q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if( ! visited[v])
            {
                dis[v] = dis[u] + 1;
                q.push(v);
                visited[v] = 1;
            }
        }
    } 
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int x, y, nodes, edges;
    cin >> nodes;       
    edges = nodes - 1;
    
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    for(int i = 1; i <= nodes; i++)
        cin >> bfs[i];

    BFS();
    visited.assign(200010, 0);
    visited[1] = 1;
    nxt[1] = 1;

    int prev = 0, k = 2, last = 0;          // last specifies the last level of traversal among children,   k specifies visit order, nodes are visited in nn decreasing order of k  
    bool flag = 0, node_p;

    for(int i = 1; i <= nodes; i++)
    {
        int u = bfs[i];

        if(dis[u] - prev >= 0)          // dis of current should be same or greater than the previous previous - BFS concept
            prev = dis[u];
        else
        {
            flag = 1;
            break;
        }

        // this condition basically checks if the we are at same level or it has decresed, then the level is saved in "last"
        if(!((nxt[u] - last == 0) || (nxt[u] - last == 1)))             // condition for the preference, either the node at same level can occur next or the child of the last node
        {                                                               // level in the traversal can remain same of decrease
            flag = 1;
            break;
        }
        else
            last = nxt[u];
        

        node_p = 0;                         // we increment k only if some children are found that are unvisited 

        for(auto &v: G[u])
        {
            if( !visited[v])
            {
                nxt[v] = k;                 // this means that next visit will be to one of these childs of u, so k specifies the visit order 
                visited[v] = 1;
                node_p = 1;
            }
        }
        if(node_p == 1)                 // if at least one child is found 
            ++k;                       
    }

    if(flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}