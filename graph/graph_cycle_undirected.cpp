#include<bits/stdc++.h>
using namespace std;

vector<int> vis(1000);
vector<int> G[1000];
vector<int> parent(1000);
vector<pair<int, int>> Edges;

// using DSU
 
int root(int a) {
    while(a != parent[a]) {
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}

void Union(int a, int b) {
    int a = root(a);
    int b = root(b);

    if(a == b)
        return;

    if(a < b)
        parent[a] = b;
    else
        parent[b] = a;
}

bool find_cycle_dsu() {
    for(int i = 0; i < Edges.size(); i++) {
        int a = Edges[i].first;
        int b = Edges[i].second;

        if(root(a) == root(b))
            return true;
        else
            Union(a, b);
    }
    return false;
}


// using DSF

bool dfs(vector<int> g[], int u=0, int par=-1) {
    vis[u] = true;

    for(auto v: g[u]) {
        if(!vis[v]) {
            if(dfs(g, v, u)) {  // cycle int the subtree
                return true;
            }
        } else if(v != par) {
            return true;
        }
        // we can also check self loop seperately
    }

    return false;
}


// Using BFS

bool bfs(vector<int> g[], int u) {
    // check for self loop seperately
    vector<int> parent(1000, -1);
    vector<int> vis(1000, 0);
    queue<int> q;
    q.push(u);
    vis[u] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v: g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                parent[v] = u;
            } else if (parent[u] != v) {
                return true;
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

    // using DSU
    for(int i = 1; i <= nodes; i++) {  
        parent[i] = i;
    }

    if(find_cycle_dsu())
        cout << "cycle" << endl;
    else
        cout << "no cycle" << endl;

    
    // using DFS
    int i;
    for(i=0; i<nodes; i++) {
        if(!vis[i]) {
            if(dfs(G, i, -1)) {
                cout << "cycle\n";
                break;
            } 
        }
    }
    if(i == nodes) {
        cout << "No cycle\n";
    }
}