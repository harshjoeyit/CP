#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> vis;
vector<vector<int>> ans;
bool reached = false;

void dfs(int i, int j) {
    if(i >=n || j >= m || grid[i][j] == 0) {
        return;
    }

    vis[i][j] = 1;
    
    if(i == n-1 && j == m-1) {
        reached = true;
        ans = vis;
        return;
    }

    dfs(i + 1, j);
    dfs(i, j + 1);

    vis[i][j] = 0;
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m, 0));
    ans = vis = grid;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    reached = false;
    dfs(0, 0);

    if(reached) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "could not reach\n";
    }
}