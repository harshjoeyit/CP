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
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
void tree_input() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
int main() {
    
}