
/*
given an array of 1s, 0s
given k, make k operations and find longest subarray with only 1s
1 operation - choose i, make a[i] = 0 ---> 1

soln: window sliding - two pointers
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int l=0, r, ans_l=-1, ans_r=-1, mxl=0, z=0;

    for(r=0; r<n; r++) {
        if(a[r] == 0) {                 
            ++z;
        }
        if(z <= k) {                        // finding a window with k or less zeroes 
            if(r-l+1 > mxl) {
                ans_l = l;
                ans_r = r;
                mxl = r-l+1;
            }
        }
        if(z > k) {                         // is zeroes > k move left poninter 
            --z;
            while(a[l] != 0) {
                ++l;
            }
            ++l;
        }
        // cout << l << " " << r << endl;
    }
    
    cout << mxl << endl;
    for(int i=ans_l; i<=ans_r; i++) {
        a[i] = 1;
    }
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
