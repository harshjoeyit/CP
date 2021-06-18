#include<bits/stdc++.h>
using namespace std;

/*
using DFS, and keeping visited vertex in the stack 
we need to keep the recusive stack because 

consider the case 
(c1) ------->  (v) <-------- (c2)
c1 and c2 are cconnected components without cycles 
suppose dfs makes c1 & v visited 
now second dfs from c2 when visits the vertex v, we cannot declare a cycle 

just as we did it in undirected graph
we need to keep track of those vitsited in the same dfs 
this can be done using a recStack array or an unordered_set 
*/

vector<int> G[100005];
int recStack[100005];
int vis[100005];
int n, m;

bool isCycle(int u) {
    vis[u] = true;
    recStack[u] = true;
    // add to recstack 

    for(auto v: G[u]) {
        if( !vis[v] && isCycle(v)) {
            return true;
        }
        else if(recStack[v]) {
            return true;
        }
    }   

    // remove, backtracking 
    recStack[u] = false;
    return false;
}

// if the directed graph is not connected then there are components
bool find_cycle() {
    for(int i = 1; i <= n; i++)
        if(!vis[i]) {
            if(isCycle(i)) {
                return true;
            }
        }
    return false;
}


/*
BFS topological sort 

if the topological sort algo works fine, then all the vertices will be covered in the end
it will happen when there is no cycle, 
if cycle exist , some vertices remian unvisited
*/

bool isCycle(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n, vector<int>());
    int indegree[n] = {};
    
    for (auto e : edges) {
        g[e[0]].push_back(e[1]);
        indegree[e[1]] += 1;
    }
    
    queue<int> q; 
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cnt += 1;
        for(auto v: g[u]) {
            indegree[v] -= 1;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    return cnt != n;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    cout << find_cycle() << endl;
}