
/*
Numbers 1 2 3 4 . .  .. . .. ..  .. . N are given (N <= 10^9)
k numbers from this sequence is removed  (k <= 10^5)

find the pth_samllest element   
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 1e5+10;
int a[mxN], n, k, p;

int pth_smallest() {
    if(p > n-k) {
        return -1;
    }
    sort(a, a+k);
    int prev_diff = 0;
    int curr_diff = n;
    int ans = p;               

    // take some test cases to understand the algorithm
    // prev diff == curr diff when upperbound is same for two consecutive times 

    while(prev_diff != curr_diff) {                         
        prev_diff = curr_diff;
        curr_diff = (upper_bound(a, a+k, ans) - a);
        // curr_diff = numbers skipped 
        ans = p + curr_diff;
    }
    return ans;
}

void solve() {
    cin >> n >> k >> p;
    for(int i=0; i<k; i++) {
        cin >> a[i];
    }
    cout << pth_smallest() << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
