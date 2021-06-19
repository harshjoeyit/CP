/*
    Print all possible paths from source (s) to destitnation (d)

    Time Complexity:
    For each function call we can make at most n-1 recursive calls
    T(n) = (n-1)*T(n-1)
    T(n) = O(n!) 

    Similar problem:
    https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/
    https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

    Solution: Use backtracking, like used here
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000];
vector<bool> vis(1000, false);
int c = 0;

void print_path(vector<int> &v);

void count_path(int s, int d, vector<int> &path, int k) {
    vis[s] = true;
    path.push_back(s);

    if(s == d) {
        ++c;
        print_path(path);
    } 
    else {
        for(auto &v: G[s]) {
            if(!vis[v]) {
                count_path(v, d, path, k+1);
            }
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
    cout << "paths: \n";
    count_path(x, y, path, 0);
    cout << "total paths: " << c << endl;
}
/*
Test Input:
5 7
0 1
0 2
0 3
0 4
1 4
2 3
1 2
0 2

Output: 
paths: 
0 1 2 
0 2 
0 3 2 
0 4 1 2 
total paths: 4
*/

void print_path(vector<int> &v) {
    for(auto &x: v) {
        cout << x << " ";
    }
    cout << endl;
}