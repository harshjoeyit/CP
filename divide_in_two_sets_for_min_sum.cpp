
/*
choose k elements from array A 
such that the sum defined below is MINIMUM possible 

v1 = { ... } - set1
v2 = {.....} - set2

sum = 0;
for(int i=0; i<v1.size(); i++) {
    for(int j=0; j<v2.size(); j++) {
        sum += abs(v1[i] - v2[j]);
    }
}

Soln:
folow a greedy approach - sorting and choosing middle elements of the array 
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(k, n-k);

    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);

    // range [st, en] - where alternate elements are to be chosen
    int st=(n-1)/2, en=n/2;
    st = st-k+1;
    en = en+k-1;

    vector<int> v1;
    vector<int> v2;

    // choose alternate elements for v1, v2
    bool f = 1;
    for(int i=st; i<=en; i++) {
        if(f) {
            v1.push_back(a[i]);
            f = 0;
        } else {
            v2.push_back(a[i]);
            f = 1;
        }
    }
    // left half remaining in v2
    for(int i=0; i<st; i++)
        v2.push_back(a[i]);

    // right half remaining in v2
    for(int i=en+1; i<n; i++)
        v2.push_back(a[i]);

    // calc sum
    int ans = 0;
    for(int i=0; i<v1.size(); i++) {
        for(int j=0; j<v2.size(); j++) {
            ans += abs(v1[i] - v2[j]);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}