
/*
IN range 1-N one element repeats and one is missing find them
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// using index as values 
void method1(int a[], int n) {
    int vis[n+1] = {};
    for(int i=0; i<n; i++) {
        if(vis[a[i]] == 0) {
            vis[a[i]] = -1;
        } else {
            vis[a[i]] = -vis[a[i]];
        }
    }
    int mis, rep;
    for(int i=1; i<=n; i++) {
        if(vis[i] == 1) {
            rep = i;
        } else if(vis[i] == 0) {
            mis = i;
        }
    }
    cout <<"rep: "<< rep << ", mis: " << mis << "\n";
}

void solve() {
    int n;
    cin >> n;       
    int a[n];
    // enter elements in range [1, n]
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    method1(a, n);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}