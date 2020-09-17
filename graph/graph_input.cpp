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