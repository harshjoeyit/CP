#include<bits/stdc++.h>
using namespace std;

/*
    Print all possible paths

    Time Complexity: O(3^(n^2)). 
    As there are N^2 cells from each cell there are 3 unvisited neighbouring cells. So the time complexity O(3^(N^2).
    Auxiliary Space: O(3^(n^2)). 
    As there can be atmost 3^(n^2) cells in the answer so the space complexity is O(3^(n^2))
*/

vector<char> ch = {'D','L','R','U'};
vector<int> dirx = {1,0,0,-1};
vector<int> diry = {0,-1,1,0};

void dfs(int i, int j, int n, vector<vector<int>> &grid, vector<string> &ans, string &path) {
    if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0) {
        return;
    }
    if(i == n-1 && j == n-1) {
        ans.push_back(path);
        return;
    }
    grid[i][j] = 0;

    for(int k=0; k<4; k++) {
        int x = i+dirx[k];
        int y = j+diry[k];
        path.push_back(ch[k]);
        dfs(x, y, n, grid, ans, path);
        path.pop_back();
    }

    grid[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &grid, int n) {
    string path = "";
    vector<string> ans;
    dfs(0, 0, n, grid, ans, path);
    return ans;
}

void ratInaMaze() {
    vector<vector<int>> grid = {
         {1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    auto ans = findPath(grid, 4);
    for(auto val: ans) {
        cout << val << " ";
    }cout << endl;
}

/*
    Find if cheese found by rat
*/

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