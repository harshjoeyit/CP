/*
Like Kruskal’s algorithm, Prim’s algorithm is also a Greedy algorithm. 
It starts with an empty spanning tree. The idea is to maintain two sets 
of vertices. The first set contains the vertices already included in the
MST, the other set contains the vertices not yet included. At every step, 
it considers all the edges that connect the two sets, and picks the 
minimum weight edge from these edges. After picking the edge, it moves 
the other endpoint of the edge to the set containing MST. 
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int mxN = 1e4 + 5;
vector <PII> G[mxN];
bool marked[mxN];

// O(VlogV + ElogV) = O(ElogV) using binary heaps, making it the same as Kruskal's algorithm.
// However, Prim's algorithm can be improved using Fibonacci Heaps to O(E + logV
int prim(int u) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;                  
    pq.push(make_pair(0, u));
    int minCost = 0;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        u = p.second;
    
        // this method should be followed while marking the vertices 
        if(marked[u] == true) {
            continue;
        }
        marked[u] = true;
        minCost += p.first;
        
        for(auto pr: G[u]) {
            if(!marked[pr.second]) {
                pq.push(pr);
            }
        }
    }
    return minCost;
}

int main() {
    int n, e, x, y, w;
    cin >> n >> e;
    for(int i = 0; i < e; ++i) {
        cin >> x >> y >> w;
        G[x].push_back(make_pair(w, y));
        G[y].push_back(make_pair(w, x));
    }

    // Selecting 1 as the starting node
    auto minCost = prim(1);                              
    cout << minCost << endl;
    return 0;
}