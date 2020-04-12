
// finding smallest size square sub-matrix of sum >= k
// https://www.hackerrank.com/contests/pir3/challenges/smallest-square-1

#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n+1][n+1];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    
    int pref[n+1][n+1];
    memset(pref, 0, sizeof(pref));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) { 
            pref[i][j] = pref[i-1][j] 
                            + pref[i][j-1] 
                            - pref[i-1][j-1] 
                            + a[i][j]; 
        }
    }
    
    // to find prefix sum fo a sub-matrix with top-left corner (i, j) and length = s
    // sum = pref[i][j] - pref[i][j+s] - pref[i+s][j] + pref[i+s][j+s];

    int low = 1;
    int high = n;
    int ans = -1;

    while(low <= high) {
        int mid = (low+high)/2;                 // current size(side) of the square  
        bool f = false;

        for(int i=1; i<=n-mid+1; i++) {
            for(int j=1; j<=n-mid+1; j++) {
                int top_left_rowx = i;
                int top_left_colx = j;
                int bot_right_rowx = i+mid-1;
                int bot_right_colx = j+mid-1;

                if( pref[bot_right_rowx][bot_right_colx]
                    - pref[top_left_rowx - 1][bot_right_colx]
                    - pref[bot_right_rowx][top_left_colx - 1]
                    + pref[top_left_rowx - 1][top_left_colx - 1] 
                    >= k) {
                    f = true;
                }
            }
        }

        if(f) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
