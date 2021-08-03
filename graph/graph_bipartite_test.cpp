/*
A graph with the cycle of odd length is not a bipartite graph
NOTE: a disconnected graph is bipartite if all the connected 
components are bipartite 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> G[200];
vector<int> col(200, -1);

bool isBipartite(int u, int c) {
    col[u] = c;
    for(auto v: G[u]) {
        if(col[v] == -1) {
            if(isBipartite(v, c ^ 1) == false)
                return false;
        } else if(col[u] == col[v]) {
            return false;
        }
    }
    return true;
}


// BFS

bool isBipartite(vector<vector<int>> g) {
    int n = g.size();
    queue<int> q;
    vector<int> col(n, -1);
    q.push(0);
    int lev = 0;
    
    while (!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int u = q.front(); 
            q.pop();
            col[u] = lev % 2;
            
            for(auto v: g[u]) {
                if (col[v] != -1 && col[u] == col[v]) {
                    return false;
                } else if (col[v] == -1) {
                    q.push(v);
                }
            }
        }
        lev++;
    }
    return true;
}

int n, m;
void graph_input() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

int main() {
    graph_input()
}