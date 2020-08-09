#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pii pair<int, int>
const int mxN = 1e5+10;

int id[mxN], n, e;
pair <int, pii> edges[mxN];

void initialize() {
    for(int i=0; i<mxN; ++i) {
        id[i] = i;
    }
}
int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
int kruskal() {
    int x, y, cost, minCost = 0;
    
    for(int i = 0; i < e; ++i) {
        x = edges[i].second.first;
        y = edges[i].second.second;
        cost = edges[i].first;

        if(root(x) != root(y)) {
            minCost += cost;
            union1(x, y);
            // mst.push_back({cost, x, y});  - if we want to see what edges are in MST 
        }    
    }
    return minCost;
}


signed main() {
    int x, y, wt, cost, minCost;
    initialize();
    cin >> n >> e;

    for(int i = 0; i < e; ++i) {
        cin >> x >> y >> wt;
        edges[i] = make_pair(wt, make_pair(x, y));
    }

    // Sort the edges in the ascending order
    sort(edges, edges + e);
    minCost = kruskal();
    cout << minCost << endl;

}