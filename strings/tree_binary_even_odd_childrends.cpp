#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1e5+10, M = 1e9+7;
int h;
int evn[mxN];               // even[i] - no nodes at even distance from this node
int odd[mxN];               //  odd[i] - no of nodes at odd distance from this node

void solve() {
    cin >> h;
    odd[h] = 0;
    evn[h] = 1;

    for(int i=h-1; i>=0; i--) {
        odd[i] = (2 * evn[i+1]) % M;
	    evn[i] = (1 + 2 * odd[i+1]) % M;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}