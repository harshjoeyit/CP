#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
    int n;
    cin >> n;

    int xr = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int indices[n+1];
    for(int i=1; i<= n; i++)            // set all indices to 1
        indices[i] = 1;

    int rep;
    for(int i=0; i<n; i++) {            // if element is found set index = -1
        if(indices[a[i]] == 1)
            indices[a[i]] = -1;
        else                           // if -1 index is found - means repeated value
            rep = a[i];   
    }

    int mis;
    for(int i=1; i<=n; i++) {          // positive index found - means value never occurs in the array 
        if(indices[i] == 1) {
            mis = i;
            break;
        }
    }

    cout << rep << " " << mis << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}