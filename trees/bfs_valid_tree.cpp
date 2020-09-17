

#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> g;
vector<int> given;
vector<int> order;
vector<int> bfsOrder;

// finding the bfs from the reordered adjacency list 
void bfs() {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
            int u = q.front();
            q.pop();

            vis[u] = true;
            bfsOrder.push_back(u);

            for(auto v: g[u]) {
                if(!vis[v]) {
                    q.push(v);
                }
            }
    }
}

void solve() {
    cin >> n;
    g.assign(n, vector<int>());
    given.assign(n, 0);
    order.assign(n, 0);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> given[i];
        --given[i];
        // storing the order in which the nodes occur 
        order[given[i]] = i;
    }

    auto comp = [](const int &a, const int &b) {
        return order[a] < order[b];
    };

    for (int i = 0; i < n; i++) {
        // sorting in the order they occur in the given travesal
        sort(g[i].begin(), g[i].end(), comp);
    }

    bfs();
    // compare the input and calculated order 
    for (int i = 0; i < n; i++) {
        if(bfsOrder[i] != given[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    solve();
}   