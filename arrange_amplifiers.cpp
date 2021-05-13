/*
    https://www.spoj.com/problems/ARRANGE/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    int ones = 0;
    for(int i=0, x; i<n; i++) {
        cin >> x;
        if(x == 1) {
            ones++;
        } else {
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    
    while(ones--) {
        cout << "1 ";
    }
    if(a.size() == 2 && a[0] == 2 && a[1] == 3) {
        cout << "2 3\n";
    } else {
        for(int i=a.size()-1; i>=0; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}