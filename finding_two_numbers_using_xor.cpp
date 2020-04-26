
/*
You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs 
whereas the other two number occur exactly once and are distinct.
You need to find the other two numbers and print them in ascending order.

Realted problem : 
Given an unsorted array of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing 
and one number 'B' occurs twice in array. Find these two numbers.

make the final array = {a[0],.... a[n-1], 1, 2, 3, 4.... N};
proceed similarly
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 2e6+10;
int a[mxN], n;

void solve() {
    cin >> n;
    int xr = 0;
    for(int i=0; i<2*n+2; i++) {
        cin >> a[i];
        xr = xr ^ a[i];
    }
    // xr  = x ^ y  as all pairs cancel cout 
    // we need to find x, y 

    int b = 1;                              // finding the rightmost set - bit in xr - NOTE : this bit must be set in one of x, y
    for(int j=0; j<64; j++) {
        if((b & xr) > 0) {
            break;
        } else {
            b = b << 1;
        }
    }
    cout << b << "\n";
    int xr2 = 0;
    for(int i=0; i<2*n+2; i++) {
        if((b & a[i]) > 0) {                
            xr2 = xr2 ^ a[i];               // finding all the numbers whose rightmost bit is set as in xr  - again pairs will cancel and (x or y remains)
            cout << a[i] << " ";
        }
    }
    cout << "\n";
    int x = xr ^ xr2;                       // find x, y
    int y = x ^ xr;
    cout << min(x, y) << " " << max(x, y) << "\n"; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}