
// https://www.hackerrank.com/contests/pir4/challenges/prefix-problem
// kth largest number for all prefixes of array with size >= k

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
    int n, k, kth_largest = 1e17;
    cin >> n >> k;
    int a[n+1];
    
    set<int> s;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i <= k)
            s.insert(a[i]);
    }
    
    cout << *(s.begin()) << " ";
    
    for(int i=k+1; i<=n; i++) {
        int t = *(s.begin());
        if(a[i] > t) {
            s.erase(t);
            s.insert(a[i]);
        } 
        cout << *(s.begin()) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
}