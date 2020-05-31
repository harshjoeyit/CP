/*
You have a matrix of size 3*n  and 3 different colours, find number of ways 
to colour matrix such that no two adjacent cell has same colour.
Two cells are adjacent only if they share some vertical or horizontal side.
Print number of ways modulus 1e9+7.
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD = 1e9+7;
const int mxN = 1e5+10;
int dp[mxN][4][4][4];                                        // i, c1 = 1, c2 = 2, c3 = 3
int n;

int count_ways(int ind, int c1, int c2, int c3) {             // prev column and colors of each row
    if(ind == n)
        return 1;
    
    if(dp[ind][c1][c2][c3] != -1)
        return dp[ind][c1][c2][c3];

    int cnt = 0;

    for(int i=1; i<=3; i++) {               
        if(i == c1)  continue;                      // if color same as cell on the left
        for(int j=1; j<=3; j++) {   
            if( j == c2 || j == i)  continue;       // if the color is same as cell on the top(row 1) or cell on the left 
            for(int k=1; k<=3; k++) {   
                if(k == c3 || k == j)  continue;    // if the color is same as cell on the top(row 2) or cell on the left 
                
                cnt += count_ways(ind+1, i, j, k);             // solve for next col for this state
                cnt = cnt%MOD;
            }
        }
    }

    return (dp[ind][c1][c2][c3] = cnt);

}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int ans = count_ways(0, 0, 0, 0);           // color 0 as for first col we can color it with any color without considering colr on left
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}