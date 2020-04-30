#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    
    int pref[n+1][m+1];
    memset(pref, 0, sizeof(pref));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) { 
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i][j]; 
        }
    }
    
    // to find prefix sum fo a sub-matrix with top-left corner (i, j) and length = s
    // sum = pref[i][j] - pref[i][j+s] - pref[i+s][j] + pref[i+s][j+s];

    // max submatrix sum of size a*b
    
    cin >> q;
    while(q--) {
        cin >> a >> b;
        int ans = 0, sum;

        for(int i=0; i<=n-a; i++) {
            for(int j=0; j<=m-b; j++) {

                sum = prefix[i][j] - prefix[i][j+b] - prefix[i+a][j] + prefix[i+a][j+b];
                ans = max(ans, sum);
                // cout << sum << " ";
            }
        }
        cout << ans << " ";
    } 
    cout << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
