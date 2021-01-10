
/*
start point 0, 0
end point   n, m

constraint - cannot move more than 2 steps in the same direction
find total ways to reach end
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2][3];
int n, m;

int go(int i, int j, int dir, int steps) {
    if(i > n || j > m || steps > 2) {
        return 0;
    }
    if(i == n && j == m) {
        return 1;
    }

    int &ans = dp[i][j][dir][steps];
    if(ans != -1) {
        return ans;
    }
    ans = 0;

    if(dir == 0) {
        // was going right
        ans += go(i + 1, j, 0, steps + 1);  // continue right
        ans += go(i, j + 1, 1, 1);          // turn, go down
    } else {
        // was going down
        ans += go(i + 1, j, 0, 1);          // turn, go right
        ans += go(i, j + 1, 1, steps + 1);  // continue down
    }

    return ans;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0, 0) << "\n";
}
