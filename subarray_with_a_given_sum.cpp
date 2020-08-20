#include <bits/stdc++.h>
using namespace std;

/*
O(n) space method 
Use a map to store the prefix sums and 
check, just like when we do counting of subarrays with a sum
*/


/*
O(1) Space method 
Use Two pointers 
*/

const int mxN = 1e6+2; 
int a[mxN], n, s, st, en;

// for non-neg values only
// for neg values use count subarrays option

void solve() {
    cin >> n >> s;
    st = 0, en = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i > 1) {
            // a[i] stores sum a[0...i]
            a[i] += a[i-1];
        }
        if(a[i] >= s && en == 0) {
            en = i;
        }
    }
    
    bool f = 0;
    while(en <= n) {
        if(a[en] - a[st] == s) {
            // subarray from st+1, en has sum = s
            f = 1;
            break;
        } else if(a[en] - a[st] > s) {
            // decrease the window
            ++st;
        } else if(a[en] - a[st] < s) {
            // increase the window
            ++en;
        }
    }   
    if(f == 1) {
        cout << st+1 << " " << en << "\n";                // print range where the sum is found - 1 indexed  
    } else {
        cout << -1 << "\n";
    }
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) 
	    solve();
	
	return 0;
}