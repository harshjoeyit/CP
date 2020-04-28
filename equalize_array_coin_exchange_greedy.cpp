
/*
Equalize array values - Application of Coin Exchange Problem(Greedy)

Rules -
Array values can be incresed by 1, 2, 5 
At a time more than one element must be incremented by the number chosen
All elements can not be incremented at the same time 

Approach  - we calculate steps to reduce all the values to the (min) 
but sometimes this may be incorrect 
so we check for min-1, m-2, m-3, m-4, 
but min-5 will always require 1 more step 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e5+10; 
int n, a[mxN];

// returns minimum steps to reach a value by reducing it greedily
int steps(int val) {
    // possible reduction values 1, 2, 5
    int s=0;
    s += val/5, val %= 5;
    s += val/2, val %= 2;
    s += val;

    return s;
}

int equal() {
    int minn = *min_element(a, a+n);
    int ans = 1e9;

    for(int t=minn-4; t <= minn; t++) {
        int s = 0;
        for(int i=0; i<n; i++) {
            s += steps(a[i] - t);
        }
        ans = min(ans, s);
    }
    return ans;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << equal() << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}