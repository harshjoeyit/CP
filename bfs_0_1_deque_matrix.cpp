

// https://www.hackerrank.com/contests/pir4/challenges/a-walk-to-remember-2/problem

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

signed main() {
    
    cin >> n >> m;
   
    vector<string> v(n);
    string a;
    for(int i=0; i<n; i++) {
        cin >> a;
        v[i] = a;
    }
    
    deque<pair<int,int> > dq;
    int cost[n+1][m+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) cost[i][j] = 2e9;
    }
    
    cost[0][0] = 0;
    dq.push_back({0, 0});
    while(!dq.empty()) {
        auto it = dq.front(); dq.pop_front();
        int x = it.first, y = it.second;
        if(x == n-1 && y == m-1) {
            cout << cost[x][y] << '\n';
            return 0;
        }
        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(cost[nx][ny] > cost[x][y] + (k+1 != (v[x][y] - '0'))) {
                cost[nx][ny] = cost[x][y] + (k+1 != (v[x][y] - '0'));
                if((k+1 == (v[x][y] - '0'))) {
                    dq.push_front({nx, ny});
                }
                else dq.push_back({nx, ny});
            }
        }
    }
    
    return 0;
}