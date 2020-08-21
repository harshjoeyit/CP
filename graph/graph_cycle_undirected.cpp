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

bool dfs(vector<int> g[], int u, int par) {
    vis[u] = true;

    for(auto v: g[u]) {
        if(!vis[v]) {
            if(dfs(g, v, u)) {
                // cycle int the subtree
                return true;
            
            } else if(v != par || v == u) {
                // if the visited is not parent or 
                // self loop
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
            if(dfs(g, i, -1)) {
                cout << "cycle\n";
                break;
            } 
        }
    }

    if(i == nodes) {
        cout << "No cycle\n";
    }
}