#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n;
    cin >> n;
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
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i][j]; 
        }
    }
    
    // to find prefix sum fo a sub-matrix with top-left corner (i, j) and length = s
    // sum = pref[i][j] - pref[i][j+s] - pref[i+s][j] + pref[i+s][j+s];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
