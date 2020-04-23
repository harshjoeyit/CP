#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n, q;
bitset<8000005> can;
int a[4005];
string ans = "";

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) 
        cin >> a[i];
    
    can[0] = 1;
    for(int i=0; i<n; i++) 
        can = can | (can << a[i]);      // setting all the bits that are possible sum
    
    cin >> q;

    while(q--) {
        int s;
        cin >> s;
        if(s == 0) ans += '0';
        else if(can[s])
            ans += '1';
        else 
            ans += '0';
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}