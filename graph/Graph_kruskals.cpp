#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pii pair<int, int>
const int mxN = 1e5+10;

int id[mxN], n, e;
vector<int> edges[mxN];

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
    int mstWt = 0;
    
    for(int i = 0; i < e; ++i) {
        int x = edges[i][1], y = edges[i][2];
        int cost = edges[i][0];

        if(root(x) != root(y)) {
            mstWt += cost;
            union1(x, y);
            // mst.push_back({cost, x, y});  - if we want to see what edges are in MST 
        }    
    }
    return mstWt;
}


signed main() {
    int x, y, wt, cost;
    initialize();
    cin >> n >> e;

    for(int i = 0; i < e; ++i) {
        cin >> x >> y >> wt;
        edges[i] = {wt, x, y};
    }

    // Sort the edges in the ascending order
    sort(edges, edges + e);
    cout << kruskal() << endl;

}