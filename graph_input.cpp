#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;
vector<int> g[mxN];

int n, m;
void graph_input() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;          // v = {0, 1, 2, 3, 4....}
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
void tree_input() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int x,y;
        cin >> x >> y;
        --x; --y;        // v = {0, 1, 2, 3, 4....}
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
void graph_disp() {
    for(int u=0; u<n; u++) {
        cout << u << " : ";
        for(auto v: g[u])
            cout << v << " ";
        cout << endl;
    }
}
int main() {
    
}