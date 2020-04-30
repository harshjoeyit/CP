#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    map<int, int> mp;
    mp[3] = 4;
    mp[1] = 3;
    mp[5]  = 10;
    mp[2] = 12;

    for(auto it = mp.rbegin(); it != mp.rend(); it++) 
        cout << it->first << " " << it->second << endl;
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}