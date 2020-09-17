
/*
Number of Nodes in the Sub-Tree With the Same Label
https://leetcode.com/contest/weekly-contest-198/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/


learned 

- do not use unordered map or map as return type of DFS function 
- try and use the method below for child processing 
- array further decrease the runtime when used in place of cnt vector 
*/


vector<vector<int>> g;
// label[i] - ['a'], z'
string label;
vector<int> ans;

void dfs(int u, int par, vector<int> &cnt) {
    for (auto v : g[u]) {
        if(v != par) {
            vector<int> temp(26, 0);
            dfs(v, u, temp);
            for (int i = 0; i < 26; i++) {
                cnt[i] += temp[i];
            }
        }
    }
    cnt[label[u] - 'a'] += 1;
    ans[u] = cnt[label[u] - 'a'];
}

int main() {
    int n;
    cin >> n;

    ans.assign(n, 0);
    label.assign(n, 0);
    g.assign(n, vector<int>());

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cin >> label;

    vector<int> cnt(26, 0);
    dfs(0, -1, cnt);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}