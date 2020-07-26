#include<bits/stdc++.h>
using namespace std;

vector<int> vis(1000);
vector<int> G[1000];
vector<int> prev(1000);
vector<int> Arr(1000);
vector<pair<int, int>> Edges;

/*
Logic - simple dfs - if a visited vertex is found again and 
it is not a parent then there is a cycle, 
a recursive function can be easily implemented  
*/

/*
Copy and paste part

int vis[1005];
int prev[1005];

bool check(vector<int> g[], int u) {
    stack<int> s;
    s.push(u);
    vis[u] = 1;

    while(!s.empty()) {
        u = s.top();
        s.pop();
        
        for(auto v: g[u]) {
            
            if(vis[v] == 1 && v != prev[u]) {
                return true;
            }

            if(vis[v] != 1) {
                s.push(v);
                vis[v] = 1;
                prev[v] = u;
            }
        }

    }
    return false;
}

bool isCyclic(vector<int> g[], int n) {
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++) {
        prev[i] = i;
    }

    // for self loops 

    for(int i=0; i<n; i++) {                
        for(auto v: g[i]) {
            if(v == i) {
                return 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(! vis[i]) {
            if(check(g, i)) {
                return 1;
            }
        }
    }
    
    return 0;
}

*/

int root(int a)
{
    while(a != Arr[a])
    {
        Arr[a] = Arr[Arr[a]];
        a = Arr[a];
    }
    return a;
}


void Union(int a, int b)
{
    int r_a = root(a);
    int r_b = root(b);

    if(r_a == r_b)
        return;

    if(r_a < r_b)
        Arr[r_a] = r_b;
    else
        Arr[r_b] = r_a;
}


bool Find(int a, int b)
{
    return (root(a) == root(b));
}


bool find_cycle_dsu()
{
    for(int i = 0; i < Edges.size(); i++)
    {
        int a = Edges[i].first;
        int b = Edges[i].second;

        if(Find(a, b))
            return true;
        else
            Union(a, b);
    }
    return false;
}

// DFS using a stack 
bool find_cycle(int u) {   
    stack<int> s;
    s.push(u);
    vis[u] = 1;

    while(! s.empty()) {
        u = s.top();
        s.pop();
        for(auto v: G[u]) {
            // if a vis node is found then it shuld not be the parent or prev node that came earlier in dfs
            if(vis[v] == 1 && v != prev[u])         
                return true;

            if(vis[v] != 1) {
                s.push(v);
                vis[v] = 1;
                prev[v] = u;
            }
        }

    }
    return false;
}



int main() {
    int x, y, nodes, edges;
    cin >> nodes;       
    cin >> edges;      

    // Undirected Graph
    for(int i = 0;i < edges;++i) {
        cin >> x >> y;
        G[x].push_back(y);        
        G[y].push_back(x);       
        Edges.push_back(make_pair(x, y)); 
    }

    for(int i = 1; i <= nodes; i++) {
        prev[i] = i;    
        Arr[i] = i;
    }

    int i;
    bool flag = 0;
    vis.assign(1000, 0);
    for(i = 1; i <= nodes; i++) {
        if(! vis[i]) {
            if(find_cycle(i)) {
                flag = 1;
                break;
            }
            cout << endl;
        }
    }

    if(flag)
        cout << "cycle" << endl;
    else
        cout << "no cycle" << endl;


    if(find_cycle_dsu())
        cout << "cycle" << endl;
    else
        cout << "no cycle" << endl;

    return 0;
}