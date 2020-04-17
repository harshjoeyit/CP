#include<bits/stdc++.h>
using namespace std;

#define int long long 

bool solve() {
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, bool> mp;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]*a[i]] = true;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int val = a[i]*a[i] + a[j]*a[j];
            if(mp.count(val))
                return 1;
        }
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        cout << ((solve() == 1)? "Yes":"No") <<"\n";
}