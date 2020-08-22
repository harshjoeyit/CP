#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000];
vector<bool> vis(1000, false);
int c = 0;

void print_path(vector<int> &v) {
    for(auto &x: v) {
        cout << x << " ";
    }
    cout << endl;
}

void count_path(int s, int d, vector<int> &path, int k) {
    vis[s] = true;
    path.push_back(s);

    if(s == d) {
        print_path(path);
        ++c;
        return;
    }
    for(auto &v: G[s]) {
        if(!vis[v]) {
            count_path(v, d, path, k+1);
        }
    }

    path.pop_back();
    vis[s] = false;
}   

int main() {    
    int x, y, n, m;
    cin >> n;     
    cin >> m;      

    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        G[x].push_back(y);        
        G[y].push_back(x);        
    }

    // source and destination 
    cin >> x >> y;

    vector<int> path;
    count_path(x, y, path, 0);
    cout << "total paths: " << c << endl;

}