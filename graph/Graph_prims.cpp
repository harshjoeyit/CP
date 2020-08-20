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