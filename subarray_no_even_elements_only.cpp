#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 8;
    // NOTE:  Array is 1 indexed
    for(int i=1; i<n; i++) {
        for(int j=i, k=i+1;  j>0 && k<=n;  j--, k++) {
            cout << j << " " << k << "\n";
        }
        cout << "\n";
    }
}